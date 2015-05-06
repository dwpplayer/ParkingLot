#include <iostream>
#include "../lib/gtest/gtest.h"
#include "../lib/gmock/gmock.h"
#include "ParkingLot.h"
#include "ParkingManager.h"
#include "ParkingDirect.h"

using namespace std;

#define TEST_SWITCH

int main(int argc, char **argv) {
#ifndef TEST_SWITCH

    std::shared_ptr<ParkingManager> parkingManager = std::make_shared<ParkingManager>("ParkingManager");
    std::shared_ptr<ParkingBoy> parkingBoy = std::make_shared<ParkingBoy>("ParkingBoy");
    std::shared_ptr<ParkingBoy> parkingBoy2 = std::make_shared<ParkingBoy>("ParkingBoy2");
    std::shared_ptr<ParkingLot> parkingLot = std::make_shared<ParkingLot>(10, 8);
    std::shared_ptr<ParkingLot> parkingLot2 = std::make_shared<ParkingLot>(5, 3);
    std::shared_ptr<ParkingLot> parkingLot3 = std::make_shared<ParkingLot>(3, 3);
    std::shared_ptr<ParkingLot> parkingLot4 = std::make_shared<ParkingLot>(2, 1);

    parkingBoy->Add(parkingLot2);
    parkingBoy2->Add(parkingLot3);
    parkingBoy2->Add(parkingLot4);


    parkingManager->AddParkingBoy(parkingBoy);
    parkingManager->AddParkingBoy(parkingBoy2);
    parkingManager->Add(parkingLot);

    std::shared_ptr<ParkingDirect> parkingDirect = std::make_shared<ParkingDirect>();

    parkingDirect->Add(std::dynamic_pointer_cast<ParkingBoy>(parkingManager));

    std::cout << parkingDirect->GetDetail();
    return 0;
 #else
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}