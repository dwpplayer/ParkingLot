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
    ParkingBoy(const std::string &id);
    bool AddParkingLot(std::shared_ptr<ParkingLot> aParkingLot);
    virtual bool Park(std::shared_ptr<Car> car);
    bool operator == (const ParkingBoy &otherParkingBoy);
    virtual std::string ToString(const std::string &prefix = "")const;

    virtual int GetAvailableParkingSpace()const;
    virtual int GetAllParkingSpace()const;

private:
    std::vector<std::string> Statistic()const;

protected:
    typedef std::vector<std::shared_ptr<ParkingLot>> VecParkingLot;
    VecParkingLot _parkingLots;

    std::string _id;
};


#endif //PARKINGLOT_PARKINGBOY_H
