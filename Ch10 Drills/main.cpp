#include "std_lib_facilities.h"

using namespace std;

//1.Begin by defining the data type Point that has two coordinate members x and y
struct Point {
 int x;
 int y;
 Point(int x,int y);
 Point();
};
Point::Point(int xx,int yy) // constructor
{
     x=xx;
     y=yy;
}
Point::Point() //empty constructor to allow me define points with no values;
{

}

//2.
/*Why is it different from my Ch20 code?
cause I didn't have const number of values in ch20, so i made a for loop*/
istream& operator>>(istream& ist,Point& p)
{
    char ch1,ch2,ch3;
    int x;
    int y;
    ist >> ch1>>x>>ch2>>y>>ch3;
    if (ch1 != '(' || ch2!=','||ch3!=')') {
        ist.unget(); //t. The unget() function is a shorter version of putback() that relies on the stream remembering which character it last produced
        return ist;
    }
    p= Point(x,y);
    return ist;
}
ostream& operator<<(ostream& ost,Point& p)
{
    return ost<<'('<<p.x<<','<<p.y<<')'<<endl;
}
bool compare(vector<Point> first,vector<Point> second)
 //7. Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.
{
    if(first.size()!= second.size())
        return false;

    for(int i=0;i<first.size();i++)
    {
        if(first[i].x !=second[i].x || first[i].y != second[i].y)
            return false;
    }

    return true;
}
int main()
{
    int size=7;
    vector<Point> original_points;

   for(int i=0;i<7;i++)
    {
        Point p;
        cin>>p;
        original_points.push_back(p);
    }

    string oname;
 cout << "Please enter name of output file: ";
 cin >> oname;
 ofstream ost {oname}; // ost writes to a file named oname
 if (!ost) error("can't open output file ",oname);

 for(auto& a:original_points) //4.output each point to a file named mydata.txt.
    ost<<a;
 ost.close();


 vector<Point> processed_points;

 cout << "Please enter input file name: ";
 string iname;
 cin >> iname;
 ifstream ist {iname}; // ist reads from the file named iname
 if (!ist) error("can't open input file ",iname);
 for(Point p;ist>> p;)
    processed_points.push_back(p);

ist.close();
for(auto& a:original_points)
    cout<< a;

for(auto& b:processed_points)
    cout<<b;

if(!compare(original_points,processed_points))
    cout<< "Something is wrongs";
else cout<< "All good!";

}

