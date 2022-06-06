#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main(){
    ifstream in("illiad.txt");
    set<string> words;
    string word="";

    unsigned long long totalCount=0;

    while(!in.eof()){
        in>>word;
        totalCount++;
        words.insert(word);
    }
    cout<<"Text contains"<<words.size()<<" unique words out of "<<totalCount<<endl;
    return 0;
}