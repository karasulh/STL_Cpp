#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(){

    vector<int> numbers{1,2,3,4,5};

    //Note that numbers.end() points to 1 past the end element,and
    //that we use ++it because it++ is the same as:
    //temp a=it; ++it; return a;
    //So, it is redundant here because
    //We can obtain the same functionality with 1 line instead of 3 lines.
    for(auto it=numbers.begin(); it!=numbers.end(); ++it){
        *it*=10;
    }

    //prev means previous, it shows the 1 previous element of pointed element.
    //In this case, it shows the last element of vector: 
    for(auto it=std::prev(numbers.end()); it>=numbers.begin(); --it){
        *it-=5;
    }
    for(int i:numbers){
        cout<<i<<" ";
    }
    cout<<"\n";

    return 0;
}