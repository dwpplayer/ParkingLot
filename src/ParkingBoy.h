//
// Created by twer  on 5/5/15.
//

#ifndef PARKINGLOT_PARKINGBOY_H
#define PARKINGLOT_PARKINGBOY_H


#include <memory>
#include <vector>
#include "car.h"
#include "ParkingLot.h"

class ParkingLot;
class ParkingBoy {

public:
    bool Add(std::shared_ptr<ParkingLot> aParkingLot);
    bool Park(std::shared_ptr<Car> car);

private:
    typedef std::vector<std::shared_ptr<ParkingLot>> VecParkingLot;
    VecParkingLot _parkingLots;

};


#endif //PARKINGLOT_PARKINGBOY_H
