//This project is used to find duplicated files in specified directory. 
//It finds duplication via hash256 algorithm with multiple threads.

#include <iostream>
#include <thread>
#include <iterator>
#include <condition_variable>
#include <mutex>
#include <future>
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <atomic>

#include "picosha2.hpp"

using namespace std;

struct WorkController{
    mutex m;
    condition_variable workReadyCV;
    queue<filesystem::path> workQueue;
    unordered_map<string, vector<string>> fileHashes; //hash string and vector for filenames
    atomic<bool> quit{false};

    WorkController() = default;
    WorkController(const WorkController&) = delete; //not allow copy constructor with "delete"
    WorkController& operator=(const WorkController&) = delete; //not allow assignment with "delete"
};

string fileHash(const filesystem::path& path){
    ifstream file(path, ios::binary);
    vector<unsigned char> hash(picosha2::k_digest_size); //to store the hash result

    picosha2::hash256(file,begin(hash),end(hash)); //hash the file
    return picosha2::bytes_to_hex_string(hash.begin(),hash.end());//hash result in hex -> string
}

void matchProcessor(WorkController& wc){
    while(true){
        filesystem::path fileToHash;

        {
            unique_lock lock(wc.m);
            if(wc.quit && wc.workQueue.empty()){
                break;
            }
            else if(wc.workQueue.empty()){
                cout<<"("<<this_thread::get_id()<<") No work, waiting for files to scan\n";
                wc.workReadyCV.wait(lock,[&wc]{return !wc.workQueue.empty();});
            }

            fileToHash = wc.workQueue.front();
            cout<<"("<<this_thread::get_id()<<") Hashing file: "<<fileToHash<<"\n";
            wc.workQueue.pop();
        }

        string hash = fileHash(fileToHash);

        {
            unique_lock(wc.m);
            if(wc.fileHashes.find(hash) != wc.fileHashes.end()){ //if there are more files has the same hash 
                wc.fileHashes.at(hash).push_back(fileToHash.string()); //add it to vector in the map
            }
            else{//if it is the first time for this hash, add it to map 
                vector<string> v{fileToHash.string()};
                wc.fileHashes.insert({hash,v});
            }
        }
    }
}

void printDuplicates(const WorkController& wc){
    for_each(begin(wc.fileHashes),end(wc.fileHashes),[](const auto& p){
        const vector<string>& v = p.second;
        if(v.size()>1){
            cout<<"Duplicate found: \n";
            for_each(begin(v),end(v),[](const string& s){
                cout<<"\t"<<s<<"\n";
            });
        }
    });
}


int main(int argc,char* argv[]){

    if(argc<2){
        cerr<<"Please provide a path to search\n";
        return 1;
    }

    filesystem::directory_entry startingDir(argv[1]);
    if(!startingDir.is_directory()){
        cerr<<"You must specify a directory to start from\n";
        return 2;
    }

    WorkController wc;
    queue<filesystem::directory_entry> directories;
    directories.push(startingDir);

    vector<thread> threads;

    for(unsigned int i=0; i<thread::hardware_concurrency();++i){
        thread t(&matchProcessor,std::ref(wc));
        threads.push_back(std::move(t));
    }

    while(!directories.empty()){
        filesystem::directory_entry dir = directories.front();
        directories.pop();

        for(auto& d : filesystem::directory_iterator(dir)){
            if(d.is_regular_file())
            {      
                {
                    unique_lock lock(wc.m);
                    wc.workQueue.push(d.path());
                    cout<<"pushing"<<d.path().string()<<"\n";
                }
                wc.workReadyCV.notify_all();
            }
            

            else if(d.is_directory()){
                directories.push(d);
            }
            else{
                continue;
            }
        }
    }

    wc.quit.store(true);

    for_each(begin(threads),end(threads),[](thread& t){t.join();});

    cout<<"Hashed "<<wc.fileHashes.size()<<" unique files\n";
    printDuplicates(wc);

    return 0;
}