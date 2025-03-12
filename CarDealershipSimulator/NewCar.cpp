#include <iostream>
#include "NewCar.h"
using namespace std;

NewCar::NewCar(const string& make, const string& model, int year, double price, const string& warranty)
    : Car(make, model, year, price), warranty(warranty) {}

string NewCar::getWarranty() const {
    return warranty;
}

void NewCar::setWarranty(const string& warranty) {
    this->warranty = warranty;
}
