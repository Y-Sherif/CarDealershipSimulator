// Car.h

#pragma once
#include <string>

using namespace std;

class Car {
public:
    Car(const string& make, const string& model, int year, double price);
    virtual ~Car();  

    // Getters
    string getMake() const;
    string getModel() const;
    int getYear() const;
    double getPrice() const;

    // Setters
    void setMake(const string& make);
    void setModel(const string& model);
    void setYear(int year);
    void setPrice(double price);

private:
    string make;
    string model;
    int year;
    double price;
};
