#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <string>

using namespace std;

int main(){

    string pop = "abcdefghijklmnoprstuvwxyz";
    string select;

    mt19937 rng {random_device{}()};//Create a RNG

    sample(begin(pop),end(pop),back_inserter<string>(select),5,rng);

    cout<<"Selected: "<<select<<"\n";

    return 0;
}