//
// Created by twer  on 5/5/15.
//

#include "ParkingBoy.h"
#include "ParkingLot.h"

bool ParkingBoy::Add(std::shared_ptr<ParkingLot> aParkingLot) {
    _parkingLots.push_back(aParkingLot);
    return true;
}

bool ParkingBoy::Park(std::shared_ptr<Car> car)
{
    for(VecParkingLot::iterator it = _parkingLots.begin(); it != _parkingLots.end(); ++it)
    {
        if(!(*it)->IsFull())
        {
            (*it)->Park(car);
            return true;
        }
    }

    return false;
}

