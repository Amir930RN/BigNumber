#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber {


    friend MyBigNumber operator*( const MyBigNumber & num1, const MyBigNumber & num2);

private:

    MyBigNumber(){};





public:

    //must be private
    MyBigNumber multByOneDigit ( const int input );

    //end of private



    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray );
    MyBigNumber(const long & intNum );
    MyBigNumber &operator= ( const MyBigNumber myBigNumber);
    MyBigNumber ( const MyBigNumber & myBig );   // copy constructor
    MyBigNumber ( MyBigNumber && myBig ) noexcept;  // move constructor
    MyBigNumber & operator=(MyBigNumber && rightNum) noexcept ;   // move assignment overloading


    MyBigNumber operator<<( unsigned shift );

    static MyBigNumber power (const MyBigNumber & big, unsigned power);




};




#endif //TA14_MYBIGNUMBER_H
