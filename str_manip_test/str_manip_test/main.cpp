//
//  main.cpp
//  str_manip_test
//
//  Created by Anil Anar on 15.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#include <iostream>
#include <string>
#include "../../my_string.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    mnp::string s = "anil";
    mnp::string s2 = s;
    s = 'a';
    int a = 5;
    s = s[{a,2}];
    std::cout << "Hello, World!\n";
    return 0;
}

