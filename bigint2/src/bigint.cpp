#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const
{
    return (!negative) ? digits : "-" + digits;
}
//comparison ==
bool BigInt::operator==(const BigInt& i2) const{
    if (digits.size() != i2.digits.size()) return false; //simple command which returns false when teh size is different
    if (negative != i2.negative) return false;
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] != i2.digits[i]){
            return false;
        }
    }
    return true;
}
//comparison greater than
bool BigInt::operator>(const BigInt& i2) const{
    if(!negative && i2.negative) return true; 
    if(negative && !i2.negative) return false;
    
     if (digits.size() < i2.digits.size()) {
        return negative ? true : false;
    }
   if(digits.size() > i2.digits.size()){
        return negative ? false : true;
    }
    
    for(int i = 0; i < digits.size(); i++){
        if (digits[i] > i2.digits[i]){
            return negative ? false : true; 
        }
    } 
    return false;
}

// not equal
bool BigInt::operator!=(const BigInt& i2) const {
    return !(*this == i2);
}

// comparison greater than or equal to
bool BigInt::operator>=(const BigInt& i2) const {
    return !(*this < i2);
}

// comparison less than
bool BigInt::operator<(const BigInt& i2) const{
    if(!negative && i2.negative) return false;
    if(negative &&!i2.negative) return true;
