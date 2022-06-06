#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Student{
    int id;
    string firstName;
    string lastName;

    Student(): id{}, firstName{},lastName{} {}
    Student(int id, string first, string last): id(id), firstName(first), lastName(last) {}
};

int main(){

    cout<<std::boolalpha;

    vector<int> num1(100,0);
    vector<int> num2(100,0);

    bool e = equal(begin(num1),end(num2),begin(num2)); //Compare the size and inside of them.
    cout<<e<<endl; //true

    e = equal(begin(num1),end(num2),begin(num2),end(num2));
    cout<<e<<endl; //true

    vector<Student> class1;
    vector<Student> class2;

    class1.push_back({0,"James","Slocum"});
    class1.push_back({1,"Jame","Slocu"});
    class1.push_back({2,"Jam","Sloc"});
    class1.push_back({3,"Ja","Slo"});

    class2.push_back({0,"Ja","Slo"});
    class2.push_back({1,"Jam","Sloc"});
    class2.push_back({2,"Jame","Slocu"});
    class2.push_back({3,"James","Slocum"});

    //std::function<return_type(argument_types)>  = lambda function
    function<bool(const Student&,const Student&)> id_only = [](const Student& s1, const Student& s2){
        return s1.id==s2.id;
    };

    function<bool(const Student&,const Student&)> all_fields = [](const Student& s1, const Student& s2){
        return s1.id==s2.id && s1.firstName == s2.firstName && s1.lastName == s2.lastName ;
    };

    e = equal(begin(class1),end(class1),begin(class2),end(class2), id_only);
    cout<<e<<endl; //true

    e = equal(begin(class1),end(class1),begin(class2),end(class2), all_fields);
    cout<<e<<endl; //false

    return 0;
}