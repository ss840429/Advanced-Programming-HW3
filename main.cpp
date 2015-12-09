#include <iostream>
#include "mystring.h"

using namespace std ;
using namespace mystr ;

void check(const string &s)
{
    int **p = (int **)&s;
    cout << *(*p-3) << ' ' // size
         << *(*p-2) << ' ' // capacity
         << *(*p-1) << endl; // reference count
}
int main ()
{
    string s("tcchiang");
    int a;
    cout << &s << ' ' << &a << endl;
    cout << (void *)&s[0] << ' ' << (void *)s.c_str() << endl;
    cout << sizeof(s) << endl;
    cout << s.size() << ' ' << s.capacity() << endl;
    s = "ntnu";
    cout << s.size() << ' ' << s.capacity() << endl;
    check(s);
    s = "iloventnu";
    cout << s.size() << ' ' << s.capacity() << endl;
    check(s);

    cout << endl << endl ;

    string s1("tcchiang"); check(s1);
    string t = s1, u = s1;
    check(s1); check(t); check(u);
    cout << (void *)s1.c_str() << ' ' << (void *)t.c_str() << ' ' << (void *)u.c_str() << endl;
    t = "new";
    check(s1); check(t); check(u);
    s = "kk1234";
    check(s1); check(t); check(u);


    return 0;
}
