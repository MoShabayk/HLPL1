#include "std_lib_facilities.h"
using namespace std;

ostream& print_array(ostream& os, int* a)
{
    for(int i = 0; i < 10; ++i)
    {
        os << a[i] << '\n';
    }
    return os;
}
ostream& print_array(ostream& os, int* a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        os << a[i] << '\n';
    }
    return os;
}
ostream& print_vector(ostream& os, vector<int>& vec)
{
    for(int v: vec)
    {
        os<< v<<endl;
    }
}
int main()
{
    int num= 7;
    int* p1= &num; //1. Allocate an int, initialize it to 7, and assign its address to a variable p1.

    cout<<"p1 address:   "<<p1<<"  p1 value: "<<*p1<<endl; // 2. Print out the value of p1 and of the int it points to.


    // 3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
    int* p2= new int[7];

    for(int i=0; i<7;i++)
    {
        p2[i]=i;
    }
    cout<<"p2 address:   "<<p2<<"  p2 value: "<<*p2<<endl; //4. Print out the value of p2 and of the array it points to.



    int*p3=p2; // 5. Declare an int* called p3 and initialize it with p2.


    p2=p1; // 6. Assign p1 to p2.
    p2=p3; // 7. Assign p3 to p2.


    // 8. Print out the values of p1 and p2 and of what they point to.
    cout<<"p1 address:   "<<p1<<"  p1 value: "<<*p1<<endl;
    cout<<"p2 address:   "<<p2<<"  p2 value: "<<*p2<<endl;

    // 9. Deallocate all the memory you allocated from the free store
    delete[]p1;
    delete[]p2;
    delete[]p3;

    p1= new int[10]; // 10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
    for(int i=0;i<10;i++)
    {
        p1[i]=i;
    }

    p2= new int[10]; //11. Allocate an array of ten ints, and assign its address to a variable p2.

    for(int i=0;i<10;i++) // 12. Copy the values from the array pointed to by p1 into the array pointed to by p2.
    {
       p2[i]=p1[i];
    }
    print_array(cout,p2);

    delete[]p1;
    delete[]p2;

    //13. Repeat 10–12 using a vector rather than an array.
    vector<int> p11{1,2,3,4,5,6,7,8,9,10};
    vector<int> p22= p11;

    print_vector(cout,p22);
}
