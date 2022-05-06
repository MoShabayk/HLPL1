#include "std_lib_facilities.h"
#include <cmath>


using namespace std;
//  1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc
vector<int> gv= { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

//2. Define a function f()
//drill 3.
f( vector<int> vec)
{

    vector<int> lv;
    lv =vec; //4. b. Copy the values from gv into lv.

    cout << "elements of lv1:"<<endl;
    for (auto& a : lv) // c. Print out the elements of lv.
        cout << a << ' ';
    cout <<endl;

    vector<int> lv2 = vec; //d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.

     cout << "elements of lv2:"<<endl;
     for (auto& a : lv2) // e. Print out the elements of lv2.
        cout << a << ' ';
    cout << endl;


}
int main()
{

    /*------------------Vector Drill---------------------------------*/
    //4.a. Call f() with gv as its argument.
    f(gv);
 cout<<"test";
    vector<int> vv(10);
    for (int i = 1; i < 10; ++i)
        vv[i] = tgamma(i+2); ////tgamma performas factorial with n - 1 -> hence we use n + 1

    f(vv); // c. Call f() with vv as its argument.
}
