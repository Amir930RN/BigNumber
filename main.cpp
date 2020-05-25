#include <iostream>
#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {




    BigNumber n1 = 120;
    BigNumber n2 = 117;


/* operator -- and ++ post and pre tests */


    //operator-- pre test
    BigNumber n3 = --n1;
    cout<<n1<<" "<<n3<<endl;

    //operator-- post test
    n1--;
    cout<<n1<<endl;

    //operator++ post test
    n1++;
    cout<<n1<<endl;

    //operator++ pre test
    n3 = ++n1;
    cout<<n1<<" "<<n3<<endl;


    MyBigNumber b1 = 123;
    MyBigNumber b2 = 122;

    cout<<b1-b2<<endl;


    //multy func test

    cout<<b1.multByOneDigit(9)<<endl;


    //operator<< test

    MyBigNumber b4 = b1<<5;

    cout<<b4<<endl;

    //operator* test

    MyBigNumber b5 = 123;
    MyBigNumber b6 = 122;
    cout<<b5*b6<<endl;

    //function power test
    cout<<MyBigNumber::power(b1,2)<<endl;
    cout<<MyBigNumber::power(b1,3)<<endl;


    //operator () test
    BigNumber b7 = 15728839;
    cout<<b7(6,3)<<endl;
    cout<<b7(7,4)<<endl;
    cout<<b7(1,2)<<endl;
    cout<<b7(1,1)<<endl;




    return 0;
}
