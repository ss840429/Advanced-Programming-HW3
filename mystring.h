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


        private :
            char *str ;
            size_t size_ , capacity_ ;
    }
}

#endif  // MYSTRING_H
