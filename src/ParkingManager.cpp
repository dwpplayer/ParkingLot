//
// Created by twer  on 5/6/15.
//

#include <sstream>
#include "ParkingManager.h"


ParkingManager::ParkingManager(const std::string &id): ParkingBoy(id) {

}

bool ParkingManager::Park(std::shared_ptr<Car> car) {
    for(ListParkingBoy::iterator it = _parkingBoys.begin(); it != _parkingBoys.end(); ++it)
    {
        if((*it)->Park(car))
        {
            return true;
        }
    }

    return ParkingBoy::Park(car);
}

bool ParkingManager::AddParkingBoy(std::shared_ptr<ParkingBoy> parkingBoy) {
    _parkingBoys.push_back(parkingBoy);
    return true;
}

bool ParkingManager::Remove(std::shared_ptr<ParkingBoy> parkingBoy) {

    for(ListParkingBoy::iterator it = _parkingBoys.begin(); it != _parkingBoys.end(); ++it)
    {
        if((**it) == *parkingBoy )
        {
            _parkingBoys.erase(it);
            return true;
        }
    }

    return false;
}

std::string ParkingManager::ToString(const std::string &prefix) const {

    std::ostringstream os;
    os << "M " << GetAvailableParkingSpace() << " " << GetAllParkingSpace() << "\n";
    std::for_each(_parkingLots.begin(), _parkingLots.end(), [&](std::shared_ptr<ParkingLot> parkingLot)
    {
        os << "\tP " << parkingLot->getAvailableParkingSpaceCount() << " " << parkingLot->getTotalParkingSpace() << "\n";
    });
    std::for_each(_parkingBoys.begin(), _parkingBoys.end(), [&](std::shared_ptr<ParkingBoy> parkingBoy)
    {
        os << parkingBoy->ToString("\t");
    });

    return os.str();
}

int ParkingManager::GetAvailableParkingSpace() const {
    int nAvailableSpace = 0;
    std::for_each(_parkingBoys.begin(), _parkingBoys.end(), [&](std::shared_ptr<ParkingBoy> parkingBoy)
    {
        nAvailableSpace += parkingBoy->GetAvailableParkingSpace();
    });
    int nSelefAvailableSpace = ParkingBoy::GetAvailableParkingSpace();

    return nAvailableSpace + nSelefAvailableSpace;
}

int ParkingManager::GetAllParkingSpace() const {
    int nAllSpace = 0;
    std::for_each(_parkingBoys.begin(), _parkingBoys.end(), [&](std::shared_ptr<ParkingBoy> parkingBoy)
    {
        nAllSpace += parkingBoy->GetAllParkingSpace();
    });
    int nSelfAllParkingSpace = ParkingBoy::GetAllParkingSpace();

    return nAllSpace + nSelfAllParkingSpace;
}
