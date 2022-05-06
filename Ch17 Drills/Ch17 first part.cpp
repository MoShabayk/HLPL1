#include "std_lib_facilities.h"
using namespace std;

ostream& print_array(ostream& os, int* a)
/* 4. Write a function print_array10(ostream& os, int* a) that prints out the
values of a (assumed to have ten elements) to os.*/
{
    for(int i = 0; i < 10; ++i)
    {
        os << a[i] << '\n';
    }
    return os;
}
ostream& print_array(ostream& os, int* a, int n)
/* 7. Write a function print_array(ostream& os, int* a, int n) that prints out the
values of a (assumed to have n elements) to os*/

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
    int* arr10 = new int[10]; //{0,1,2,3,4,5,6,7,8,9}; // 1. Allocate an array of ten ints on the free store using new.

  for(int i =0;i<10;i++)
    {
        arr10[i]=i;
    }

   /* for(int i=0;i<10;i++)
    {
        cout<< arr[i]<<endl; // 2. Print the values of the ten ints to cout.
    } */

    print_array(cout, arr10);

    delete[] arr10; // 3. Deallocate the array (using delete[]).

  for(int i =0;i<10;i++) //5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    {
        arr10[i]=i+100;
    }
     print_array(cout, arr10);// it will work fine with the new values as we deallocated the older values in Q1.

    delete[] arr10;

      for(int i =0;i<11;i++)  //6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    {
        arr10[i]=i+100;
    }
     print_array(cout, arr10);//it will work fine but the last value (11) will not be visible as pinter arr allocates 10 slots in the free-store

    delete[]arr10;

     int* arr20 = new int[20];
     /* 8. Allocate an array of 20 ints on the free store; initialize it with the values
100, 101, 102, etc.; and print out its values.*/

      for(int i =0;i<20;i++)
    {
        arr20[i]=i+100;
    }

    cout<< arr20[2];
   print_array(cout,arr20,20);

    delete[]arr20;

//---------------------------- 10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().

vector<int> vec(10);

    for(int i=0;i<10;i++)
    {
        vec[i]=i;
    }

    print_vector(cout,vec);

    return 0;
}
