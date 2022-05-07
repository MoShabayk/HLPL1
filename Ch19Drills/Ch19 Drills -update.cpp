#include "std_lib_facilities.h"

template<typename T>
struct s  // 1. Define template<typename T> struct S { T val; };.
{
   private:  //7. Make val private.
        T val;
   public:
    s& operator=(const T&);
    // 2. Add a constructor, so that you can initialize with a T.
    s(T newValue)
    {
        val = newValue;
    }
    // 9. Add a set() function template so that you can change val
    void set(T newValue)
    {
    val = newValue;
    }

    s<T> &operator=(s<T> &value);

// 5. Add a function template get() that returns a reference to val.
    T& get();
// 11. Provide const and non-const versions of get().
    const T& get() const;
};

// 6. Put the definition of get() outside the class.
template<typename T>
T& s<T>::get()
{
    return val;
}

template<typename T>
const T& s<T>::get()const
{
    return val;
}

// 10. Replace set() with an S<T>::operator=(const T&).
template<typename T>
s<T>& s<T>::operator=(const T& value)
{
    val = value;
    return *this; /* refers to the struct you've made */
}

/*14. Bonus: Define input and output operators (>> and <<) for vector<T>s.
For both input and output use a { val, val, val } format. That will allow
read_val() to also handle the S<vector<int>> variable. */
template<typename T>
ostream& operator <<(ostream& output , vector<T> vec)
{
    output << "{";
    for(int i =0;i<vec.size();i++)
    {
        output<< vec[i];
        if(i< vec.size()-1)
            output<< ",";
    }
    output << "}";

    return output;
}

template<typename T>
istream& operator>>(istream& input, vector<T>& v)
{
    char ch = 0;
    input >> ch;
    if (ch != '{') {
        error(" '{' was expected");
        return input;
    }
    for (T val; input >> val; ) {
        v.push_back(val);
        input >> ch;
        if (ch != ',') break;
    }
    return input;
    }

// 12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
template<typename T>
void read_val(T& v)
{
    cin >> v;
}

int main()
{
    int int_test;
    double double_test;
    string string_test;
    char char_test;
    /*3. Define variables of types S<int>, S<char>, S<double>, S<string>, and
S<vector<int>>; initialize them with values of your choice. */
 // 4. Read those values and print them
   //cout<< num.val<< endl<< num2.val<<endl <<word.val<<endl<< letter.val<<endl;

/*13. Use read_val() to read into each of the variables from 3 except the
S<vector<int>> variable. */
    read_val(int_test);
    read_val(double_test);
    read_val(string_test);
    read_val(char_test);

    s<int> num{int_test};
    s<double> num2{double_test};
    s<string> word{string_test};
    s<char> letter{char_test};

    // 8. Do 4 again using get().
   cout<<num.get()<<endl<< num2.get()<<endl<<word.get()<<endl<<letter.get()<<endl;

    cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    vector<int> vi2;
    read_val(vi2);
    s<vector<int>> svi2 {vi2};

    cout << "S<vector<int>> read: " << svi2.get() << '\n';
   /* for(int i=0;i<vec.val.size();i++)
   cout <<vec.val[i]; */
return 0;
}
