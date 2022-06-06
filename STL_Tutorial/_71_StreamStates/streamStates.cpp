#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream fs("input.txt");

    if(fs){ // if(fs.good()){ //the same
        cout<<"ifstream is in good state\n";
        //keep reading while state is good
        int count=0;
        while(fs.good()) {
            string line;
            fs>>line;
            if(line.size()>0){
                ++count;
            }
        }
        cout<<"Read "<<count << " words\n";
    }
    
    if(fs.bad()){
        cout<<"fstream is in bad state\n";
    }
    if(fs.fail()){
        cout<<"fstream is in fail state\n";
    }
    if(fs.eof()){
        cout<<"fstream is in eof state\n";
    }

    cout<<std::showbase<<std::hex<<(int)fs.rdstate()<<"\n";
    
    fs.setstate(ios::eofbit);

    cout<<std::showbase<<std::hex<<(int)fs.rdstate()<<"\n";


    return 0;
}