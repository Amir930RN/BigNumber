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
