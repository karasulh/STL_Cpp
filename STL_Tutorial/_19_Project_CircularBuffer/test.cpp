#include <iostream>
#include "circular_buffer.hpp"

using namespace std;

int main(){

    CircularBuffer<int,10> buf;

    for(int i=0;i<13;i++){
        buf.push_back(i);
    }
    while(! buf.empty() ){
        cout<<"popping "<<buf.head() <<"\n";
        buf.pop();
    }

    return 0;
}