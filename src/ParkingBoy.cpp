//
// Created by twer  on 5/5/15.
//

#include <sstream>
#include "ParkingBoy.h"
#include "ParkingLot.h"

bool ParkingBoy::AddParkingLot(std::shared_ptr<ParkingLot> aParkingLot) {
    _parkingLots.push_back(aParkingLot);
    return true;
}

bool ParkingBoy::Park(std::shared_ptr<Car> car)
{
    for(VecParkingLot::iterator it = _parkingLots.begin(); it != _parkingLots.end(); ++it)
    {
        if(!(*it)->IsFull())
        {
            (*it)->Park(car);
            return true;
        }
    }

    return false;
}

bool ParkingBoy::operator==(const ParkingBoy &otherParkingBoy) {
    return _id == otherParkingBoy._id;
}

ParkingBoy::ParkingBoy(const std::string &id): _id(id) {

}

std::vector<std::string> ParkingBoy::Statistic() const {
    std::vector<std::string> vecRet;

    std::ostringstream os;
    os << "B " << GetAvailableParkingSpace() << " " << GetAllParkingSpace();
    vecRet.push_back(os.str());

    std::for_each(_parkingLots.begin(), _parkingLots.end(), [&](std::shared_ptr<ParkingLot> parkingLot)
    {
        std::ostringstream os;
        os << "\tP " << parkingLot->getAvailableParkingSpaceCount() << " " << parkingLot->getTotalParkingSpace();
        vecRet.push_back(os.str());
    });

    return vecRet;
}

int ParkingBoy::GetAvailableParkingSpace()const  {
    int nAailableParkingSpace = 0;
    for_each(_parkingLots.begin(), _parkingLots.end(), [&](std::shared_ptr<ParkingLot> parkingLot)
    {
        nAailableParkingSpace += parkingLot->getAvailableParkingSpaceCount();
    });
    return nAailableParkingSpace;
}

int ParkingBoy::GetAllParkingSpace()const {
    int nAllParkingSpace = 0;
    std::for_each(_parkingLots.begin(), _parkingLots.end(), [&](std::shared_ptr<ParkingLot> parkingLot)
    {
        nAllParkingSpace += parkingLot->getTotalParkingSpace();
    });
    return nAllParkingSpace;
}

std::string ParkingBoy::ToString(const std::string &prefix) const {
    std::string strRet;
    std::vector<std::string> vecStat = std::move(Statistic());
    std::for_each(vecStat.begin(), vecStat.end(), [&](const std::string &item)
    {
        strRet += (prefix + item + "\n");
    });
    return strRet;
}
