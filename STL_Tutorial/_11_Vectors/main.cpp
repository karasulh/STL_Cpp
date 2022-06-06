#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printVector(const vector<T>& vec){
    cout<<"used: "<<vec.size() <<"/" << vec.capacity()<<" max size: "<<vec.max_size()<<endl;

    for(const T& t:vec){
        cout<<t<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> numbers; 
    vector<string> strings{"Hello", "How", "are", "you", "doing", "?" }; //strings know the actual size due to initalization, so its capacity 6
    vector<string> strings2; 

    numbers.push_back(100); 
    numbers.push_back(200);
    numbers.push_back(32); //number doesnot know the actual size, so its capacity larger than 3.

    strings2.push_back("Are");
    strings2.push_back("you");
    strings2.push_back("fasting"); //strings2 doesnot know the actual size, so its capacity larger than 3.

    printVector(numbers);
    printVector(strings);
    printVector(strings2);

    strings.resize(3);
    printVector(strings);

    strings.resize(10,"XXXX"); //Make size as 10, and fill empty blocks with XXXX 
    printVector(strings);

    numbers[0]=43;

    numbers.push_back(400);
    numbers.push_back(500);
    printVector(numbers);

    for(int* p = &numbers[0];p<(&numbers[0] +numbers.size()); ++p){
        cout<<*p<<endl; //it shows that for vector, contiguous blocks are allocated.
    }

    //Bad access
    cout<<numbers[10]<<endl;
    //Good way
    try{
        cout<<numbers.at(10); //vectors provides "at" method which can give exception
    } catch(std::out_of_range& e){
        cerr<<e.what()<<endl;
    }


    return 0;
}