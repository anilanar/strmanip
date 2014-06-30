//
//  mnp_string_combin.cpp
//  str_manip
//
//  Created by Anil Anar on 29.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#include <gtest/gtest.h>
#include <tuple>
#include "test_fixture.h"


class CombinTest: public CommonTest, public testing::WithParamInterface<std::tuple<int,int>> {
protected:
    const mnp::string str_list[3] = {
        short_str,
        long_str,
        long_str.substr(-1, -long_str.size() - 1)
    };
    
    const mnp::string substr_list[3] = {
        mnp::string("strt"),
        mnp::string("strt strtst tstrts trts strt strtst"),
        mnp::string("strt strtst tstrts trts strt strtst").substr(-1, -36)
    };
    
    const int count_r[3][3] = {
        {2, 0, 0},
        {8, 2, 1},
        {7, 1, 2}
    };
};

INSTANTIATE_TEST_CASE_P(TestCombinations,
                        CombinTest,
                        testing::Combine(testing::Values(0,1,2),
                                         testing::Values(0,1,2)));

TEST_P(CombinTest, Lala) {
    std::tuple<int, int> t = GetParam();
    int f = std::get<0>(t);
    int s = std::get<1>(t);
    
    EXPECT_EQ(count_r[f][s], str_list[f].count(substr_list[s]));
}

