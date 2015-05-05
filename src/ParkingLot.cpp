//
// Created by twer  on 5/5/15.
//

#include "ParkingLot.h"

bool ParkingLot::Park(const Car &car) {
    if(!IsFull())
    {
        ++_nUsed;
        return true;
    }
    return false;
}

bool ParkingLot::IsFull()const { return getAvailableParkingSpaceCount() <= 0; }

int ParkingLot::getAvailableParkingSpaceCount()const { return _nTotal - _nUsed; }


int ParkingLot::UnPark(const Car &car) {
    if(_nUsed > 0)
    {
        --_nUsed;
        return true;
    }
    return false;
}

ParkingLot::ParkingLot(int nTotal, int nUsed) : _nTotal(nTotal), _nUsed(nUsed) {

}