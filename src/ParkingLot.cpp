//
// Created by twer  on 5/5/15.
//

#include "ParkingLot.h"

bool ParkingLot::Park(const Car &car) {
    if(_nBucket > 0)
    {
        --_nBucket;
        return true;
    }
    return false;
}

ParkingLot::ParkingLot(int nBucket):_nBucket(nBucket) {

}
