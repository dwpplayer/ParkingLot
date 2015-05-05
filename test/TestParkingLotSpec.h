//
// Created by twer  on 5/5/15.
//

#ifndef PARKINGLOT_TESTCARSPEC_H
#define PARKINGLOT_TESTCARSPEC_H

#include "../lib/gtest/gtest.h"

class TestParkingLotSpec : public ::testing::Test{

public:
    virtual void SetUp();
    virtual void TearDown();
};

#endif //PARKINGLOT_TESTCARSPEC_H
