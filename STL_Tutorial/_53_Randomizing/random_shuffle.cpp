#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <random>

using namespace std;

int main(){

    //We want to show that if the seed is known, they are the same "random" number.
    //With the same seed, we obtain the same random sequence
    mt19937 rng1(100); //Mersenne Twister(mt19937) RNG algorithm, seed it with 100
    mt19937 rng2(100);
    
    for(int i=0;i<10;i++){
        cout<<"RNG1: "<<rng1()<<", ";
        cout<<"RNG2: "<<rng2()<<"\n";
    }

    //Now lets re-seed with random entropy
    rng1.seed(random_device{}());
    rng2.seed(random_device{}());
    
    for(int i=0;i<10;i++){
        cout<<"RNG1: "<<rng1()<<", ";
        cout<<"RNG2: "<<rng2()<<"\n";
    } 
    
    vector<int> n{0,1,2,3,4,5,6,7,8,9};
    for_each(begin(n),end(n),[](auto& i){cout<<i<<" ";});
    cout<<"\n";

    shuffle(begin(n),end(n),rng1);
    for_each(begin(n),end(n),[](auto& i){cout<<i<<" ";});
    cout<<"\n";

    return 0;
}