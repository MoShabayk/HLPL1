/*
	The first working version of Stroustrup's calculator.
	Written by Renátó Besenczi based on the book BS, "Programming: Principles and Practice using C++, Second Edition"
	See chapter 6 and chapter 7 of book: https://stroustrup.com/programming.html
	© 2020 Renátó Besenczi, according to CC0. Questions: renato.besenczi@gmail.com
	Input from cin; output to cout. Input comes from cin through the Token_stream called ts.
	Grammar:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement
	Print:
		;
	Quit:
		q
	Statement:
		Declaration
		Expression
	Declaration:
		"let" Name "=" Expression
	Name:
		string literal
	Expression:
		Term
		Expression + Term
		Expression – Term
	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary:
		Number
		( Expression )
		– Primary
		+ Primary
	Number:
		floating-point-literal
*/

#include "std_lib_facilities.h"
// Some symbolic constants for clarity
constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = '#';
constexpr char result = '=';
constexpr char root ='r'; /*Declaring Token.kind for root*/
constexpr char power= 'p';
//constexpr string since C++20 only
const string rootkey= "root"; /*Declaring key for square root command*/
const string powerkey= "power";/*Declaring key for power command*/
const string quitkey= "exit";/*Declaring key for exit command*/

//function declarations
double expression();
double primary();
double term();
double declaration();
double statement();
double square_root();
double power_number();

// Variable ///////////////////////
class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;
bool is_declared(string var)
{
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}


double get_value(string s)
{
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
	return -1;
}

void set_value(string s, double d)
{
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
	error("set: undefined variable", s);
}
// Variable end ///////////////////////

// Token ///////////////////////
class Token {
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};
// Token end ///////////////////////

// Token_stream ///////////////////////
class Token_stream {
public:
	Token_stream();
	void putback(Token t);
	Token get();
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
		case print:
		case quit:
        case let:
        case ',': /* You added this cause the program gave you 'Bad Token' when you was using the power(x,y) function
                     as it cant get ',' in the token stream */
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback (ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default:
    	{
    		if (isalpha(ch))
    		{
    			string s;
    			s += ch;
    			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
    			cin.putback(ch);

                if(s== rootkey)
                    return Token{root};
                if(s== powerkey)
                    return Token{power};
                if(s==quitkey)
                    return Token{quit};

    			return Token{name,s};


    		}
    		error("Bad token");
    	}
    	return 0;
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}
// Token_stream end ///////////////////////
Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}

// Logically separate calculate() from the usual "boiler plate" of main
void calculate()
{
	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}
double square_root()
{

   double num=expression();
    if(num < 0){
        error("Can't Calculate root for a negative number");
        /*  8. Catch attempts to take the square root of a negative number and print an appropriate error message. */
    }
    return sqrt(num);
}
double power_number()
{
    Token t = ts.get();
    if(t.kind != '(') error(" '(' was expected");
    double base = expression();

    t = ts.get();
    if (t.kind != ',') error(" ',' was expected");

    int exponent = expression();

    t = ts.get();
    if(t.kind != ')')error("')' was expected");

    return pow(base,exponent);

}
int main()
try {

	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("K",1000); // 6. Add a predefined name k meaning 1000.

	calculate();

	return 0;

} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}

//Functions mapping grammar rules //////////////////////////
double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
        case name:  /* get the value of the name*/
            return get_value(t.name);
		default:
			error("primary expected");
	}
	return -1;
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error("%: divide by zero");
				left = fmod (left, d);
				t = ts.get();
				break;
				/* //or you can use narrow cast check
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2 == 0) error ("%: Zero oszto");
				left = i1 % i2;
				t = ts.get();
				break;
				*/
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}


double statement()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case let:
			return declaration();
        case root:
            return square_root();
        case power:
            return power_number();
		default:
			ts.putback(t);
			return expression();
	}
}

//Functions mapping grammar rules end //////////////////////////

// Program end!
