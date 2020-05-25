#include "MyBigNumber.h"

using namespace std;

MyBigNumber::MyBigNumber(const std::string &str) : BigNumber(str) {}

MyBigNumber::MyBigNumber(const long &intNum) : BigNumber(intNum) {}

MyBigNumber::MyBigNumber(const char *myCharArray) : BigNumber((std::string) myCharArray) {}

MyBigNumber &MyBigNumber::operator=(const MyBigNumber myBigNumber) {

    if ( &myBigNumber != this ){
        sign = myBigNumber.sign;
        numOfDigits = myBigNumber.numOfDigits;
        delete [] numArray;
        numArray = new int8_t[numOfDigits];
        for(size_t i{0}; i < numOfDigits; ++i){
            numArray[i] = myBigNumber.numArray[i];
        }
    }
    return *this;
}

MyBigNumber & MyBigNumber:: operator=( MyBigNumber && rightNum) noexcept {

    if( &rightNum != this ){
        sign = rightNum.sign;
        numOfDigits = rightNum.numOfDigits;
        delete [] numArray;
        numArray = rightNum.numArray;
        rightNum.numArray = nullptr;
    }
    return *this;

}

MyBigNumber::MyBigNumber ( const MyBigNumber & myBig ){
    sign = myBig.sign;
    numOfDigits = myBig.numOfDigits;
    numArray = new int8_t[numOfDigits];
    for(size_t i{0}; i < numOfDigits; ++i){
        numArray[i] = myBig.numArray[i];
    }
}

MyBigNumber::MyBigNumber ( MyBigNumber && myBig ) noexcept
{
    sign = myBig.sign;
    numOfDigits = myBig.numOfDigits;
    numArray  = myBig.numArray;
    myBig.numArray = nullptr;
}
