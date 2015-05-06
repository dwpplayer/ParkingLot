//
// Created by twer  on 5/5/15.
//

#ifndef FIZZBUZZWHIZZ_PARKINGLOT_H
#define FIZZBUZZWHIZZ_PARKINGLOT_H


#include <vector>
#include "Car.h"

class ParkingLot {
public:
    ParkingLot(int nTotal, int nPlaceHoldSpace = 0);
    bool Park(std::shared_ptr<Car> car);
    int UnPark(std::shared_ptr<Car> car);
    int getAvailableParkingSpaceCount()const;
    int getTotalParkingSpace()const;
    bool IsFull()const;
    bool FindCar(std::shared_ptr<Car> car)const;


private:
    typedef std::vector<std::shared_ptr<Car>> VecCar;
    VecCar _cars;
    int _nTotal;
    int _nPlaceHolderSpace;
};


#endif //FIZZBUZZWHIZZ_PARKINGLOT_H
