//
// Created by twer  on 5/6/15.
//

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
