#include <gtest/gtest.h>
#include "my_string.h"

TEST(Count, Null) {
    mnp::string str("Some String");
    size_t actual = str.count(NULL);
    EXPECT_EQ(0, actual);
}

TEST(Count, CStyleStringEmpty) {
    mnp::string str("SomeStr String");
    size_t actual = str.count("");
    EXPECT_EQ(15, actual);
}

TEST(Count, CStyleStringMultipleChars) {
    mnp::string str("SomeStr String");
    size_t actual = str.count("Str");
    EXPECT_EQ(2, actual);
}

TEST(Count, CStyleStringSingleChar) {
    const mnp::string str("SomeStr String");
    size_t actual = str.count("S");
    EXPECT_EQ(3, actual);
}

TEST(Count, StdStringEmpty) {
    mnp::string str("SomeStr String");
    std::string std_str = "";
    size_t actual = str.count(std_str);
    EXPECT_EQ(15, actual);
}

TEST(Count, StdStringMultipleChars) {
    mnp::string str("SomeStr String");
    std::string std_str = "Str";
    size_t actual = str.count(std_str);
    EXPECT_EQ(2, actual);
}

TEST(Count, StdStringSingleChar) {
    const mnp::string str("SomeStr String");
    std::string std_str = "S";
    size_t actual = str.count(std_str);
    EXPECT_EQ(3, actual);
}

TEST(Count, MnpStringEmpty) {
    mnp::string str("SomeStr String");
    mnp::string mnp_str = "";
    size_t actual = str.count(mnp_str);
    EXPECT_EQ(15, actual);
}

TEST(Count, MnpStringMultipleChars) {
    mnp::string str("SomeStr String");
    mnp::string mnp_str = "Str";
    size_t actual = str.count(mnp_str);
    EXPECT_EQ(2, actual);
}

TEST(Count, MnpStringSingleChar) {
    const mnp::string str("SomeStr String");
    mnp::string mnp_str = "S";
    size_t actual = str.count(mnp_str);
    EXPECT_EQ(3, actual);
}