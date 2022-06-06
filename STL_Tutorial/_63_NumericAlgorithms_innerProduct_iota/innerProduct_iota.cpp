#include <vector>
#include <iostream>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

int main(){

    vector<int> set1(20);
    vector<int> set2(20);

    iota(begin(set1),end(set1),1);
    iota(begin(set2),end(set2),10);

    copy(begin(set1),end(set1),ostream_iterator<int>(cout," "));
    cout<<"\n";
    copy(begin(set2),end(set2),ostream_iterator<int>(cout," "));
    cout<<"\n";

    //3rd parameter: initial value of the inner product
    int v=inner_product(begin(set1),end(set1),begin(set2),0);
    cout<<"inner product is: "<<v<<endl;
    
    //use plus operation instead of multiply, so it is like "inner sum" :)
    v=inner_product(begin(set1),end(set1),begin(set2),0,std::plus<int>(),std::plus<int>());
    cout<<"sum of sums is "<<v<<endl;

    //after xored, "and"ed them <= first function place is sum, second one is product
    vector<bool> bits1 {true,true,false,true,false,true,true,false};
    vector<bool> bits2 {false,false,true,false,true,false,false,true};
    bool allTrue = inner_product(begin(bits1),end(bits2),begin(bits2),true,std::bit_xor<bool>(),std::logical_and<bool>());
    cout<<"Data parity: "<<(allTrue ? "Good" : "Bad")<<"\n";

    return 0;
}