#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber {

private:

    MyBigNumber();


public:

    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray );
    MyBigNumber(const long & intNum );
    MyBigNumber &operator= ( const MyBigNumber myBigNumber);
    MyBigNumber ( const MyBigNumber & myBig );   // copy constructor
    MyBigNumber ( MyBigNumber && myBig ) noexcept;  // move constructor
    MyBigNumber & operator=(MyBigNumber && rightNum) noexcept ;   // move assignment overloading


};




#endif //TA14_MYBIGNUMBER_H
