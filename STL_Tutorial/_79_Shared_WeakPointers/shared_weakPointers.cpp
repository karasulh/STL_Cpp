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

void printStudent(weak_ptr<Student> s){ //if s is shared_ptr, shared_ptr => weak_ptr implicit conversion
    cout<<s.use_count()<<" references open\n"; //Only weak_ptr = 1,it doesnt not affect the shared_ptr ref count
    if(shared_ptr<Student> l= s.lock()){ // weak_ptr => shared_ptr
        cout<<l->getFirst()<<" "<< l->getLast()<<"\n";
    }
    else{
        cout<<"pointer has expired\n";
    }
}

void printSharedStudent(shared_ptr<Student> s){ //pass by value // copy of shared_ptr not okay for unique_ptr
    cout<<s.use_count()<<" references open\n"; //It is 2 due to copied shared_ptr
    cout<<s->getFirst()<<" "<< s->getLast()<<"\n";
}

int main(){

    weak_ptr<Student> w;
    {
        shared_ptr<Student> s(new Student(1,"John","Smith"));

        StudentDeleter sd;
        Student *j= new Student(3,"Bugrahan","Kara");
        shared_ptr<Student> student(j,sd);

        printStudent(s);
        printSharedStudent(student);

        printSharedStudent(s);
        printSharedStudent(student);

        w=student;

        printStudent(w);
    }
    printStudent(w);    

    return 0; 
}