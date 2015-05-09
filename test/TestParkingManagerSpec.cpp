//
// Created by twer  on 5/6/15.
//

#include "TestParkingManagerSpec.h"
#include "../src/ParkingBoy.h"
#include "../src/SmartParkingBoy.h"
#include "../src/SuperParkingBoy.h"
#include "../src/ParkingManager.h"
#include "../lib/gmock/gmock.h"

void TestParkingManagerSpec::SetUp() {
    Test::SetUp();

    parkingManager = std::make_shared<ParkingManager>("ParkingMgr");
    parkingBoy = std::make_shared<ParkingBoy>("ParkingBoy");
    smartParkingBoy = std::make_shared<SmartParkingBoy>("SmartParkingBoy");
    superParkingBoy = std::make_shared<SuperParkingBoy>("SuperParkingBoy");
}

void TestParkingManagerSpec::TearDown() {
    Test::TearDown();
}



TEST_F(TestParkingManagerSpec, should_be_able_to_add_parkingboys_to_a_parking_manager)
{
    ASSERT_TRUE(parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(parkingBoy)));
    ASSERT_TRUE(parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(smartParkingBoy)));
    ASSERT_TRUE(parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(superParkingBoy)));
}

TEST_F(TestParkingManagerSpec, should_be_able_to_remove_parkingboys_from_a_parking_manager)
{
    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(parkingBoy));
    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(smartParkingBoy));

    ASSERT_TRUE(parkingManager->Remove(std::dynamic_pointer_cast<ParkingBoy>(parkingBoy)));
    ASSERT_TRUE(parkingManager->Remove(std::dynamic_pointer_cast<ParkingBoy>(smartParkingBoy)));
}

TEST_F(TestParkingManagerSpec, should_be_able_to_park_car_with_delegate_mode_for_a_parking_manager)
{
    std::shared_ptr<ParkingLot> parkingLot = std::make_shared<ParkingLot>(1);

    parkingBoy->AddParkingLot(parkingLot);
    parkingManager->AddParkingBoy(parkingBoy);

    ASSERT_TRUE(parkingManager->Park(std::make_shared<Car>("1")));
}


TEST_F(TestParkingManagerSpec, should_be_able_to_park_car_directly)
{
    std::shared_ptr<ParkingLot> parkingLot = std::make_shared<ParkingLot>(1);

    parkingManager->AddParkingLot(parkingLot);
    parkingManager->AddParkingBoy(parkingBoy);

    ASSERT_TRUE(parkingManager->Park(std::make_shared<Car>("1")));
}


class MockParkingBoy: public ParkingBoy
{
public:
    MockParkingBoy(const std::string &id) : ParkingBoy(id)
    {}
    MOCK_METHOD1(Park, bool(std::shared_ptr<Car> car));
};

TEST_F(TestParkingManagerSpec, should_be_able_to_park_car_when_delegate_to_a_parkingboy)
{
    std::shared_ptr<MockParkingBoy> mockParkingBoy = std::make_shared<MockParkingBoy>("DDD");

    std::shared_ptr<Car> car = std::make_shared<Car>("1");
    EXPECT_CALL(*mockParkingBoy, Park(car)).Times(1).WillRepeatedly(testing::Return(true));

    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(mockParkingBoy));
    parkingManager->Park(car);
}

TEST_F(TestParkingManagerSpec, should_park_car_only_once)
{
    std::shared_ptr<MockParkingBoy> mockParkingBoy = std::make_shared<MockParkingBoy>("DDD");
    std::shared_ptr<MockParkingBoy> mockParkingBoy2 = std::make_shared<MockParkingBoy>("TTT");

    std::shared_ptr<Car> car = std::make_shared<Car>("1");
    EXPECT_CALL(*mockParkingBoy, Park(car)).Times(1).WillRepeatedly(testing::Return(true));
    EXPECT_CALL(*mockParkingBoy2, Park(car)).Times(0);

    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(mockParkingBoy));
    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(mockParkingBoy2));
    parkingManager->Park(car);
}