//
// Created by twer  on 5/6/15.
//

#ifndef PARKINGLOT_PARKINGMANAGER_H
#define PARKINGLOT_PARKINGMANAGER_H

#include <list>
#include "ParkingBoy.h"

class ParkingManager : public ParkingBoy{
public:
    ParkingManager(const std::string &id);
    virtual bool Park(std::shared_ptr<Car> car);
    bool AddParkingBoy(std::shared_ptr<ParkingBoy> parkingBoy);
    bool Remove(std::shared_ptr<ParkingBoy> parkingBoy);
    virtual std::string ToString(const std::string &prefix = "")const;

protected:
    virtual int GetAvailableParkingSpace()const;
    virtual int GetAllParkingSpace()const;

private:
    std::string GetSelfParkingLotInfo()const;
    std::string GetParkingBoysInfo()const;
    std::string GetTotalParkingLotInfo()const;

private:
    typedef std::list<std::shared_ptr<ParkingBoy>> ListParkingBoy;

    ListParkingBoy _parkingBoys;
};


#endif //PARKINGLOT_PARKINGMANAGER_H
