#include "my.h"
#include <iostream>
using namespace std;
char cc;
int foo =7;
int main()
{
    cin>>cc;
    print_foo();
    print(99);

    int x = 7;
    int y =9;
    swap_v(x,y); //it will compile, but will not replace the values, as the variables passed by value, not by reference.
    cout<< "x= "<< x<<endl<<"y= "<<y<<endl;
    swap_r(x,y); //it will work fine, as we passed variables by reference.
    cout<< "x= "<< x<<endl<<"y= "<<y<<endl;
    swap_v(7,9); // compile but does nothing for the same reason
    const int cx = 7;
    const int cy = 9;
    swap_v(cx,cy); //compile but doens't work, for the same reason, and as the variables was passed by value, it's a copy, so it will work even if the variables are constants
    swap_v(7.7,9.9); // it worked even thought its not int, but i think it was compiled to int (7,9) when passed

   // swap_r(cx,cy); //it will not compile because the constant variables' cant be changed
    cout<< "cx= "<< cx<<endl<<"cy= "<<cy<<endl;


    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy); //it will compile, bot will not swap, due to swapping by value like previous functions
    //swap_r(dx,dy); // it didn't compile, as the dx,dy was defined as double while the swap_r has int parameters, regardless of their values.
    cout<< "dx= "<< dx<<endl<<"dy= "<<dy<<endl;
    swap_v(7.7,9.9);


}
