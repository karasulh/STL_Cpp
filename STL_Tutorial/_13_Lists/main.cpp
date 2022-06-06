#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> mylist{10,20,25,30,40,50};
    list<int> other {15,25,35,45,50,55};

    //merge transfers all elements from other to mylist
    mylist.merge(other); //merge, transfer the list, so other will not be used later.

    cout<<"list size= "<<mylist.size()<<endl;
    cout<<"other size= "<<other.size()<<endl;

    //list<int>::iterator i;
    for(auto i=mylist.begin(); i!=mylist.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    mylist.unique();//take unique elements of list

    for(auto i=mylist.begin(); i!=mylist.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    return 0;
}