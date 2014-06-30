#include <gtest/gtest.h>
#include "mnp_string.h"
#include "test_fixture.h"

class SubstrTest: public CommonTest {};

TEST_F(SubstrTest, EmptyStringThrowsOutOfRange) {
    EXPECT_THROW(empty_str.substr(0, 0), std::out_of_range);
}


TEST_F(SubstrTest, SingleCharFromShortString) {
    mnp::string sub_str = short_str.substr(3, 4);
    sub_str.c_str(buff);
    EXPECT_EQ(short_str_c[3], buff[0]);
    EXPECT_EQ(0, buff[1]);
}

TEST_F(SubstrTest, SingleCharFromLongString) {
    mnp::string sub_str = long_str.substr(3, 4);
    sub_str.c_str(buff);
    EXPECT_EQ(long_str_c[3], buff[0]);
    EXPECT_EQ('\0', buff[1]);
}

TEST_F(SubstrTest, MultiCharInMiddleFromShortString) {
    mnp::string sub_str = short_str.substr(3, 5);
    sub_str.c_str(buff);
    EXPECT_EQ(short_str_c[3], buff[0]);
    EXPECT_EQ(short_str_c[4], buff[1]);
    EXPECT_EQ('\0', buff[2]);
}

TEST_F(SubstrTest, MultiCharInMiddleFromLongString) {
    mnp::string sub_str = long_str.substr(15, 17);
    sub_str.c_str(buff);
    EXPECT_EQ(long_str_c[15], buff[0]);
    EXPECT_EQ(long_str_c[16], buff[1]);
    EXPECT_EQ('\0', buff[2]);
}

TEST_F(SubstrTest, MultiCharTillEndFromShortString) {
    mnp::string sub_str = short_str.substr(9, 11);
    sub_str.c_str(buff);
    EXPECT_EQ(short_str_c[9], buff[0]);
    EXPECT_EQ(short_str_c[10], buff[1]);
    EXPECT_EQ('\0', buff[2]);
}

TEST_F(SubstrTest, MultiCharTillEndFromLongString) {
    mnp::string sub_str = long_str.substr(long_str.size() - 2, long_str.size());
    sub_str.c_str(buff);
    EXPECT_EQ(long_str_c[long_str.size() - 2], buff[0]);
    EXPECT_EQ(long_str_c[long_str.size() - 1], buff[1]);
    EXPECT_EQ('\0', buff[2]);
}

TEST_F(SubstrTest, WholeStringFromShortString) {
    mnp::string sub_str = short_str.substr(0, short_str.size());
    sub_str.c_str(buff);
    EXPECT_STREQ(short_str_c, buff);
}

TEST_F(SubstrTest, WholeStringFromLongString) {
    mnp::string sub_str = long_str.substr(0, long_str.size());
    sub_str.c_str(buff);
    EXPECT_STREQ(long_str_c, buff);
}

TEST_F(SubstrTest, ReverseFromShortString) {
    mnp::string sub_str = short_str.substr(2,0);
    sub_str.c_str(buff);
    EXPECT_EQ(short_str_c[2], buff[0]);
    EXPECT_EQ(short_str_c[1], buff[1]);
    EXPECT_EQ('\0', buff[2]);
}

TEST_F(SubstrTest, ReverseFromLongString) {
    mnp::string sub_str = long_str.substr(2,0);
    sub_str.c_str(buff);
    EXPECT_EQ(long_str_c[2], buff[0]);
    EXPECT_EQ(long_str_c[1], buff[1]);
    EXPECT_EQ('\0', buff[2]);
}

TEST_F(SubstrTest, NegativeIndices) {
    mnp::string sub_str = short_str.substr(-3, -1);
    sub_str.c_str(buff);
    EXPECT_EQ(short_str_c[8], buff[0]);
    EXPECT_EQ(short_str_c[9], buff[1]);
    EXPECT_EQ('\0', buff[2]);
}

TEST_F(SubstrTest, LongSubstrFromLongStringIsRef) {
    mnp::string sub_str = long_str.substr(10, 40);
    EXPECT_EQ(long_str.data(), sub_str.data() - 10);
}

TEST_F(SubstrTest, SubstrFromShortStringIsCopy) {
    mnp::string sub_str = short_str.substr(3, 6);
    EXPECT_NE(short_str.data(), sub_str.data() - 3);
}

TEST_F(SubstrTest, OutOfRangeThrowsOutOfRange) {
    EXPECT_THROW(short_str.substr(3, 15), std::out_of_range);
}

TEST_F(SubstrTest, ReverseSubstrFromLongReverseSubstr) {
    mnp::string sub_str = long_str.substr(-1, -long_str.size() - 1);
    mnp::string sub_str2 = sub_str.substr(-1, -long_str.size() -1);
    sub_str2.c_str(buff);
    EXPECT_STREQ(long_str_c, buff);
}

TEST_F(SubstrTest, ReverseSubstrFromShortReverseSubstr) {
    mnp::string sub_str = short_str.substr(-1, -short_str.size() - 1);
    mnp::string sub_str2 = sub_str.substr(-1, -short_str.size() -1);
    sub_str2.c_str(buff);
    EXPECT_STREQ(short_str_c, buff);
}

