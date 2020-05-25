#include "MyBigNumber.h"

using namespace std;

MyBigNumber::MyBigNumber(const std::string &str) : BigNumber(str) {}

MyBigNumber::MyBigNumber(const long &intNum) : BigNumber(intNum) {}

MyBigNumber::MyBigNumber(const char *myCharArray) : BigNumber((std::string) myCharArray) {}
