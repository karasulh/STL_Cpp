#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string toLowerCase(const string& s){
    string temp;
    std::transform(begin(s),end(s),back_insert_iterator<string>(temp),[](unsigned char c){return tolower(c);});

    return temp;
}

int main(){

    vector<int> numbers{1,2,6,12,48,1,4,2,10,54,12};
    vector<string> words{"Hello","hello", "zebra","x-ray","apple","123","Apple"};

    auto it = is_sorted_until(begin(numbers), end(numbers));
    cout<<"Numbers is sorted for "<<distance(begin(numbers),it)<< " elements\n";

    cout<<std::boolalpha;
    cout<<"numbers is sorted: "<<is_sorted(begin(numbers),end(numbers))<<"\n";

    sort(numbers.begin(),numbers.end());
    sort(begin(words),end(words));

    for_each(begin(numbers),end(numbers),[](auto s){cout<<s<<" ";});
    cout<<endl;

    for_each(begin(words),end(words),[](auto s){cout<<s<<" ";});
    cout<<endl;

    //Note: We didnot modify the contents during sort, only sorted on copied values
    sort(begin(words),end(words),[](const auto& s1, const auto& s2){
        return toLowerCase(s1)<toLowerCase(s2);
    });

    for_each(begin(words),end(words),[](auto s){cout<<s<<" ";});
    cout<<endl;

    return 0;
}