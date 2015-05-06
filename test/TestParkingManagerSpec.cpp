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



TEST_F(TestParkingManagerSpec, ShouldAddParkingBoys)
{
    ASSERT_TRUE(parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(parkingBoy)));
    ASSERT_TRUE(parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(smartParkingBoy)));
    ASSERT_TRUE(parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(superParkingBoy)));
}

TEST_F(TestParkingManagerSpec, ShouldRemoveParkingBoys)
{
    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(parkingBoy));
    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(smartParkingBoy));

    ASSERT_TRUE(parkingManager->Remove(std::dynamic_pointer_cast<ParkingBoy>(parkingBoy)));
    ASSERT_TRUE(parkingManager->Remove(std::dynamic_pointer_cast<ParkingBoy>(smartParkingBoy)));
}

TEST_F(TestParkingManagerSpec, ShouldReturnFalseWhenTheRemoveParkingBoyNotUnderTheParkingManager)
{
    std::shared_ptr<SuperParkingBoy> superParkingBoy2 = std::make_shared<SuperParkingBoy>("SuperParkingBoy2");

    ASSERT_FALSE(parkingManager->Remove(std::dynamic_pointer_cast<ParkingBoy>(superParkingBoy2)));
}

TEST_F(TestParkingManagerSpec, ShouldParkCarDelegate)
{
    std::shared_ptr<ParkingLot> parkingLot = std::make_shared<ParkingLot>(1);

    parkingBoy->Add(parkingLot);
    parkingManager->AddParkingBoy(parkingBoy);

    ASSERT_TRUE(parkingManager->Park(std::make_shared<Car>("1")));
}


TEST_F(TestParkingManagerSpec, ShouldParkCarDirectly)
{
    std::shared_ptr<ParkingLot> parkingLot = std::make_shared<ParkingLot>(1);

    parkingManager->Add(parkingLot);
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

TEST_F(TestParkingManagerSpec, ShouldDelegateCallToParkingBoyWhenParkCar)
{
    std::shared_ptr<MockParkingBoy> mockParkingBoy = std::make_shared<MockParkingBoy>("DDD");

    std::shared_ptr<Car> car = std::make_shared<Car>("1");
    EXPECT_CALL(*mockParkingBoy, Park(car)).Times(1).WillRepeatedly(testing::Return(true));

    parkingManager->AddParkingBoy(std::dynamic_pointer_cast<ParkingBoy>(mockParkingBoy));
    parkingManager->Park(car);
}

TEST_F(TestParkingManagerSpec, ShouldParkCarOnlyOnce)
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