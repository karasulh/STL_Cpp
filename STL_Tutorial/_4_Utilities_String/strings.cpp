#include <iostream>
#include <string>

using namespace std;

int main(){
    //Declaring strings
    string name= "James Slocum";
    string n2("James Slocum");
    string n3(name);

    string n4 { 'J', 'a' ,'m' ,'e' , 's'}; //=> James
    string last(name,6,6); //string name, offset, length => Slocum
    string line(20,'-'); //length, initial char => ----...---
    string reverse(name.rbegin(),name.rend()); //rbegin,rend => reverse

    cout<<name<<endl;
    cout<<n2<<endl;
    cout<<n3<<endl;
    cout<<n4<<endl;
    cout<<last<<endl;
    cout<<reverse<<endl;
    cout<<line<<endl;

    //Finding strings
    std::size_t pos = name.find(n4);
    if(pos!=std::string::npos){
        cout<< "Found first name at: "<<pos<<endl;
    }
    cout << "Comma at "<< ("Hello, How are you?"s ).find(',')<<endl;

    //Append to string
    string about="is a programmer";
    name.push_back(' ');
    for (char c : about){
        name.push_back(c);
    }
    cout <<name <<endl;

    //Insert into strings
    name.insert(0,"I have heard that");
    cout<<name<<endl;

    //Replace some string
    pos=name.find("programmer");
    name.replace(pos,("programmer"s ).length(),"snowboarder");

    pos=name.find("heard");
    name.erase(pos, ("heard"s).length());
    name.insert(pos,"read somewhere");
    cout<<name<<endl;

    return 0;
}