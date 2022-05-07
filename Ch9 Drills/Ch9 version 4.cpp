#include "std_lib_facilities.h"
using namespace std;

enum class Month {
 jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
 };
 vector<string> month_tbl = { "January", "February", "March", "April","May", "June", "July", "August", "September","October", "November", "December" };


 class Date {
 int y;
 Month m;
 int d;
public:
 Date(int y, Month m, int d); // check for valid date and initialize
 void add_day(int n); // increase the Date by n days
 Month month() { return m; }
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
        if(m==Month::dec)
        {
            Month::jan;
            y++;

        }
        else Month(int(m)+1);
    }

}

Date::Date(int year, Month month, int day)
{

    y=year; m=month; d=day;

       if(y>2022 || d>31)
        {
            error("Date is invalid");

        }
}

bool Date::is_valid()
{
    if(y>2022 ||d>31)
        return false;

    else return true;
}

ostream& operator<<(ostream& os, Month m)
{
 return os << month_tbl[int(m)];
}

ostream& operator<<(ostream& os,Date& x)
{
    if(x.is_valid()==false)
        return os<< "The date is invalid";
    return os << "Date:"<<endl<< "------------"<<endl<<"Year: "<< x.year()<<endl<< "Month: " << x.month()<<endl<<"Day: "<<x.day()<< endl;
}


int main()
{

Date today(1978,Month::jan,25);
Date tomorrow= today;
tomorrow.add_day(1);


cout<<"Today "<<today<<"Tomorrow "<<tomorrow<<endl;



//cout<< "Today:"<< endl<< "------------"<<endl<< "Year: "<<today.y<<endl<<"Month: "<< today.m<<endl<<"Day: "<<today.d<<endl<<"------------"<<endl;

//cout<< "Tomorrow:"<< endl<< "------------"<<endl<< "Year: "<<tomorrow.y<<endl<<"Month: "<< tomorrow.m<<endl<<"Day: "<<tomorrow.d<<endl<<"------------"<<endl;

Date invalid_date(2050,Month::jan,40);

cout<<"The invalid_date check:"<<endl<< invalid_date;





}
