#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main(){

    vector<int> v{0,1,2,3,4,5,6,7,8,9,10};
    vector<int> v_copy;
    
    // vector<int> v_copy(11);
    // copy(begin(v),end(v),v_copy.begin());

    //if we didnot initialize v_copy with the same size of v, we must use "back_inserter" to copy.
    //it v_copy is initialized, no need to use back_inserter.
    copy(begin(v),end(v),back_inserter(v_copy));

    copy(begin(v_copy),end(v_copy),ostream_iterator<int>(cout," "));
    cout<<"\n"; //0,1,2,3,4,5,6,7,8,9,10

    v_copy.clear();

    //copy_if can be used with lambda function
    copy_if(begin(v),end(v),back_inserter(v_copy),[](int i){return i%3==0;});

    copy(begin(v_copy),end(v_copy),ostream_iterator<int>(cout," "));
    cout<<"\n"; //0,3,6,9

    auto it=begin(v);
    advance(it,3);
    copy_n(it,5,back_inserter(v_copy));

    copy(begin(v_copy),end(v_copy),ostream_iterator<int>(cout," "));
    cout<<"\n"; //0,3,6,9,3,4,5,6,7

    return 0;
}