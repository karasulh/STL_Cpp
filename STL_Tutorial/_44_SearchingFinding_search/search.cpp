#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <numeric>
#include <cctype>
#include <functional>

using namespace std;

//If we dont give a specified function for 3. parameter, chose 3.parameter as std::equal_to as default
auto searchString(const string& ref, const string& s, function<bool(unsigned char,unsigned char)> pred = std::equal_to<unsigned char>()){
    return search(begin(ref),end(ref),begin(s),end(s),pred);
}

//to show return type, we write ->bool, but it is optional
std::function<bool(unsigned char, unsigned char)> equal_ignore_case = [](unsigned char rc, unsigned char sc) -> bool {
    return tolower(rc) == tolower(sc);
};

int main(){

    string dna="GATATATACAGGTACCCAATTTACAGATACAAATTTTAAGGAAGAGATATACACACA";
    string text = "Can i match my name JaMeS?";

    auto it = searchString(dna, "GATACA");
    if(it!=end(dna)){
        cout<<"Found GATACA at position: "<<distance(cbegin(dna),it)<<"\n";
    }

    it = searchString(text,"james",equal_ignore_case);
    if(it!=end(text)){
        cout<<"Found james at position: "<<distance(cbegin(text),it)<<"\n";
    }


    //Search with searcher object (C++17)
    string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
    " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    string needle="pisci";

    auto it2=search(in.begin(),in.end(),boyer_moore_horspool_searcher(needle.begin(),needle.end()));

    if(it2!=in.end()){
        cout<<"The string "<<needle<<" found at offset "<< distance(in.begin(),it2) <<"\n";
    }
    else{
        cout<<"The string "<<needle<<" not found\n";
    }


    return 0;
}