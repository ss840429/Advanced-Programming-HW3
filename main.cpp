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
    String s("yoyo") ;
    cout << s << endl ;
    s += "234567" ;
    cout << s << endl ;
    s += s ;
    cout << s << endl ;



    return 0;
}
