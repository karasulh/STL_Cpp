//Input Iterator
#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>
#include <cctype> //access to some C standard library

using namespace std;

bool isValidChar(char c){
    return !(isalpha(c));
}

int main(){

    istream_iterator<string> end; //iterator to end of stream //Ctrl+Z=EOF
    istream_iterator<string> ins(cin); //iterator through the strings which user types 

    map<string,int> wordFrequencies;

    while(ins!=end){
        string word = *ins++;
        //Explanation for below sentence: 
        //remove_if doesnot delete characters, it puts unwanted elements to at the end of string, then return iterator of unwanted chars
        //Later, erase deletes the unwanted elements thanks to given iterator
        //With this method, we can take pure word not with punctuations from text : "car" vs "car," 
        word.erase(remove_if(word.begin(),word.end(),&isValidChar),word.end());

        if(wordFrequencies.find(word) != wordFrequencies.end()){
            wordFrequencies[word]++;
        }
        else{
            wordFrequencies[word] = 1;
        }
    }

    for(const auto& p:wordFrequencies){
        cout<<p.first<<" : "<<p.second<<"\n";
    }
    cout<<flush;

    return 0;
}