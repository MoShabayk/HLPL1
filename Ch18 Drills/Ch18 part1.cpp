#include "std_lib_facilities.h"
#include <cmath>


using namespace std;
// 1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

//2. Define a function f()
//drill 3.
f(int x[],int n)
{

    int la[10];
    for (int i = 0; i < n; ++i)
        la[i] = x[i];

     for (auto& a : la)
        cout << a << ' ';
     cout <<endl;

      int* p = new int[n];
      for (int i = 0; i < n; ++i)
        p[i] = x[i];

     cout << "elements of the free store"<<endl;
    for (int i = 0; i < n; ++i)
        cout << p[i] << ' ';
    cout <<endl;

    delete[] p;
}
int main()
{

    /*------------------Array Drill---------------------------------*/
    //4.a. Call f() with ga as its argument.
    f(ga, 10);

    int aa[10];
    for (int i=0; i<10;i++) //4.b.b. Define an array aa with ten elements, and initialize it with the first ten factorial values
        aa[i] = tgamma(i + 2); ////tgamma performas factorial with n - 1 -> hence we use n + 1

    //4.c.c. Call f() with aa as its argument.
    f(aa,10);
}
