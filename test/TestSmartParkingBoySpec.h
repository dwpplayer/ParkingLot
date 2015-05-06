//
// Created by twer  on 5/6/15.
//

#ifndef PARKINGLOT_TESTSMARTPARKINGBOYSPEC_H
#define PARKINGLOT_TESTSMARTPARKINGBOYSPEC_H


#include <memory>
#include "../lib/gtest/gtest.h"

class ParkingLot;
class SmartParkingBoy;

class TestSmartParkingBoySpec: public testing::Test {
public:
    virtual void SetUp();
    virtual void TearDown();

protected:
    std::shared_ptr<ParkingLot> _parkingLotSmall;
    std::shared_ptr<ParkingLot> _parkingLotBig;
};


#endif //PARKINGLOT_TESTSMARTPARKINGBOYSPEC_H
