#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "BigInt.h"
using namespace std;

TEST_CASE("Test can create and render BigInts") {
    BigInt bi;
    CHECK(bi.to_string() == "0");
    BigInt bi2(42);
    CHECK(bi2.to_string() == "42");
    BigInt bi3(-42);
    CHECK(bi3.to_string() == "-42");
    BigInt bi4("123456789012345678901234567890");
    CHECK(bi4.to_string() == "123456789012345678901234567890");
    BigInt bi5("-923456789012345678901234567890");
    CHECK(bi5.to_string() == "-923456789012345678901234567890");
}

TEST_CASE("Test can compare BigInts for equality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 == i5) == true);
    CHECK((i1 == i2) == false);
    CHECK((i1 == i3) == false);
    CHECK((i2 == i6) == false);
}

TEST_CASE("Test can compare BigInts for inequality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 > i5) == false);
    CHECK((i2 > i1) == true);
    CHECK((i4 > i1) == false);
    CHECK((i6 > i4) == true);
}

TEST_CASE("Test can compare BigInts with !=, <=, <, and <=") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i4 != i1) == true);
    CHECK((i2 <= i5) == true);
    CHECK((i2 < i1) == false);
    CHECK((i6 >= i4) == true);
}

TEST_CASE("Test can add BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("9999");
    BigInt i5("1");
    BigInt i6("-9999");
    BigInt i7("765432");
    BigInt i8("87654321");

    CHECK((i1 + i2).to_string() == "444");
    CHECK((i1 + i3).to_string() == "43333");
    CHECK((i4 + i5).to_string() == "10000");
    CHECK((i7 + i8).to_string() == "88419753");
}

TEST_CASE("NEGATION TESTING") {
    BigInt b1("52");
    BigInt b2 = -b1;
    BigInt b3("765");
    BigInt b4("-765");

    CHECK(b2.to_string() == "-52");
    CHECK((-b2).to_string() == "52");
    CHECK((-b3).to_string() == "-765");
    CHECK((-b4).to_string() == "765");
}

TEST_CASE("SUBTRACTION TESTING") {
    BigInt b1("1600");
    BigInt b2("1500");
    BigInt b3("654321");
    BigInt b4("65");
    BigInt b5("9999");
    BigInt b6("8888");

    CHECK((b1 - b2).to_string() == "100");
    CHECK((b3 - b4).to_string() == "654256");
    CHECK((b5 - b6).to_string() == "1111");
}

TEST_CASE("MULTIPLICATION TESTING") {
    BigInt b1("12");
    BigInt b2("34");
    BigInt b3("-56");
    BigInt b4("999");
    BigInt b5("-999");

    CHECK((b1 * b2).to_string() == "408");
    CHECK((b2 * b3).to_string() == "-1904");
    CHECK((b1 * b3).to_string() == "-672");
    CHECK((b4 * b5).to_string() == "-998001");
    CHECK((b4 * b4).to_string() == "998001");
}


