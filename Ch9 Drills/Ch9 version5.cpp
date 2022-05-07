#include "std_lib_facilities.h"
using namespace std;

enum class Month {
 jan=1,feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
 vector<string> month_tbl = { "January", "February", "March", "April","May", "June", "July", "August", "September","October", "November", "December" };

 class Date {
 int y;
 Month m;
 int d;
public:
 Date(int y, Month m, int d); // check for valid date and initialize
 Month month() const{ return m; }
 int day() const{ return d; }
 int year() const{ return y; }

 bool is_valid();
 void add_day(int n); // non-const member: can modify the object
 void add_month(int n); // non-const member: can modify the object
 void add_year(int n); // non-const member: can modify the object
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
void Date::add_month(int n)
{
    //cout<<"int(m)= "<< int(m)<<endl; //you tested this to understand the enum class
    int month_count=0;
    month_count= int(m)+n;
    if(month_count>12)
    {
        y = y+(month_count/12);
        month_count=month_count%12;
    }
    switch(month_count)
    {
        case 1 : m=Month::jan;break;
        case 2 : m=Month::feb;break;
        case 3 : m=Month::mar;break;
        case 4 : m=Month::apr;break;
        case 5 : m=Month::may;break;
        case 6 : m=Month::jun;break;
        case 7 : m=Month::jul;break;
        case 8 : m=Month::aug;break;
        case 9 : m=Month::sep;break;
        case 10 : m=Month::oct;break;
        case 11 : m=Month::nov;break;
        case 12 : m=Month::dec;break;
        default: error("Something went wrong!");
    }
}
void Date::add_year(int n)
{
    y=y+n;
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
try{
Date today(1978,Month::jan,25);
Date tomorrow= today;
tomorrow.add_day(1);
tomorrow.add_month(24);
tomorrow.add_year(1);

cout<<"Today "<<today<<"Tomorrow "<<tomorrow<<endl;

//cout<< "Today:"<< endl<< "------------"<<endl<< "Year: "<<today.y<<endl<<"Month: "<< today.m<<endl<<"Day: "<<today.d<<endl<<"------------"<<endl;

//cout<< "Tomorrow:"<< endl<< "------------"<<endl<< "Year: "<<tomorrow.y<<endl<<"Month: "<< tomorrow.m<<endl<<"Day: "<<tomorrow.d<<endl<<"------------"<<endl;

cout<<"The invalid_date check:"<<endl;
Date invalid_date(2050,Month::jan,40);
}catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}

