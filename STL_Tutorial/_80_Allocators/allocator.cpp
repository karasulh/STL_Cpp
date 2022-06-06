#include <iostream>
#include <memory>

using namespace std;

int main(){

    //the deprecated way to access an allocator
    std::allocator<int> a1;
    std::allocator<double> a2;

    int* i=a1.allocate(1); // allocate a memory for 1 int
    cout<<i<<": "<<*i<<"\n";
    a1.construct(i,123); //Only for C++11, deprecated in C++17 use allocator_traits
    cout<<i<<": "<<*i<<"\n";

    cout<<"allocating 5 doubles\n";
    double* d= a2.allocate(5);

    for(int i=0; i<5;i++){
        cout<<&d[i]<<": "<<d[i]<<"\n";
    }

    cout<<"constructing d and d[2] only\n";
    a2.construct(&d[2],3.14);//Only for C++11, deprecated in C++17 use allocator_traits
    a2.construct(d,999.13); //change d[0] //Only for C++11, deprecated in C++17 use allocator_traits

    for(int i=0; i<5;i++){
        cout<<&d[i]<<": "<<d[i]<<"\n";
    }

    a1.destroy(i); //Not essential before deallocating //Only for C++11, deprecated in C++17 use allocator_traits
    a1.deallocate(i,1); //to avoid from dangling reference/memory leak, do it

    a2.destroy(d); //Only for C++11, deprecated in C++17 use allocator_traits
    a2.destroy(&d[2]);//Only for C++11, deprecated in C++17 use allocator_traits
    a2.deallocate(d,5);


    //The correct way to access an allocator
    int* x=allocator_traits<std::allocator<int>>::allocate(a1,1);
    allocator_traits<std::allocator<int>>::construct(a1,x,9876);

    cout<<"x addr="<<x<<": "<<*x<<"\n";
    allocator_traits<std::allocator<int>>::deallocate(a1,x,1);

    /* */
    //Defining an Allocator, Custom Allocator
    


    return 0;
}