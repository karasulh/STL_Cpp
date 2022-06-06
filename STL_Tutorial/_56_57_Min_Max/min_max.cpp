#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    
    //MIN
    cout<<min("Hello","world")<<" is smaller\n";
    cout<<min(45,51)<<" is smaller\n";

    //Use 's' to show it is string, not unsigned char array
    cout<<min("AAAA"s, "XX"s, [](const string& s1,const string& s2){ 
        return s1.size() < s2.size();
    }) << " is shorter\n";

    cout<<min({42,5,63,14,0,41}) <<" is smaller\n"; //initializer list

    vector<double> d{1.3,6.12,0.543,1.0,-5.0,0.001};
    
    auto it = min_element(begin(d),end(d));
    cout<<*it<<" is the smallest\n";

    it = min_element(begin(d),end(d),[](const double& a, const double& b){
        return abs(a)<abs(b);
    });
    cout<<*it<<" is the smallest absolute value\n";


    ////////MAX
    cout<<max("Hello","world")<<" is larger\n";
    cout<<max(45,51)<<" is larger\n";

    //Use 's' to show it is string, not unsigned char array
    cout<<max("AAAA"s, "XX"s, [](const string& s1,const string& s2){ 
        return s1.size() < s2.size(); /*Careful!*/
    }) << " is larger\n";

    cout<<max({42,5,63,14,0,41}) <<" is larger\n"; //initializer list

    vector<double> d2{1.3,6.12,0.543,1.0,-5.0,0.001};
    
    auto it2 = max_element(begin(d2),end(d2));
    cout<<*it2<<" is the largest\n";

    it2 = max_element(begin(d2),end(d2),[](const double& a, const double& b){
        return abs(a)<abs(b);
    });
    cout<<*it2<<" is the largest absolute value\n";

    return 0;
}