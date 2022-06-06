#include <iostream>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T=long>
class PrimeGeneratorIterator{
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = T;
    using difference_type = T;
    using pointer = T*;
    using reference =T&;

    PrimeGeneratorIterator(): currentPrime(2){}
    PrimeGeneratorIterator(T initialValue): currentPrime(initialValue){
        if(!isPrime(initialValue)){
            generateNextPrime();
        }
    }

    bool operator==(const PrimeGeneratorIterator& other){
        return this->currentPrime == other.currentPrime;
    }
    bool operator!=(const PrimeGeneratorIterator& other){
        return this->currentPrime != other.currentPrime;
    }
    reference operator*(){
        return currentPrime;
    }
    pointer operator->(){
        return &currentPrime;
    }
    PrimeGeneratorIterator& operator++(){ //++prefix
        generateNextPrime();
        return *this;
    }
    PrimeGeneratorIterator operator++(int){//suffix++
        PrimeGeneratorIterator pgi(*this);
        ++*this;
        return pgi;
    }

private:
    T currentPrime;

    void generateNextPrime(){
        while(!isPrime(++currentPrime));
    }

    bool isPrime(T num){
        if(num<=1)
            return false;
        if(num==2)
            return true;
        if(num%2==0)
            return false;
        for(int i=3;i<=std::sqrt(num);i+=2){
            if(num%i == 0)
                return false;
        }
        return true;
    }
};

int main(){

    PrimeGeneratorIterator<> p_gen;
    PrimeGeneratorIterator<> end(100);

    std::copy(p_gen,end,std::ostream_iterator<long>(std::cout," "));
    cout<<endl;


    return 0;
}