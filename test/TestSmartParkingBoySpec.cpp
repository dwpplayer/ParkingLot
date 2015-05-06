//
// Created by twer  on 5/6/15.
//

#include "TestSmartParkingBoySpec.h"
#include "../src/Car.h"
#include "../src/SmartParkingBoy.h"


void TestSmartParkingBoySpec::TearDown() {
    Test::TearDown();
}


void TestSmartParkingBoySpec::SetUp() {
    Test::SetUp();
    _parkingLotSmall = std::make_shared<ParkingLot>(1);
    _parkingLotBig = std::make_shared<ParkingLot>(10);
}

TEST_F(TestSmartParkingBoySpec, ShouldParkCarInParkingLotWithMoreParkingSpace)
{
    std::shared_ptr<SmartParkingBoy> parkingLotBoy;

    parkingLotBoy = std::make_shared<SmartParkingBoy>("XXX");

    parkingLotBoy->Add(_parkingLotSmall);
    parkingLotBoy->Add(_parkingLotBig);

    parkingLotBoy->Park(std::make_shared<Car>("1"));
    parkingLotBoy->Park(std::make_shared<Car>("2"));

    ASSERT_TRUE(_parkingLotBig->FindCar(std::make_shared<Car>("1")));
    ASSERT_TRUE(_parkingLotBig->FindCar(std::make_shared<Car>("2")));
}