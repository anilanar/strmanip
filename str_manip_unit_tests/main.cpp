#include <stdio.h>
#include <gtest/gtest.h>
#include <string>
#include <chrono>
#include <sys/time.h>
#include <sys/types.h>
#include <vector>
#include "mnp_string.h"

int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}