#include "std_lib_facilities.h"

using namespace std;

template<typename C>
void printout(const C& c)
{
     for (auto& a : c)
        std::cout << a << ' ';

    cout<<endl;
}
template<typename C>
void printout(const C& c, int x)
{
     for (auto& a : c)
        std::cout << a+x<< ' ';

    cout<<endl;
}

template<typename T,typename T2>
T2 my_copy (T first,T endfirst,T2 second)
{
    for(T p= first; p != endfirst;p++)
    {
        *second++ = *p;
    }
    return second;
}
int main()
{
 const int size=10;
 array<int,size> integar_array={0,1,2,3,4,5,6,7,8,9}; // 1. Define an array of ints with the ten elements
 vector<int>integar_vector={0,1,2,3,4,5,6,7,8,9};// 2. Define a vector<int> with those ten elements.
 list<int>integar_list={0,1,2,3,4,5,6,7,8,9};// 3. Define a list<int> with those ten elements.

/* 4. Define a second array, vector, and list, each initialized as a copy of the first
array, vector, and list, respectively.*/
 array<int,size> test = integar_array;
 vector<int> test2= integar_vector;
 list<int> test3= integar_list;

 printout(test);
 printout(test2);
 printout(test3);

/* 5. Increase the value of each element in the array by 2; increase the value of
each element in the vector by 3; increase the value of each element in the
list by 5.*/
 printout(integar_array,2);
 printout(integar_vector,3);
 printout(integar_list,5);


//7. Use your copy() to copy the array into the vector and to copy the list into the array.
 my_copy(integar_array.begin(), integar_array.end(),test2.begin());
//my_copy(integar_vector.begin(),integar_vector.end(),test2.begin());
 my_copy(integar_list.begin(),integar_list.end(),test.begin());

 printout(integar_array);
 printout(integar_vector);
 printout(integar_list);

 /* 8. Use the standard library find() to see if the vector contains the value 3
and print out its position if it does; use find() to see if the list contains the
value 27 and print out its position if it does. The “position” of the first
element is 0, the position of the second element is 1, etc. Note that if find()
returns the end of the sequence, the value wasn’t found.*/

 vector<int>::iterator counter;
 counter=find(integar_vector.begin(),integar_vector.end(),3);
 if (counter != integar_vector.end())
    {
        std::cout << "Element found at position : " ;
        std::cout << counter - integar_vector.begin();
    }
    else
        std::cout << "Element not found.\n\n";
}
