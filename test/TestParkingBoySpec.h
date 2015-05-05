//
// Created by twer  on 5/5/15.
//

#ifndef PARKINGLOT_TESTPARKINGBOYSPEC_H
#define PARKINGLOT_TESTPARKINGBOYSPEC_H
#include "../lib/gtest/gtest.h"
#include "../src/ParkingBoy.h"

class ParkingLot;
class TestParkingBoySpec: public testing::Test {
public:
    virtual void SetUp();
    virtual void TearDown();

protected:
    std::shared_ptr<ParkingLot> _parkingLotSmall;
    std::shared_ptr<ParkingLot> _parkingLotBig;
    std::shared_ptr<ParkingBoy> _parkingLotBoy;
};


#endif //PARKINGLOT_TESTPARKINGBOYSPEC_H
