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
            String():size_(0),capacity_(1){
                str = new char[capacity_]() ;
                str[0] = '\0' ;
            }
            ~String(){
                delete[] str ;
                size_ = 0 , capacity_ = 0 ;
            }
            size_t size() const {
                return size_ ;
            }
            const char* c_str() const {
                return str ;
            }
            void clear() {
                size_ = 0 ;
            }
            void swap ( String& str ) ;

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
