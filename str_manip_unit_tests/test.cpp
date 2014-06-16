#include <gtest/gtest.h>

#include "my_string.h"


TEST(Constructors, EmptyConstructor) {
    mnp::string str;
    EXPECT_EQ(0, str.size());
}

TEST(Constructors, EmptyStdString) {
    std::string std_str = "";
    mnp::string str(std_str);
    EXPECT_EQ(0, str.size());
}

TEST(Constructors, StdString) {
    std::string std_str = "Some String";
    mnp::string str(std_str);
    EXPECT_EQ(11, str.size());
}

TEST(Constructors, EmptyCStyleString) {
    mnp::string str("");
    EXPECT_EQ(0, str.size());
}

TEST(Constructors, CStyleString) {
    mnp::string str("Some String");
    EXPECT_EQ(11, str.size());
}

TEST(Constructors, EmptyMnpString) {
    mnp::string mnp_str;
    mnp::string str(mnp_str);
    EXPECT_EQ(0, str.size());
}

TEST(Constructors, MnpString) {
    mnp::string mnp_str("Some String");
    mnp::string str(mnp_str);
    EXPECT_EQ(11, str.size());
}

TEST(Assignment, CStyleString) {
    mnp::string str;
    str = "Some String";
    EXPECT_EQ(11, str.size());
}

TEST(CStyleString, WhenEmpty) {
    mnp::string str;
    char expected[] = {'\0'};
    char actual[1];
    size_t size = str.c_str(actual);
    
    EXPECT_EQ(0, size);
    EXPECT_STREQ(expected, actual);
}

TEST(CStyleString, WhenNotEmpty) {
    char expected[] = "Some String";
    mnp::string str = expected;
    
    char actual[12];
    size_t size = str.c_str(actual);
    
    EXPECT_EQ(11, size);
    EXPECT_STREQ(expected, actual);
}