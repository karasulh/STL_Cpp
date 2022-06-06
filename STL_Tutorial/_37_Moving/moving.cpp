#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int main(){

    vector<unique_ptr<int>> intPointers;

    for(int i=0;i<10;i++){
        unique_ptr tmp=make_unique<int>(); //create unique pointer 
        *tmp=i;
        intPointers.push_back(std::move(tmp));//push these pointers by moving into vector
    }

    for_each(begin(intPointers),end(intPointers), [](const unique_ptr<int>&i){
        cout<<*i<<" ";
    });
    cout<<endl;

    //move unique_ptr into container via output iterator
    vector<unique_ptr<int>> morePointers; 
    move(begin(intPointers),end(intPointers),back_inserter(morePointers));

    //After the move, those objects are now all nullptr
    cout<<boolalpha;
    for_each(begin(intPointers),end(intPointers),[](const unique_ptr<int>& i){
        cout<<(i==nullptr)<<" ";
    });
    cout<<endl;

    intPointers.clear(); //dont want to use them by accident later.

    for_each(begin(morePointers),end(morePointers),[](const unique_ptr<int>& i){
        cout<<*i<<" ";
    });
    cout<<endl;

    return 0;
}