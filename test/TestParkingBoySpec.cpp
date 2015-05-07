//
// Created by twer  on 5/5/15.
//

#include "TestParkingBoySpec.h"
#include "../src/ParkingLot.h"
#include "../src/ParkingBoy.h"
#include "../lib/gtest/gtest.h"

void TestParkingBoySpec::TearDown() {
    Test::TearDown();
}


void TestParkingBoySpec::SetUp() {
    Test::SetUp();
    _parkingLotSmall = std::make_shared<ParkingLot>(1);
    _parkingLotBig = std::make_shared<ParkingLot>(10);
    _parkingLotBoy = std::make_shared<ParkingBoy>("XXX");

    _parkingLotBoy->AddParkingLot(_parkingLotSmall);
    _parkingLotBoy->AddParkingLot(_parkingLotBig);
}

TEST_F(TestParkingBoySpec, ShouldAddOneMoreParkingLotForAPrkingBoy)
{
    ParkingBoy parkingBoy("xxx");
    parkingBoy.AddParkingLot(_parkingLotSmall);

    ASSERT_TRUE(parkingBoy.AddParkingLot(_parkingLotBig));
}

TEST_F(TestParkingBoySpec, ShouldParkCarInMultipleParkingLotsWithSequenceOrder)
{
    _parkingLotBoy->Park(std::make_shared<Car>("1"));
    _parkingLotBoy->Park(std::make_shared<Car>("2"));

    ASSERT_TRUE(_parkingLotSmall->FindCar(std::make_shared<Car>("1")));
    ASSERT_TRUE(_parkingLotBig->FindCar(std::make_shared<Car>("2")));
}

TEST_F(TestParkingBoySpec, ShouldOutputParkinglotStatus)
{
    _parkingLotBoy->Park(std::make_shared<Car>("1"));
    ASSERT_EQ("B 10 11\n\tP 0 1\n\tP 10 10\n", _parkingLotBoy->ToString());
}