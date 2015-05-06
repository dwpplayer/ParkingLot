//
// Created by twer  on 5/5/15.
//

#include "ParkingLot.h"

bool ParkingLot::Park(std::shared_ptr<Car> car) {
    if(!IsFull())
    {
        _cars.push_back(car);
        return true;
    }
    return false;
}

bool ParkingLot::IsFull()const { return getAvailableParkingSpaceCount() <= 0; }

int ParkingLot::getAvailableParkingSpaceCount()const { return _nTotal - _cars.size(); }


int ParkingLot::UnPark(std::shared_ptr<Car> car ) {
    if(_cars.size() > 0)
    {
        for(VecCar::iterator it = _cars.begin(); it != _cars.end(); ++it) {
            if (**it == *car) {
                _cars.erase(it);
                return true;
            }
        }
    }
    return false;
}

ParkingLot::ParkingLot(int nTotal) : _nTotal(nTotal){

}

bool ParkingLot::FindCar(std::shared_ptr<Car> car)const {
    for(VecCar::const_iterator it = _cars.begin(); it != _cars.end(); ++it) {
        if (**it == *car) {
            return true;
        }
    }
    return false;
}
