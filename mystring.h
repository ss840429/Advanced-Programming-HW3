#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <iostream>
#include <cstring>

namespace mystr
{
    class String{
        friend std::ostream& operator <<( std::ostream& os , const String& str ) ;
        friend std::istream& operator >>( std::istream& is , String& str ) ;

        public :
            size_t size() const ;
            const char* c_str() const ;
            void clear() ;
            void swap ( std::string& str ) ;

            char& operator []( size_t idx ) ;
            const char& operator []( size_t idx ) const;

            String& operator += ( const String& str ) ;
            String& operator += ( const std::string& str ) ;
            String& operator += ( const char* str ) ;
            String& operator += ( const char c ) ;

            String& operator = ( const String& str ) ;
            String& operator = ( const std::string& str ) ;
            String& operator = ( const char* str ) ;
            String& operator = ( const char c ) ;

        private :
            char *str ;
            size_t size_ , capacity_ ;
    } ;
}

#endif  // MYSTRING_H
