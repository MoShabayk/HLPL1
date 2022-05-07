#include "std_lib_facilities.h"
using namespace std;


// 1. The version from §9.4.1
struct Date {
 int y; // year
 int m; // month in year
 int d; // day of month


};

void add_day(Date& x, int n)
{
    x.d = x.d+n;
    if(x.d >31)
    {
        x.d= x.d-31;
        x.m= x.m+1;
        if(x.m>12)
        {
            x.m-=12;
            x.y+=1;
        }

    }
}
bool is_valid(Date x)
{
    if(x.y>2022 || x.m>12 ||x.d>31)
        return false;

    else return true;
}

ostream& operator<<(ostream& os,Date& x)
{
    if(is_valid(x)==false)
        return os<< "The date is invalid";
    return os << "Date:"<<endl<< "------------"<<endl<<"Year: "<< x.y<<endl<< "Month: " << x.m<<endl<<"Day: "<<x.d<< endl;
}


int main()
{

//1. The version from §9.4.1
Date today;
today.y=1978;
today.m=6;
today.d=25;

Date tomorrow= today;
add_day(tomorrow,1);


cout<<"Today "<<today<<"Tomorrow "<<tomorrow<<endl;
//cout<< "Today:"<< endl<< "------------"<<endl<< "Year: "<<today.y<<endl<<"Month: "<< today.m<<endl<<"Day: "<<today.d<<endl<<"------------"<<endl;

//cout<< "Tomorrow:"<< endl<< "------------"<<endl<< "Year: "<<tomorrow.y<<endl<<"Month: "<< tomorrow.m<<endl<<"Day: "<<tomorrow.d<<endl<<"------------"<<endl;

Date invalid_date;
invalid_date.y= 2050;
invalid_date.m=6;
invalid_date.d=40;

cout<<"The invalid_date check:"<<endl<< invalid_date;





}
