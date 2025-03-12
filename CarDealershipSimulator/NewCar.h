// NewCar.h

#pragma once
#include "Car.h"
#include <string>

using namespace std;

class NewCar : public Car {
public:
    NewCar(const string& make, const string& model, int year, double price, const string& warranty);

    // Getter and Setter for warranty
    string getWarranty() const;
    void setWarranty(const string& warranty);

private:
    string warranty;
};
