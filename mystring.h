#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <iostream>
#include <cstring>

namespace mystr
{
    class String{

        public :
            String( const char* c_arr = "" ):size_(0),capacity_(0){
                if( strcmp( c_arr , "" ) ) {
                    capacity_ = size_ = strlen( c_arr ) ;
                }
                str_ = new char[capacity_+1]() ;    // for null character
                strcpy( str_ , c_arr ) ;
            }
            String( const String& str ):String(str.c_str()){}
            ~String(){
                delete[] str_ ;
                size_ = 0 , capacity_ = 0 ;
            }
            size_t size() const{ return size_ ; }
            const char* c_str() const{ return str_ ; }
            void clear() ;
            void swap ( String& str ) ;

            char& operator []( size_t idx ) ;
            const char& operator []( size_t idx ) const;

            String& operator += ( const String& str ) ;
            String& operator += ( char c ) ;
            String& operator = ( String str ) ;

        private :
            char *str_ ;
            size_t size_ , capacity_ ;
    } ;

    /***************** Non member function *****************/

    std::ostream& operator <<( std::ostream& os , const String& str ) ;
    std::istream& operator >>( std::istream& is ,       String& str ) ;
    bool operator < ( const String& lhs , const String& rhs ) ;
    bool operator > ( const String& lhs , const String& rhs ) ;
    bool operator <=( const String& lhs , const String& rhs ) ;
    bool operator >=( const String& lhs , const String& rhs ) ;
    bool operator !=( const String& lhs , const String& rhs ) ;
    bool operator ==( const String& lhs , const String& rhs ) ;
    String operator+( const String& lhs , const String& rhs ) ;
}

#endif  // MYSTRING_H
