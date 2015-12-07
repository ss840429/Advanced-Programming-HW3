#include "mystring.h"
#include <iostream>
#include <cstring>

using namespace std ;
using namespace mystr ;

namespace mystr
{
    ostream& operator <<( ostream& os , const String& str ) {
        for( int i = 0 ; i < str.size() ; ++i )
            cout << str[i];
        return os ;
    }
    /*
        istream
    */
    char& String::operator []( size_t idx ) {
        return const_cast<char&>( static_cast<const String&>(*this)[idx] ) ;
    }
    const char& String::operator []( size_t idx ) const{
        return str_[idx] ;
    }




}

