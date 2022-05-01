#include "E:\HLPL\std_lib_facilities.h"

using namespace std;


namespace X
{
int var{0};
void print()
{
    cout<<"x= "<< var<<endl;
}
}
namespace Y
{
 int var{0};
 void print()
{
    cout<<"y= "<< var<<endl;
}
}
namespace Z
{
 int var{0};
 void print()
{
    cout<<"z= "<< var<<endl;
}
}


int main()
{
    X::var = 7;
 X::print(); // print X’s var
 using namespace Y;
 var = 9;
 print(); // print Y’s var
 { using Z::var;
 using Z::print;
 var = 11;
 print();
 } // print Z’s var
 print(); // print Y’s var
 X::print(); // print X’s var
 }
