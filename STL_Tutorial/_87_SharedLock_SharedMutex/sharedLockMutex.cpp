#include <thread>
#include <shared_mutex>
#include <mutex>
#include <chrono>
#include <iostream>

using namespace std;

struct DataSource{

private:
    shared_mutex mut;
    int value=0;
public:
    DataSource() = default;
    
    int get(){
        shared_lock lock(mut);
        cout<<"Getting value: "<<value<<"\n";
        return value;
    }
    
    void set(int v){
        unique_lock lock(mut); //only one thread, releases lock at the end of block
        cout<<"Setting value to: "<<v<<"\n";
        value=v;
    }
};

void readWorker(DataSource& ds){
    while(true){
        ds.get();
        this_thread::sleep_for(500ms);
    }
}

void writeWorker(DataSource& ds){
    while(true){
        int val = ds.get();
        ds.set(val+1);
        this_thread::sleep_for(2s);
    }
}

int main(){
    
    DataSource d;
    thread writeThread(&writeWorker,std::ref(d));

    for(int i=0; i<50 ; i++){
        thread r(&readWorker,std::ref(d));
        r.detach(); //it means: run thread at background, not care what it is doing.
                    //due to this, we lose reference to them, so we can not use join().
    }

    writeThread.join(); //wait writeThread to finish main thread
    
    return 0;
}