//
// Created by twer  on 5/6/15.
//

#include "TestParkingDirectSpec.h"
#include "../lib/gtest/gtest.h"
#include "../src/ParkingManager.h"
#include "../src/ParkingDirect.h"


TEST_F(TestParkingDirectSpec, ShouldOutputCarListForParkingManagersAndParkingBoys)
{
    std::shared_ptr<ParkingManager> parkingManager = std::make_shared<ParkingManager>("ParkingManager");
    std::shared_ptr<ParkingBoy> parkingBoy = std::make_shared<ParkingBoy>("ParkingBoy");

    std::shared_ptr<ParkingDirect> parkingDirect = std::make_shared<ParkingDirect>();

    ASSERT_TRUE(parkingDirect->Add(parkingManager));
    ASSERT_TRUE(parkingDirect->Add(parkingBoy));
}

const std::string expectedOutputList = "M 5 20"
        "\n\tP 2 10"
        "\n\tB 2 5"
        "\n\t\tP 2 5"
        "\n\tB 1 5"
        "\n\t\tP 0 3"
        "\n\t\tP 1 2\n";


TEST_F(TestParkingDirectSpec, ShouldVerifyOutAsExpected)
{
    std::shared_ptr<ParkingManager> parkingManager = std::make_shared<ParkingManager>("ParkingManager");
    std::shared_ptr<ParkingBoy> parkingBoy = std::make_shared<ParkingBoy>("ParkingBoy");
    std::shared_ptr<ParkingBoy> parkingBoy2 = std::make_shared<ParkingBoy>("ParkingBoy2");
    std::shared_ptr<ParkingLot> parkingLot = std::make_shared<ParkingLot>(10, 8);
    std::shared_ptr<ParkingLot> parkingLot2 = std::make_shared<ParkingLot>(5, 3);
    std::shared_ptr<ParkingLot> parkingLot3 = std::make_shared<ParkingLot>(3, 3);
    std::shared_ptr<ParkingLot> parkingLot4 = std::make_shared<ParkingLot>(2, 1);

    parkingBoy->AddParkingLot(parkingLot2);
    parkingBoy2->AddParkingLot(parkingLot3);
    parkingBoy2->AddParkingLot(parkingLot4);


    parkingManager->AddParkingBoy(parkingBoy);
    parkingManager->AddParkingBoy(parkingBoy2);
    parkingManager->AddParkingLot(parkingLot);

    std::shared_ptr<ParkingDirect> parkingDirect = std::make_shared<ParkingDirect>();

    parkingDirect->Add(std::dynamic_pointer_cast<ParkingBoy>(parkingManager));

    ASSERT_EQ(expectedOutputList, parkingDirect->GetDetail());
}