#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main(){

    function<bool(unsigned char)> pred= [](unsigned char c)->bool{
        return isupper(c);
    };

    string s="This Is Some String Of Text In Mixed Case";

    //partition_copy
    /*
    string s_true;
    string s_false;

    partition_copy(begin(s),end(s),back_inserter(s_true),back_inserter(s_false),pred);

    cout<<s<<"\n";
    cout<<s_true<<"\n";
    cout<<s_false<<"\n";
    */
    
    if(!is_partitioned(begin(s),end(s),pred)){
        partition(begin(s),end(s),pred);
    }

    cout<<"String now: "<<s<<"\n";

    auto part= partition_point(begin(s),end(s),pred);

    cout<<"True bucket: ";
    copy(begin(s),part,ostream_iterator<char>(cout,""));
    cout<<"\n";

    cout<<"False bucket: ";
    copy(part, end(s), ostream_iterator<char>(cout,""));
    cout<<"\n";

    return 0;
}