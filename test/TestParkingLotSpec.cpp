//
// Created by twer  on 5/5/15.
//


#include "TestParkingLotSpec.h"
#include "../src/ParkingLot.h"
#include "../src/Car.h"
#include "../src/ParkingBoy.h"

void TestParkingLotSpec::TearDown() {
    Test::TearDown();
}


void TestParkingLotSpec::SetUp() {
    Test::SetUp();
}


TEST_F(TestParkingLotSpec, ShouldParkingCarWhenTheParkinglotExistSpace)
{
    ParkingLot parkingLot(1);
    ASSERT_TRUE(parkingLot.Park(std::make_shared<Car>("1")));
}

TEST_F(TestParkingLotSpec, ShouldParkingCarWhenTheParkinglotIsFull)
{
    ParkingLot parkingLot(0);
    ASSERT_FALSE(parkingLot.Park(std::make_shared<Car>("1")));
}

TEST_F(TestParkingLotSpec, ShouldIncrementalParkingLotNumbeWhenUnparkOneCar)
{
    //given
    ParkingLot parkingLot(2);

    parkingLot.Park(std::make_shared<Car>("1"));
    int nParkingSpaceCountBefore = parkingLot.getAvailableParkingSpaceCount();

    //when
    parkingLot.UnPark(std::make_shared<Car>("1"));

    //then
    ASSERT_EQ(1, parkingLot.getAvailableParkingSpaceCount() - nParkingSpaceCountBefore);
}