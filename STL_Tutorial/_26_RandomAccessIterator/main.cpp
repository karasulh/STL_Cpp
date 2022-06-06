#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main(){

    vector<int> vecNum{1,2,3,4,5};
    list<int> listNum{10,20,30,40,50};

    vector<int>::iterator vit = vecNum.begin();
    list<int>::iterator lit = listNum.begin();

    cout<< vit[3] <<endl; //4
    cout<< *(vit+1) <<endl; //2

    //Wont work:
    //cout<< lit[3] <<endl;
    //cout<< *(lit+1) <<endl;

    //Need to do this instead
    std::advance(lit,3); //40
    cout<< *lit <<endl;

    return 0;
}