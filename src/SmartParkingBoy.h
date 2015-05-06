//
// Created by twer  on 5/6/15.
//

#ifndef PARKINGLOT_SMARTPARKINGBOY_H
#define PARKINGLOT_SMARTPARKINGBOY_H


#include "ParkingBoy.h"

class SmartParkingBoy: public ParkingBoy {
public:
    SmartParkingBoy(const std::string &id);
    virtual bool Park(std::shared_ptr<Car> car);
};


#endif //PARKINGLOT_SMARTPARKINGBOY_H
