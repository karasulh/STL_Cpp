#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

using namespace std;

template<typename InputIt, typename OutputIt>
OutputIt copy_every_other(InputIt begin, InputIt end,OutputIt out){ //Generic Function

    while(begin!=end){
        *out++ = *begin;
        ++begin;
        if(begin == end) break;
        ++begin;
    }
    return out;
}

int main(){

    vector<double> numbers{1.0, 1.1, 1.2, 1.3, 1.4, 1.5};
    vector<double> other;

    std::copy(std::begin(numbers),std::end(numbers),ostream_iterator<double>(std::cout," "));
    cout<<endl;

    copy_every_other(std::begin(numbers), std::end(numbers), back_insert_iterator<vector<double>>(other));//.use generic func.

    for(double d: other){
        cout<<d<<" ";
    }
    cout<<endl;

    copy_every_other(std::begin(numbers), std::end(numbers),ostream_iterator<double>(std::cout," ")); //the same with above

    return 0;
}