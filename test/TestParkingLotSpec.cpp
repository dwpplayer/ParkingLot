//
// Created by twer  on 5/5/15.
//


#include "TestParkingLotSpec.h"
#include "../src/ParkingLot.h"
#include "../src/Car.h"

void TestParkingLotSpec::TearDown() {
    Test::TearDown();
}


void TestParkingLotSpec::SetUp() {
    Test::SetUp();
}


TEST_F(TestParkingLotSpec, ShouldParkingCarWhenTheParkinglotExistSpace)
{
    ParkingLot parkingLot(1);
    Car car;
    ASSERT_TRUE(parkingLot.Park(car));
}

TEST_F(TestParkingLotSpec, ShouldParkingCarWhenTheParkinglotIsFull)
{
    ParkingLot parkingLot(0);
    Car car;
    ASSERT_FALSE(parkingLot.Park(car));
}