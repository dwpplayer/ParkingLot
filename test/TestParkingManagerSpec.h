//
// Created by twer  on 5/6/15.
//

#ifndef PARKINGLOT_TESTPARKINGMANAGERSPEC_H
#define PARKINGLOT_TESTPARKINGMANAGERSPEC_H


#include "../lib/gtest/gtest.h"
class ParkingManager;
class ParkingBoy;
class SmartParkingBoy;
class SuperParkingBoy;
class TestParkingManagerSpec: public testing::Test {
public:
    void SetUp();
    void TearDown();

protected:
    std::shared_ptr<ParkingManager> parkingManager;
    std::shared_ptr<ParkingBoy> parkingBoy;
    std::shared_ptr<SmartParkingBoy> smartParkingBoy;
    std::shared_ptr<SuperParkingBoy> superParkingBoy;
};


#endif //PARKINGLOT_TESTPARKINGMANAGERSPEC_H
