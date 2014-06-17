#include <gtest/gtest.h>
#include "mnp_string.h"

TEST(Find, Null) {
    mnp::string str("Some String");
    size_t actual = str.find(NULL);
    EXPECT_EQ(-1, actual);
}

TEST(Find, CStyleStringEmpty) {
    mnp::string str("SomeStr String");
    size_t actual = str.find("");
    EXPECT_EQ(0, actual);
}

TEST(Find, CStyleStringMultipleChars) {
    mnp::string str("SomeStr String");
    size_t actual = str.find("Str");
    EXPECT_EQ(4, actual);
}

TEST(Find, CStyleStringSingleChar) {
    const mnp::string str("SomeStr String");
    size_t actual = str.find("S");
    EXPECT_EQ(0, actual);
}

TEST(Find, StdStringEmpty) {
    mnp::string str("SomeStr String");
    std::string std_str = "";
    size_t actual = str.find(std_str);
    EXPECT_EQ(0, actual);
}

TEST(Find, StdStringMultipleChars) {
    mnp::string str("SomeStr String");
    std::string std_str = "Str";
    size_t actual = str.find(std_str);
    EXPECT_EQ(4, actual);
}

TEST(Find, StdStringSingleChar) {
    const mnp::string str("SomeStr String");
    std::string std_str = "S";
    size_t actual = str.find(std_str);
    EXPECT_EQ(0, actual);
}

TEST(Find, MnpStringEmpty) {
    mnp::string str("SomeStr String");
    mnp::string mnp_str = "";
    size_t actual = str.find(mnp_str);
    EXPECT_EQ(0, actual);
}

TEST(Find, MnpStringMultipleChars) {
    mnp::string str("SomeStr String");
    mnp::string mnp_str = "Str";
    size_t actual = str.find(mnp_str);
    EXPECT_EQ(4, actual);
}

TEST(Find, MnpStringSingleChar) {
    const mnp::string str("SomeStr String");
    mnp::string mnp_str = "S";
    size_t actual = str.find(mnp_str);
    EXPECT_EQ(0, actual);
}