#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(){

    vector<int> backInsertionVector ={1,2,3};
    vector<int> forwardVector ={1,2,3};

    back_insert_iterator<vector<int>> bins(backInsertionVector); //Output Iterator
    vector<int>::iterator fit=forwardVector.begin(); //Forward Iterator

    *fit=20; //Forward iterator must be incremented manually.
    *fit=30;//Overwrite
    fit++;

    *bins=20; //Output iterator is automatically incremented
    *bins=30;
    bins++;//No operation

    for(int i:backInsertionVector){
        cout<<i<<" ";
    }

    cout<<endl;

    for(int i:forwardVector){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}