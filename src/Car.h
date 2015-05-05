//
// Created by twer  on 5/5/15.
//

#ifndef FIZZBUZZWHIZZ_CAR_H
#define FIZZBUZZWHIZZ_CAR_H


#include <string>

class Car {
public:
    Car(const std::string &id);

    bool operator == (const Car &otherCar);
private:
    std::string _id;
};


#endif //FIZZBUZZWHIZZ_CAR_H
