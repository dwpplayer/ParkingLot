//
// Created by twer  on 5/5/15.
//

#include "Car.h"

Car::Car(const std::string &id):_id(id) {

}

bool Car::operator==(const Car &otherCar) {
    return _id == otherCar._id;
}
