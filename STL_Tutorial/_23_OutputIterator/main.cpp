#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

int main(){

    istream_iterator<double> end;
    istream_iterator<double> din(cin); //iterate inputs //input iterator

    vector<double> doubles;
    back_insert_iterator<vector<double>> bins(doubles); //C++17 //output iterator

    while(din!=end){
        *bins=*din++; //*bins++=*din++;
    }
    //Below: ostream_iterator: it add elements orderly and write them in order. 
    partial_sum(doubles.begin(),doubles.end(),ostream_iterator<double>(cout," "));

    cout<<endl;

    return 0;
}