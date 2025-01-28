#include <string>
using namespace std;

class BigInt
{
    bool negative;
    string digits;

    public:
    // constructors
    BigInt();
    BigInt(int);
    BigInt(string);

    // member functions
    string to_string() const;
    
    //comparisons 
    bool operator==(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    bool operator<=(const BigInt&) const;
    bool operator<(const BigInt&) const;
    bool operator>=(const BigInt&) const;
    

    //operations
    BigInt operator+(const BigInt& b2) const;
    BigInt operator-() const;
    BigInt operator-(const BigInt &b2) const ;
    BigInt operator*(const BigInt &b2) const;

};
