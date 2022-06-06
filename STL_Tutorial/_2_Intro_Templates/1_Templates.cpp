#include <iostream>
using namespace std;

template<typename T> //Template class
class Container{
    T t;
public:
    explicit Container(T t):t(t){}

friend std::ostream& operator<<(std::ostream& os, const Container<T>& c){
        return (os<<"Container holding "<< c.t);
    } 
};

template<typename X> //We can use template for function
bool isGreator(X x1, X x2){
	return x1>x2;
}

template<> //If we declare it like that, it is always called when we use isGreator function with "int"
bool isGreator(int x1,int x2){
	std::cout<<"Specialized for int"<<endl;
	return x1>x2;
}

auto lambda = []<typename T> (T t1,T t2){ //Template can be used in Lambda function after C++14
	return t1==t2; 
};


int main(){

	cout<<std::boolalpha;//Use it for write boolean result as "true or false" not "1 or 0"

	Container<int> c(100);
	Container<string> s("Some String");
	cout<<c<<"\n";
	cout<<s<<"\n"; //It gives error in VisualStudio compiler but not in g++ compiler

	cout<< isGreator(5,10)<<endl;
	cout<< isGreator("ZZZ","AAA")<<endl;
	cout<< isGreator(5.2,10.85)<<endl;
	cout<< isGreator('c','r')<<endl;

	cout<<"Lambda returns:"<<lambda(10,10)<<endl;

	return 0;
}