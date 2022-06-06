#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //to write
    ofstream os("outputfile.txt"); // if the file exists, file is truncated, overwritten.
                                   // if the file doesnot exist, it creates this file.
    int i =231;
    double d=3.1883;
    char c='j';
    string name="James";

    os << i <<" "<< d <<" "<< c << name;
    os.close();

    os.open("outputfile.txt",ios::app);
    os<<"\nThis is appended to end!\n";
    os.close();

    //to read
    ifstream is("outputfile.txt");

    int i_2;
    double d_2;
    char c_2;
    string name_2;

    is >> i_2 >> d_2 >> c_2 >> name_2;
    is.close();

    cout << i_2 << " " << d_2 <<" " << c_2 << " " << name_2;

    return 0;
}