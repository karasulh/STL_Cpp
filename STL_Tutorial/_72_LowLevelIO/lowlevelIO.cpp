#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream fs("input.txt");
    string text;

    if(fs){
        char c=fs.peek();//not extract the character from stream
        cout<<"Peeked and saw a "<<c<< " as the first character\n";
        
        fs.seekg(0,ios_base::end); // go to end of input stream

        int size=fs.tellg(); //take the position the end character of stream
        cout<<size<<" characters in stream\n";

        text.resize(size);

        fs.seekg(0,ios_base::beg);//go to beginning of stream
        
        fs.read(text.data(),size); //read stream into text
        cout<<"Read in: "<<text;

        fs.close();
    }
    else{
        cerr<<"Unable to open file for reading, exiting...\n";
        return 1;
    }

    ofstream out("output.txt");

    if(out){
        for_each(begin(text),end(text),[&out](char c){
            out.put(c); //write char to out stream
        });
    }
    else{
        cerr<<"Unable to open file for writing, exiting\n";
        return 2;
    }

    out.close();//important as this will flush the buffers out


    return 0;
}