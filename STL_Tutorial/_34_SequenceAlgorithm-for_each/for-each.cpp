#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
struct Sum{
    using value_type = T;

    T sum;
    Sum(): sum{} {}
    void operator()(T i){
        sum+=i;
    }
};

template<typename T>
void print(T val){
    cout<<val<<" ";
}

int main(){

    vector<int> numbers{2,4,6,7,10,12,14,16,18,20};

    //std::function<return_type(argument_type)> 
    //&print<int> : function pointer
    std::function<void(int)> printFunction(&print<int>);
    //Use for_each with std::function
    for_each(begin(numbers),end(numbers),printFunction);
    cout<<endl;

    //Use for_each with lambda function
    for_each(begin(numbers),end(numbers), [](int& i){i+=1;});
    for_each(begin(numbers),end(numbers),printFunction);
    cout<<endl;

    //Use for_each with functors
    //Functor: Function object => object which has overriden "()" operation
    //Sum::operator()
    //call "()" operation of Sum object for each elements of numbers
    Sum<int> sum= for_each(begin(numbers),end(numbers),Sum<int>());
    cout<<sum.sum<<endl;

    return 0;
}