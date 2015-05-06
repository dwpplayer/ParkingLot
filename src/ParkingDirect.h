//
// Created by twer  on 5/6/15.
//

#ifndef PARKINGLOT_PARKINGDIRECT_H
#define PARKINGLOT_PARKINGDIRECT_H


#include <memory>
#include <list>

class ParkingBoy;
class ParkingDirect {
public:
    bool Add(std::shared_ptr<ParkingBoy> parkingBoy);
    std::string GetDetail()const;

private:
    typedef std::list<std::shared_ptr<ParkingBoy>> ListParkingBoy;
    ListParkingBoy _boys;
};


#endif //PARKINGLOT_PARKINGDIRECT_H
