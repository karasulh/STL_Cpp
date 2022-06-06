#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){

    string s="This is some string";
    vector<int> n{0,1,2,3,4,5,6,7,8,9,10};

    cout<<s<<"\n";
    replace(begin(s),end(s),'s','B');
    cout<<s<<"\n";

    for_each(begin(n),end(n),[](int i){cout<<i<<" ";});
    cout<<endl;

    replace_if(begin(n),end(n),[](int i)->bool{return i>=7;},6);
    
    for_each(begin(n),end(n),[](int i){cout<<i<<" ";});
    cout<<endl;

    //replace_copy
    vector<int> v{0,1,2,3,4,5,6,7,8,9,0};
    vector<int> v_copy;

    replace_copy(begin(v),end(v),back_inserter<vector<int>>(v_copy),4,87878);
    
    for_each(begin(v_copy),end(v_copy),[](const int&i){cout<<i<<" ";});
    cout<<"\n";

    v_copy.clear();

    replace_copy_if(begin(v),end(v),back_inserter<vector<int>>(v_copy),[](const int& i){return i<7;},55);
    
    for_each(begin(v_copy),end(v_copy),[](const int&i){cout<<i<<" ";});
    cout<<"\n";


    return 0;
}