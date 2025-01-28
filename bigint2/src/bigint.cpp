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

// comparison greater than equal to
bool BigInt::operator>=(const BigInt& i2) const {
    return !(*this < i2);
}

// comparison less than
bool BigInt::operator<(const BigInt& i2) const{
    if(!negative && i2.negative) return false;
    if(negative &&!i2.negative) return true;

    if(digits.size() > i2.digits.size()) return negative ? true : false;
    if(digits.size() < i2.digits.size()) return negative ? false : true;
    for (int i = 0; i < digits.size(); i++){
        if (digits[i] > i2.digits[i]) return negative ? true : false;
    }
    return false;
}
//comparison less than equal to
bool BigInt::operator<=(const BigInt& other) const {
    return !(*this > other);
}

//mutliplication
BigInt BigInt::operator*(const BigInt& i2) const{

    bool neg_result = this->negative != i2.negative;
    string r(this->digits.size() + i2.digits.size(), '0');

    for (int i =this->digits.size() -1; i>=0; i--){
        int c = 0;
        for (int j = i2.digits.size() -1; j >=0; j--){
            int prod = (this->digits[i] - '0') * (i2.digits[j]-'0') + (r[i+j+1]-'0') + c;
            c = prod/10;
            r[i+j+1] = (prod%10) + '0';
        }
        r[i] += c;
    }
    size_t starting_position = r.find_first_not_of('0');
    if (starting_position != string::npos) r = r.substr(starting_position);
    else r = "0";

    if (neg_result && r != "0") r.insert(r.begin(), '-');
    return BigInt(r);

}

//addition
BigInt BigInt::operator+(const BigInt& i) const {
    if (negative != i.negative) {
        return *this + BigInt(i.negative ? i.digits : "-" + i.digits);
    }

    bool resultNegative = false;
    string a = digits, b = i.digits;

    if (*this > i) {
        swap(a, b);
        resultNegative = !negative;
    } else {
        resultNegative = negative;
    }


   string result = "";
   string a = digits;
   string b = i.digits;


   int carry = 0;
   int i = a.size() - 1, j = b.size() - 1;


   while (i >= 0 || j >= 0 || carry) {
       int digitA = (i >= 0) ? a[i--] - '0' : 0;
       int digitB = (j >= 0) ? b[j--] - '0' : 0;


       int sum = digitA + digitB + carry;
       carry = sum / 10;
       result.insert(result.begin(), (sum % 10) + '0');
   }


   return BigInt(result);
}
//subtraction
BigInt BigInt::operator-(const BigInt& i) const {
    if (negative != i.negative) {
        return *this + BigInt(i.negative ? i.digits : "-" + i.digits);
    }

    bool resultNegative = false;
    string a = digits, b = i.digits;

    if (*this < other) {
        swap(a, b);
        resultNegative = !negative;
    } else {
        resultNegative = negative;
    }

    string result = "";
    int borrow = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0) {
        int digitA = (i >= 0) ? a[i--] - '0' : 0;
        int digitB = (j >= 0) ? b[j--] - '0' : 0;

        int diff = digitA - digitB - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.insert(result.begin(), diff + '0');
    }

    while (result.size() > 1 && result.front() == '0') {
        result.erase(result.begin());
    }

    return BigInt(resultNegative ? "-" + result : result);
}

