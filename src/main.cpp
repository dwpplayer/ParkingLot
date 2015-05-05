#include <iostream>
#include "../lib/gtest/gtest.h"
#include "../lib/gmock/gmock.h"

using namespace std;

#define TEST_SWITCH

int main(int argc, char **argv) {
#ifndef TEST_SWITCH
    return 0;
 #else
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}