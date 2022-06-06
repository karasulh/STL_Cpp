#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){

    locale loc;
    cout<<"Using locale "<< loc.name()<<"\n";
    cout<<"Here is a double: "<< 18.90d <<"\n";
    cout<<"Here is a char: "<< 'J' <<"\n";
    cout<<"Here is an int: "<< 101 <<"\n";

    string val = "Here is a string from a variable, ";
    double pi= 3.1415;
    cout<<val<<" it can be combined with other things like "<<pi<<"\n";
    cout<<"Outputs to UTF-8, so it supports a huge character set, including emoji\n";

    string face = "How about a \U0001f60a?";
    cout<<face<<"\n";


    int x=0;
    double d=0;
    string name="";

    cout<<"Please enter an integer ";
    cin>>x;

    cout<<"Please enter an double ";
    cin>>d;

    cout<<"Please enter an name ";
    cin>>name;

    cout<<"We expect a number, so enter a string ";
    cin>>x;

    if(cin.fail()){
        cin.clear();
        cerr<< "There was an error reading a number from the user\n";
        string s;
        cin>>s;
        cout<<"Read string: "<<s<<" from user\n";
    }
    else{
        cout<<"Read in value: "<<x<<" from the user\n";
    }

    return 0;
}