//
// Created by twer  on 5/5/15.
//

#include <memory>
#include "TestParkingBoySpec.h"
#include "../src/ParkingLot.h"
#include "../src/ParkingBoy.h"
#include "../lib/gtest/gtest.h"

void TestParkingBoySpec::TearDown() {
    Test::TearDown();
}


void TestParkingBoySpec::SetUp() {
    Test::SetUp();
    _parkingLotSmall = std::make_shared<ParkingLot>(1, 0);
    _parkingLotBig = std::make_shared<ParkingLot>(10, 0);
    _parkingLotBoy = std::make_shared<ParkingBoy>();

    _parkingLotBoy->Add(_parkingLotSmall);
    _parkingLotBoy->Add(_parkingLotBig);
}

TEST_F(TestParkingBoySpec, ShouldAddOneMoreParkingLotForAPrkingBoy)
{
    ParkingBoy parkingBoy;
    parkingBoy.Add(_parkingLotSmall);

    ASSERT_TRUE(parkingBoy.Add(_parkingLotBig));
}

TEST_F(TestParkingBoySpec, ShouldParkCarInMultipleParkingLotsWithSequenceOrder)
{
    _parkingLotBoy->Park(std::make_shared<Car>("1"));
    _parkingLotBoy->Park(std::make_shared<Car>("2"));

    ASSERT_TRUE(_parkingLotSmall->FindCar(std::make_shared<Car>("1")));
    ASSERT_TRUE(_parkingLotBig->FindCar(std::make_shared<Car>("2")));
}