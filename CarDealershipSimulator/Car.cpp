#include <iostream>
#include <string>
#include "Car.h"

Car::Car(const string& make, const string& model, int year, double price)
    : make(make), model(model), year(year), price(price) {}

Car::~Car() {
}

string Car::getMake() const {
    return make;
}

string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getPrice() const {
    return price;
}

void Car::setMake(const string& make) {
    this->make = make;
}

void Car::setModel(const string& model) {
    this->model = model;
}

void Car::setYear(int year) {
    this->year = year;
}

void Car::setPrice(double price) {
    this->price = price;
}
