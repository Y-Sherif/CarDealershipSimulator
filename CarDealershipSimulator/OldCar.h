// OldCar.h

#pragma once
#include "Car.h"
#include <string>

using namespace std;

class OldCar : public Car {
public:
    OldCar(const string& make, const string& model, int year, double price, int mileage, const string& condition);

    // Getters and Setters for additional attributes
    int getMileage() const;
    void setMileage(int mileage);
    string getCondition() const;
    void setCondition(const string& condition);

private:
    int mileage;
    string condition;
};
