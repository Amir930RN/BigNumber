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


MyBigNumber MyBigNumber::multByOneDigit(const int input) {

    MyBigNumber result;


    if ( input==0 ) {

        result.sign = true;
        result.numOfDigits = 1;
        result.numArray = new int8_t[1];
        result.numArray[0] = 0;
        return result;

    }

    result.sign = (input > 0 && sign) || (input < 0 && !sign);

    int myInput = abs(input);

    result.numOfDigits = numOfDigits + 1;
    result.numArray = new int8_t[result.numOfDigits];
    size_t i{0};
    int8_t carry = 0;
    int8_t s;
    for (; i < numOfDigits; ++i) {
        s = myInput * numArray[i] + carry;
        result[i] = s % 10;
        carry = s / 10;
    }


    if (carry !=0) {
        result[i] = carry;
    }
    else {
        //result[i] = 0;
        result.numOfDigits -= 1;
    }

    return result;
    
}

MyBigNumber operator*(const MyBigNumber &num1, const MyBigNumber &num2) {

    MyBigNumber result;


    if ( ( num1.getNumOfDigits()==1 && num1.numArray[0]==0 ) || ( num2.getNumOfDigits()==1 && num2.numArray[0]==0 ) ){

        result.sign = true;
        result.numOfDigits = 1;
        result.numArray = new int8_t[1];
        result.numArray[0]=0;
        return result;
    }

    result.sign = (  (num1.sign && num2.sign) || (  !num1.sign && !num2.sign ) );

    MyBigNumber myNum2 = num2;

    unsigned s=0;

    BigNumber r{"0"};

    for (int i = 0; i < num1.numOfDigits ; ++i) {

        r=r+ ( ( (myNum2<<s).multByOneDigit(num1[i]) ) );
        s++;
    }

    result.numOfDigits = r.getNumOfDigits();
    result.numArray = new int8_t[result.numOfDigits];
    for (int i = 0; i < result.numOfDigits ; ++i) {
        result.numArray[i] = r.getA(i);
    }

    return result;


}

MyBigNumber MyBigNumber:: operator<<( unsigned shift ){

    MyBigNumber temp;

    if( shift==0 ) {
        return *this;
    }
    else{
        temp.sign = sign;
        temp.numOfDigits = numOfDigits + shift;
        temp.numArray = new int8_t[temp.numOfDigits];

        for (int i = 0; i < shift ; ++i) {
            temp.numArray[i] = 0;
        }

        for (int i = (int) shift; i < temp.numOfDigits ; ++i) {
            temp.numArray[i] = numArray[i-shift];
        }
    }
    return temp;
}

MyBigNumber MyBigNumber::power(const MyBigNumber &big, unsigned power) {

    MyBigNumber result = big;

    for (int i = 0; i < power -1 ; ++i) {

        const MyBigNumber b = result * big;

        result = b;

    }

    return result;



}




