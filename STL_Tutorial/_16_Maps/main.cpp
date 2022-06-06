#include <iostream>
#include <map>

using namespace std;

struct SimpleObject{
    int x;
    int y;
    std::string z;

    SimpleObject() : x(1),y(2),z("stuff") {}
    SimpleObject(int x, int y, const std::string& z): x(x), y(y), z(z) {

    }
};

void maps(){

    map<string,string> stringMap;
    stringMap.insert({"Hello","World"});
    cout<<stringMap["Hello"]<<endl;

    map<string,SimpleObject> objectMap;

    //Insert some elements
    objectMap.insert(pair<string,SimpleObject>("first",SimpleObject(4,8,"Hello"))); 
    objectMap["second"] = SimpleObject();
    objectMap["second"] = SimpleObject(0,0,"Overwritten"); //Overwrite the value of second key 
    objectMap["third"] = SimpleObject(1,6,"World");
    objectMap.insert({"fourth",SimpleObject(1,1,"number 4")});

    //check whether the key already exists 
    const auto [iterator, inserted] = objectMap.insert({"third",SimpleObject()});  //returns tuple 
    if(inserted){                                                                  //split with C++17 Structured Binding
        cout<<"Item inserted!"<<endl;
    }
    else{
        cout<<"key "<< iterator->first << " exists, not inserted" <<endl;
    }

    //Iterate all elements of map
    for(auto& x:objectMap){
        cout<<x.first<<" ->"<<x.second.z<<endl;
    }

    objectMap.erase("second"); //erase an element of map
    objectMap.erase("third");

    auto ptr=objectMap.find("third"); //returns an iterator
    if(ptr == objectMap.end()){
        cout<<"Unable to find third"<<endl;
    }
    else{
        cout<<"found the key "<<ptr->first<<endl;
    }

    objectMap.clear(); //Clear all elements of map
    cout<<"The objectMap is now size: "<< objectMap.size()<< endl;
}


int main(){

    maps();

    return 0;
}