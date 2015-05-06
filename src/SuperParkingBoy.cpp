//
// Created by twer  on 5/6/15.
//

#include "SuperParkingBoy.h"


bool SuperParkingBoy::Park(std::shared_ptr<Car> car) {
    if(0 == _parkingLots.size())
    {
        return false;
    }

    if(1 == _parkingLots.size())
    {
        return _parkingLots[0]->Park(car);
    }

    VecParkingLot::iterator itFind = _parkingLots.begin();

    for(VecParkingLot::iterator it = itFind + 1; it != _parkingLots.end(); ++it)
    {
        if((*it)->getAvailableParkingSpaceCount() / (*it)->getTotalParkingSpace() > (*itFind)->getAvailableParkingSpaceCount() / (*itFind)->getTotalParkingSpace())
        {
            itFind = it;
        }
    }

    return (*itFind)->Park(car);
}

SuperParkingBoy::SuperParkingBoy(const std::string &id): ParkingBoy(id) {

}
