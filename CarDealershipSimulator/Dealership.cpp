#include <string>
#include <iostream>
#include "Dealership.h"
#include "NewCar.h"  
#include "OldCar.h"  

Dealership::Dealership() {}

Dealership::~Dealership() {
    for (Car* car : inventory) {
        delete car;
    }
}

void Dealership::addCar(Car* car) {
    inventory.push_back(car);
}

vector<Car*> Dealership::searchByMake(const string& make) {
    vector<Car*> foundCars;
    for (Car* car : inventory) {
        if (car->getMake() == make) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}

vector<Car*> Dealership::searchByModel(const string& model) {
    vector<Car*> foundCars;
    for (Car* car : inventory) {
        if (car->getModel() == model) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}

vector<Car*> Dealership::searchByYear(int year) {
    vector<Car*> foundCars;
    for (Car* car : inventory) {
        if (car->getYear() == year) {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}

void Dealership::displayInventory() const {
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
        return;
    }

    cout << "\n--- Current Inventory ---" << endl;
    for (const Car* car : inventory) {
        cout << "Make: " << car->getMake() << ", Model: " << car->getModel()
            << ", Year: " << car->getYear() << ", Price: $" << car->getPrice() << endl;
        const NewCar* newCar = dynamic_cast<const NewCar*>(car);
        if (newCar) {
            cout << "Warranty: " << newCar->getWarranty() << endl;
        }
        const OldCar* oldCar = dynamic_cast<const OldCar*>(car);
        if (oldCar) {
            cout << "Mileage: " << oldCar->getMileage() << ", Condition: " << oldCar->getCondition() << endl;
        }
    }
    cout << "------------------------" << endl;
}