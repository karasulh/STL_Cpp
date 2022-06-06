#include <vector>
#include <iostream>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

template<typename ForwardIt>
void print(ForwardIt begin,ForwardIt end){
    for_each(begin,end,[](const auto& a){
        cout<<a<<" ";
    });
    cout<<endl;
}

int main(){

    vector<int> num{2,2,2,2,2,2,2,2,2,2};
    vector<int> out;

    partial_sum(begin(num),end(num),back_inserter<vector<int>>(out));
    print(begin(out),end(out));
    out.clear();

    partial_sum(begin(num),end(num),back_inserter<vector<int>>(out),multiplies<int>());
    print(begin(out),end(out));

    vector<int> diff;
    adjacent_difference(begin(out),end(out), back_inserter<vector<int>>(diff));
    print(begin(diff),end(diff));

    vector<int> fib(15,0);//fill 15 elements with 0
    fib[0]=1;
    //prev(end(fib)=last element of fib ; next(begin(fib)= second element of fib
    adjacent_difference(begin(fib),prev(end(fib)), next(begin(fib)),plus<int>());
    //1 0 0 0 0
    //1 1 0 0 0
    //1 1 2 0 0
    //1 1 2 3 0 ...
    print(begin(fib),end(fib));

    return 0;
}