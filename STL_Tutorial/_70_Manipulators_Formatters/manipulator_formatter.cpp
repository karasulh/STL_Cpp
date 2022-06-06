#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    int byte = 0xA9;
    cout<<byte;
    cout<<std::dec<<byte<<"\n";
    cout<<std::oct<<byte<<"\n";
    cout<<std::hex<<byte<<"\n";
    cout<<std::showbase<<std::hex<<byte<<"\n";

    string name ="James Slocum";
    cout<<setfill('*');
    cout<<name<<"\n";
    cout<<setw(40)<<name<<"\n";
    cout<<setw(40)<<std::left<<name<<"\n";
    cout<<setw(40)<<std::right<<name<<"\n";

    long double d= 4*atan(1); //pi
    cout<<d<<"\n";
    cout<<std::setprecision(20)<<d<<"\n";
    cout<<std::setprecision(3)<<d<<"\n";
    cout<<std::scientific<<d<<"\n";

    long double cash=12345; //pi
    cout.imbue(std::locale(""));
    cout<<put_money(cash)<<"\n"; //$123.45
    cout<<put_money(cash,true)<<"\n";// USD 123.45 due to locale
  

    return 0;
}