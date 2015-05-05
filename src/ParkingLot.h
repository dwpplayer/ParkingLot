//
// Created by twer  on 5/5/15.
//

#ifndef FIZZBUZZWHIZZ_PARKINGLOT_H
#define FIZZBUZZWHIZZ_PARKINGLOT_H


#include "Car.h"

class ParkingLot {
public:
    ParkingLot(int nBucket);
    bool Park(const Car &car);

private:
    int _nBucket;

};


#endif //FIZZBUZZWHIZZ_PARKINGLOT_H
