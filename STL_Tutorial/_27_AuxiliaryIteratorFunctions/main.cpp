#include <iostream>
#include <iterator>
#include <vector>


using namespace std;

int main(){

    vector<int> numbers{1,2,3,4,5};
    int arr[]{1,3,5,7,9,11,13};

    for(auto it= begin(numbers); it!= end(numbers); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(auto it=begin(arr); it!= end(arr); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    auto thirdElm=next(next(begin(numbers)));
    cout<<"Third element of number is: "<<*thirdElm<<endl;
    cout<<"Third element of array is: "<< *(next(next(begin(arr))))<<endl;
    cout<<"There are "<<distance(begin(numbers),end(numbers))<<" numbers"<<endl;
    cout<<"and "<<distance(begin(arr),end(arr))<<" array numbers\n";


    return 0;
}