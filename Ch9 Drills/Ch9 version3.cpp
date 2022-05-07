#include "std_lib_facilities.h"
using namespace std;



 class Date {
 int y, m, d; // year, month, day
public:
 Date(int y, int m, int d); // check for valid date and initialize
 void add_day(int n); // increase the Date by n days
 int month() { return m; }
 int day() { return d; }
 int year() { return y; }
 bool is_valid();
};

void Date::add_day(int n)
{
      d = d+n;
    if(d >31)
    {
        d= d-31;
        m= m+1;
        if(m>12)
        {
            m-=12;
            y+=1;
        }
    }

}

Date::Date(int year, int month, int day)
{

    y=year; m=month; d=day;

       if(y>2022 || m>12 || d>31)
        {
            error("Date is invalid");

        }
}

bool Date::is_valid()
{
    if(y>2022 || m>12 ||d>31)
        return false;

    else return true;
}

ostream& operator<<(ostream& os,Date& x)
{
    if(x.is_valid()==false)
        return os<< "The date is invalid";
    return os << "Date:"<<endl<< "------------"<<endl<<"Year: "<< x.year()<<endl<< "Month: " << x.month()<<endl<<"Day: "<<x.day()<< endl;
}


int main()
{

Date today(1978,6,25);
Date tomorrow= today;
tomorrow.add_day(1);


cout<<"Today "<<today<<"Tomorrow "<<tomorrow<<endl;



//cout<< "Today:"<< endl<< "------------"<<endl<< "Year: "<<today.y<<endl<<"Month: "<< today.m<<endl<<"Day: "<<today.d<<endl<<"------------"<<endl;

//cout<< "Tomorrow:"<< endl<< "------------"<<endl<< "Year: "<<tomorrow.y<<endl<<"Month: "<< tomorrow.m<<endl<<"Day: "<<tomorrow.d<<endl<<"------------"<<endl;

Date invalid_date(2050,6,40);

cout<<"The invalid_date check:"<<endl<< invalid_date;





}
