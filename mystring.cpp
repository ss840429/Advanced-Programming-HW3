#include "mystring.h"
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std ;
using namespace mystr ;

namespace mystr
{
    ostream& operator <<( ostream& os , const String& str ) {
        for( size_t i = 0 ; i < str.size() ; ++i )
            os << str[i];
        return os ;
    }
    istream& operator >>( istream& is , String& str ){
        str.clear() ;
        char ch = '\0' ; int textcount = 0 ;
        while( ch = getchar() )
        {
            if( ( ch == ' ' || ch == '\n' ) && textcount > 0 ) break ;
            if( ch != ' ' && ch != '\n' ){
                textcount += 1 ;
                str += ch ;
            }
        }
        return is ;
    }
    void String::clear() {
        size_ = 0 ;
        strcpy( str_ , "" ) ;
    }
    void String::swap ( String& str ){
        using std::swap ;
        swap( str.str_ , str_ ) ;
        swap( str.capacity_ , capacity_ ) ;
        swap( str.size_ , size_ ) ;
    }
    char& String::operator []( size_t idx ) {
        return const_cast<char&>( static_cast<const String&>(*this)[idx] ) ;
    }
    const char& String::operator []( size_t idx ) const{
        return str_[idx] ;
    }
    String& String::operator += ( const String& str ){
        int length = size_ + str.size_ ;
        if( length > capacity_ ){
            char* newstr = new char[length+1]() ;
            capacity_ = size_ = length ;
            strcpy( newstr , str_ ) ;
            strcat( newstr , str.str_ ) ;
            delete[] str_ ;
            str_ = newstr ;
        }
        else {
            strcat( str_ , str.str_ ) ;
        }
        return *this ;
    }
    String& String::operator += ( char c ) {
        char tmp[] = { c , '\0' } ;
        (*this) += String(tmp) ;
        return *this ;
    }
    String& String::operator = ( String str ) {
        this->swap(str) ;
        return *this ;
    }

    /***************** Non member function *****************/

    bool operator < ( const String& lhs , const String& rhs ){
        return ( strcmp( lhs.c_str() , rhs.c_str() ) < 0 ) ;
    }
    bool operator > ( const String& lhs , const String& rhs ){
        return ( strcmp( lhs.c_str() , rhs.c_str() ) > 0 ) ;
    }
    bool operator <=( const String& lhs , const String& rhs ){
        return !(lhs>rhs) ;
    }
    bool operator >=( const String& lhs , const String& rhs ){
        return !(lhs<rhs) ;
    }
    bool operator !=( const String& lhs , const String& rhs ){
        return (lhs<rhs||lhs>rhs) ;
    }
    bool operator ==( const String& lhs , const String& rhs ){
        return !(lhs!=rhs) ;
    }
    String operator + ( const String& lhs , const String& rhs  ){
        String str( lhs ) ;
        str += rhs ;
        return str ;
    }
}

