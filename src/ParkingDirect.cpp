//
// Created by twer  on 5/6/15.
//

#include <sstream>
#include "ParkingDirect.h"
#include "ParkingBoy.h"

bool ParkingDirect::Add(std::shared_ptr<ParkingBoy> parkingBoy) {

    for(ListParkingBoy::iterator it = _boys.begin(); it != _boys.end(); ++it)
    {
        if(**it == *parkingBoy)
        {
            return false;
        }
    }
    _boys.push_back(parkingBoy);
    return true;
}

std::string ParkingDirect::GetDetail() const {
    std::ostringstream os;
    std::for_each(_boys.begin(), _boys.end(), [&](std::shared_ptr<ParkingBoy> parkingBoy){
        os << parkingBoy->ToString();
    });

    return os.str();
}
