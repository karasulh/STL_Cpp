#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "circular_buffer.hpp"

using namespace std;

int main(){
    CircularBuffer<int,7> buffer;
    cout<<"Buffer size: "<< buffer.size()<<"\n";

    auto bufInsert = back_insert_iterator<CircularBuffer<int,7>>(buffer);
    //back_insert_iterator<CircularBuffer<int,7>> bufInsert(buffer); //The same with above

    for(int i=0;i<13;i++){
        *bufInsert = i*10;
    }
    cout<<"Buffer size now: " <<buffer.size()<<"\n";

    //copy(buffer.begin(),buffer.end(),ostream_iterator<int>(cout," "));
    copy(begin(buffer),end(buffer),ostream_iterator<int>(cout," "));//The same with above
    cout<<endl;

    while(!buffer.empty()){
        cout<<"popping: "<< buffer.head()<<"\n";
        buffer.pop();
    }
    return 0;
}