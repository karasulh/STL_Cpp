#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Student {
private : 
    int id;
    string first;
    string last;

public: 
    Student(int id, const string& first, const string& last) :
      id(id), first(first), last(last) {}

    Student() :
      id{}, first({}), last({}) {}

    int getId() {
      return id;
    }

    const string& getFirst() const {
      return first;
    }

    const string& getLast() const {
      return last;
    }
};

class StudentDeleter{
public:
    void operator()(Student* s) const{ //callable operator
        cout<<"StudentDeleter: deleting "<<s->getFirst()<<" "<<s->getLast()<<"\n";
        delete s;
    }
};

int main(){

    unique_ptr<Student> s1(new Student(1,"John","Smith")); // First way of creating unique_ptr
    unique_ptr<Student> s2 = make_unique<Student>(2,"Mike","Sith"); // Second way of creating unique_ptr
    unique_ptr<Student> s3 = make_unique<Student>();

    StudentDeleter d;
    Student* bugra = new Student(3,"Bugrahan","Kara");

    unique_ptr<Student,StudentDeleter> j(bugra,d); //we can create unique_ptr with deleter

    unique_ptr<Student> n=nullptr;

    return 0; 
}