#include "std_lib_facilities.h"
#include "my.h"
using namespace std;

void print_foo()
{
    cout<< foo<<endl;
}
void print(int i)
{
    cout<< i<<endl;
}
void swap_v(int a,int b)
 {
  int temp;
  temp = a, a=b;
  b=temp;
 }
void swap_r(int& a,int& b)
 {
      int temp;
      temp = a, a=b;
      b=temp;
 }
/*
void swap_cr(const int&a, const int&b) // It will not compile as we have read-only references(const a, const b)
     int temp;
     temp = a, a=b;
     b=temp;
 }
*/
