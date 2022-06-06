#include <memory>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class debug_allocator{
public:
    using value_type=T;

    debug_allocator() noexcept {} //constructor for allocator class

    template<typename U>
    debug_allocator(const debug_allocator<U>&) noexcept {} //copy constructor for allocator class

    value_type* allocate(std::size_t n){
        std::size_t size = n * sizeof(value_type);
        value_type* t = static_cast<value_type*>(::operator new(size));
        cout<<"allocated "<<size<<" bytes at addr: "<<t<<"\n";
        return t;
    }

    void deallocate(value_type* p, std::size_t n) noexcept{
        std::size_t size = n* sizeof(value_type);
        ::operator delete(p); //global delete operator
        cout<<"deallocated "<<size<<" bytes at addr: "<<p<<"\n";
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args&& ...args){
        ::new(p) U(std::forward<Args>(args)...);
        cout<<"constructed new "<<typeid(decltype(*p)).name()<<" at addr: "<<p<<"\n";
    }

    template<typename U>
    void destroy(U* p) noexcept{
        p->~U();
        cout<<"destroyed "<<typeid(decltype(*p)).name()<<" at addr: "<<p<<"\n";
    }

    template<typename U>
    bool operator==(const debug_allocator<U>&) noexcept{
        return true; //to be simple
    }

    template<typename U>
    bool operator!=(const debug_allocator<U>& u) noexcept{
        return (*this == u);
    }
};

int main(){

    debug_allocator<int> d;
    vector<int,debug_allocator<int>> v(d); //vector uses our allocator

    //When we add a new element into vector, it looks the storage capacity of it, if it is not enough,
    //it takes a doubled storage place and copies(construct) the previous elements into new place,
    //then delete the previous elements in the previous place.
    //We will see this case with our allocator prints.

    cout<<"emplace 1\n";
    v.emplace(v.end(),1);
    cout<<"emplace 2\n";
    v.emplace(v.end(),2);
    cout<<"emplace 3\n";
    v.emplace(v.end(),3);



    return 0;
}
