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
    ParkingLot parkingLot(1, 0);
    Car car;
    ASSERT_TRUE(parkingLot.Park(car));
}

TEST_F(TestParkingLotSpec, ShouldParkingCarWhenTheParkinglotIsFull)
{
    ParkingLot parkingLot(5, 5);
    Car car;
    ASSERT_FALSE(parkingLot.Park(car));
}

TEST_F(TestParkingLotSpec, ShouldIncrementalParkingLotNumbeWhenUnparkOneCar)
{
    //given
    ParkingLot parkingLot(2, 1);
    Car car;
    int nParkingSpaceCountBefore = parkingLot.getAvailableParkingSpaceCount();

    //when
    parkingLot.UnPark(car);

    //then
    ASSERT_EQ(1, parkingLot.getAvailableParkingSpaceCount() - nParkingSpaceCountBefore);
}