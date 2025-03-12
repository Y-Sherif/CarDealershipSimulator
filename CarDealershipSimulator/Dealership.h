// Dealership.h

#pragma once
#include "Car.h"
#include "NewCar.h"
#include "OldCar.h"
#include <vector>
#include <string>

using namespace std;

class Dealership {
public:
    Dealership();
    ~Dealership();

    // Functions to manage the inventory
    void addCar(Car* car);
    vector<Car*> searchByMake(const string& make);
    vector<Car*> searchByModel(const string& model);
    vector<Car*> searchByYear(int year);

    // Display all cars in the inventory
    void displayInventory() const;

private:
    vector<Car*> inventory; 
};
