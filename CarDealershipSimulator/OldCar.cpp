#include <iostream>
#include "OldCar.h"
using namespace std;

OldCar::OldCar(const string& make, const string& model, int year, double price, int mileage, const string& condition)
    : Car(make, model, year, price), mileage(mileage), condition(condition) {}

int OldCar::getMileage() const {
    return mileage;
}

void OldCar::setMileage(int mileage) {
    this->mileage = mileage;
}

string OldCar::getCondition() const {
    return condition;
}

void OldCar::setCondition(const string& condition) {
    this->condition = condition;
}
