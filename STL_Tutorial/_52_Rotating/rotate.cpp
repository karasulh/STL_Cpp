#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main(){

    vector<int> i {0,1,2,3,4,5,6,7};

    for_each(begin(i),end(i),[](const auto& i){cout<<i<<" ";});
    cout<<"\n";

    //left rotate 2 times
    rotate(begin(i),begin(i)+2,end(i)); //begin+2 => new first 

    for_each(begin(i),end(i),[](const auto& s){cout<<s<<" ";});
    cout<<"\n";

    //reverse rotate:right rotate 5 times 
    rotate_copy(rbegin(i),rbegin(i)+5,rend(i),ostream_iterator<int>(cout," ")); //rbegin+5 => new rFirst
    cout<<"\n";

    return 0;
}