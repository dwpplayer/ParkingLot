//
// Created by twer  on 5/6/15.
//

#ifndef PARKINGLOT_SUPERTPARKINGBOY_H
#define PARKINGLOT_SUPERTPARKINGBOY_H


#include "ParkingBoy.h"

class SuperParkingBoy : public ParkingBoy {
public:
    virtual bool Park(std::shared_ptr<Car> car);
};


#endif //PARKINGLOT_SUPERTPARKINGBOY_H

