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
        while( ch = getchar() ){
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
        if( capacity_ > 0 ) str_[0] = '\0' ;
    }
    void String::swap ( String& str ){
        std::swap( str.str_ , str_ ) ;
        std::swap( str.capacity_ , capacity_ ) ;
        std::swap( str.size_ , size_ ) ;
    }
    char& String::operator []( size_t idx ) {
        return const_cast<char&>( static_cast<const String&>(*this)[idx] ) ;
    }
    const char& String::operator []( size_t idx ) const{
        return str_[idx] ;
    }
    String& String::operator += ( const String& str ){
        if( (*this).size_+str.size_ >= (*this).capacity_ ){
            char* newstr = new char[(*this).size_+str.size_+1]() ;
            (*this).size_ = (*this).size_+str.size_ ;
            (*this).capacity_ = (*this).size_+1 ;
            strcpy( newstr , (*this).str_ ) ;
            strcat( newstr , str.str_ ) ;
            delete[] (*this).str_ ;
            (*this).str_ = newstr ;
        }
        else
            strcat( (*this).str_ , str.str_ ) ;
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
        return strcmp( lhs.c_str() , rhs.c_str() ) < 0 ;
    }
    bool operator > ( const String& lhs , const String& rhs ){
        return strcmp( lhs.c_str() , rhs.c_str() ) > 0 ;
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

