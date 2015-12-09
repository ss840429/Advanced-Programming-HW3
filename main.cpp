#include <iostream>
#include "mystring.h"

using namespace std ;
using namespace mystr ;

int main()
{
    mystr::String str("123") , str1("123");

    cin >> str1 ;
    cout << (str == "123") << "   " << (str1 != "123" ) ;

    return 0 ;
}
