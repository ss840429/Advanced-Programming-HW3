#include <iostream>
#include "mystring.h"

using namespace std ;
using namespace mystr ;


int main()
{
    cout << "/* Constructor */" << endl ;
    String s, t("CSIE"), u(t);
    cout << "s: " << s << "\tsize: " << s.size() << endl ;
    cout << "t: " << t << "\tsize: " << t.size() << endl ;
    cout << "u: " << u << "\tsize: " << u.size() << endl ;

    cout << endl << "/* Copy Assignment */" << endl ;
    s = "NTNU" ; t = t = t ; u = "106" ;
    cout << "s: " << s << "\tsize: " << s.size() << endl ;
    cout << "t: " << t << "\tsize: " << t.size() << endl ;
    cout << "u: " << u << "\tsize: " << u.size() << endl ;

    cout << endl << "/* Char array for C */" << endl ;
    const char* p = s.c_str() ;     // NTNU
    cout << "p: " << static_cast<const void*>(p) << "   " ;
    cout << p << endl ;
    cout << "s: " << static_cast<void*>(&s[0]) << "   " ;
    cout << s << endl ;

    cout << endl << "/* Operator [] */" << endl ;
    const String s1("Taiwan #1") ;
    for( int i = 0 ; s1[i] ; i ++ ) cout << s1[i] << " " ;
    cout << endl ;
    /* Error */
    // s1 = "China" ;
    // s1[0] = 'Z' ;    // Read Only

    cout << endl << "/* Operator += */" << endl ;
    s = "NTNU" , t = "CSIE" , u = "106" ;
    ((s += t) += u) += " No#1" ;  // NTNU + CSIE + 106 + No#1
    cout << "s: " << s << "\tsize: " << s.size() << endl ;
    cout << "t: " << t << "\tsize: " << t.size() << endl ;
    cout << "u: " << u << "\tsize: " << u.size() << endl ;

    cout << endl << "/* Operator + */" << endl ;
    const String first( "telnet.csie" ) , second( ".ntnu.edu" ) ;
    cout << first + second + ".tw" << endl ;

    cout << endl << "/* Clear */" << endl ;
    s = "NTNU" ;
    cout << "s: " << s << "\tsize: " << s.size() << endl ;
    s.clear() ;
    cout << "s: " << s << "\tsize: " << s.size() << endl ;
    s += 'A' ;
    cout << "s: " << s << "\tsize: " << s.size() << endl ;

    cout << endl << "/* Swap */" << endl ;
    cout << "s: " << s << "\tsize: " << s.size() << endl ;
    cout << "t: " << t << "\tsize: " << t.size() << endl ;
    s.swap(t) ;
    cout << "s: " << s << "\tsize: " << s.size() << endl ;
    cout << "t: " << t << "\tsize: " << t.size() << endl ;

    cout << endl << "/* Relational Operator */" << endl ;
    s = "NTNU" , t = "CSIE" , u = "106" ;
    cout << ( s == "NTNU" ) << ( t != t ) << ( s<t )
            << ( s>"A" ) << ( t <= "CSIE" ) << (t >= "CSIF" ) ;
            /* 100110 */

    cout << endl << endl << "End" ;

    cin >> s >> t ;

    return 0;
}
