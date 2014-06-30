//
//  test_fixture.h
//  str_manip
//
//  Created by Anil Anar on 29.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_test_fixture_h
#define str_manip_test_fixture_h

#include <gtest/gtest.h>
#include "mnp_string.h"

class CommonTest: public testing::Test {
protected:
    const char* empty_str_c = "";
    const char* short_str_c = "strt strtst";
    const char* long_str_c = "strt strtst tstrts trts strt strtst tstrts trts strt strtst";
    const int short_count_in_long = 6;
    char buff[100];
    
    mnp::string empty_str;
    mnp::string short_str;
    mnp::string long_str;
    
    CommonTest():
    empty_str(),
    short_str(short_str_c),
    long_str(long_str_c) {}
};

#endif
