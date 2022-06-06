// #include <iostream>
// #include <exception>

// //EXCEPTIONS

// class ResourceException : public std::exception{ //Inherit this class from std::exception 
//     std::string w;
// public:
//     ResourceException(const std::string& w): w(w) {}
//     const char* what() const noexcept{ //overrride the what function of std::exception library 
//         return w.c_str();
//     }
// };

// class SomethingImportant{
//     public:
//     SomethingImportant(){
//         throw ResourceException("Unable to open some resource I need");//1.option
//         //throw(10); //2.option
//         //throw("catch it trial"); //3.option
//     }
// };



// int main(){

//     try{
//         SomethingImportant si;
//     } catch(std::exception& except){ //1.option
//         std::cout<<except.what()<<std::endl;
//         return 1;
//     } catch(int i){ //2.option
//         std::cout<<"I caught and int value: "<<i<<std::endl;
//         return 2;
//     } catch(...){ //catch all exceptions //3.option
//         std::cout<<"Catch All"<<std::endl;
//         return 3;
//     }
//     return 0;
// }


//MEMORY

#include <iostream>
#include <memory>
using namespace std;

class Widget{ 
    int num;
public:
    Widget(int num):num(num) {
        std::cout<<"Constructing Widget "<< num << std::endl;
    }
    virtual ~Widget(){
        std::cout << "Destroying Widget" << num <<std::endl;
    }    
};

int main(){
    Widget* w= new Widget(1);
    unique_ptr<Widget> uw= make_unique<Widget>(2);
    Widget w2= Widget(3);
    return 0; 
}