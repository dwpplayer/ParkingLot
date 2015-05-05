//
// Created by twer  on 5/5/15.
//

#ifndef FIZZBUZZWHIZZ_PARKINGLOT_H
#define FIZZBUZZWHIZZ_PARKINGLOT_H


#include "Car.h"

class ParkingLot {
public:
    ParkingLot(int nTotal, int nUsed);
    bool Park(const Car &car);
    int UnPark(const Car &car);
    int getAvailableParkingSpaceCount()const;


private:
    bool IsFull()const;


private:
    int _nTotal;
    int _nUsed;
};


#endif //FIZZBUZZWHIZZ_PARKINGLOT_H
