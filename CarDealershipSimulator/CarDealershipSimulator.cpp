#include <iostream>
#include <string>
#include <limits>  
#include "Car.h"
#include "NewCar.h"
#include "OldCar.h"
#include "Dealership.h"
using namespace std;

void displaySearchResults(const vector<Car*>& foundCars, const string& searchType, const string& searchValue) {
    if (foundCars.empty()) {
        cout << "No cars found with " << searchType << " " << searchValue << "." << endl;
    }
    else {
        cout << "\n--- Search Results ---" << endl;
        for (auto* car : foundCars) {
            cout << "Found Car - Make: " << car->getMake() << ", Model: "
                << car->getModel() << ", Year: " << car->getYear()
                << ", Price: $" << car->getPrice() << endl;

            const NewCar* newCar = dynamic_cast<const NewCar*>(car);
            if (newCar) {
                cout << "Warranty: " << newCar->getWarranty() << endl;
            }
            const OldCar* oldCar = dynamic_cast<const OldCar*>(car);
            if (oldCar) {
                cout << "Mileage: " << oldCar->getMileage() << ", Condition: " << oldCar->getCondition() << endl;
            }
        }
        cout << "---------------------" << endl;
    }
}


int getValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}


double getValidatedDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

int main() {
    Dealership dealership;

    dealership.addCar(new NewCar("Toyota", "Corolla", 2022, 22000, "3 years"));
    dealership.addCar(new NewCar("Honda", "Civic", 2022, 21000, "3 years"));
    dealership.addCar(new NewCar("Ford", "Mustang", 2022, 35000, "5 years"));
    dealership.addCar(new NewCar("Chevrolet", "Camaro", 2022, 33000, "3 years"));
    dealership.addCar(new NewCar("Tesla", "Model 3", 2022, 44000, "4 years"));
    dealership.addCar(new OldCar("Toyota", "Camry", 2010, 8000, 120000, "Good"));
    dealership.addCar(new OldCar("Ford", "Fusion", 2008, 7000, 150000, "Fair"));
    dealership.addCar(new OldCar("Honda", "Accord", 2007, 6500, 130000, "Good"));
    dealership.addCar(new OldCar("Nissan", "Altima", 2005, 5000, 180000, "Fair"));
    dealership.addCar(new OldCar("Chevrolet", "Impala", 2000, 3000, 200000, "Runs"));

    int choice;

    while (true) {
        cout << "\nCar Dealership System Menu:\n";
        cout << "1. Add New Car\n";
        cout << "2. Add Old Car\n";
        cout << "3. Display Inventory\n";
        cout << "4. Search Cars\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            // Get new car details
            string make = getStringInput("Enter make: ");
            string model = getStringInput("Enter model: ");
            int year = getValidatedInt("Enter year: ");
            double price = getValidatedDouble("Enter price: $");
            string warranty = getStringInput("Enter warranty (e.g., '3 years'): ");

            Car* newCar = new NewCar(make, model, year, price, warranty);
            dealership.addCar(newCar);
            cout << "New car added.\n";
        }
        else if (choice == 2) {
            string make = getStringInput("Enter make: ");
            string model = getStringInput("Enter model: ");
            int year = getValidatedInt("Enter year: ");
            double price = getValidatedDouble("Enter price: $");
            int mileage = getValidatedInt("Enter mileage: ");
            string condition = getStringInput("Enter condition (e.g., 'Good', 'Fair', 'Poor'): ");

            Car* oldCar = new OldCar(make, model, year, price, mileage, condition);
            dealership.addCar(oldCar);
            cout << "Old car added.\n";
        }
        else if (choice == 3) {
            dealership.displayInventory();
        }
        else if (choice == 4) {
            cout << "Search Cars:\n";
            cout << "1. By Make\n";
            cout << "2. By Model\n";
            cout << "3. By Year\n";
            cout << "Select an option to search by: ";

            int searchChoice;
            if (!(cin >> searchChoice)) {
                cout << "Invalid input. Please try again.\n";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (searchChoice == 1) {
                string make = getStringInput("Enter make: ");
                vector<Car*> foundCars = dealership.searchByMake(make);
                displaySearchResults(foundCars, "make", make);
            }
            else if (searchChoice == 2) {
                string model = getStringInput("Enter model: ");
                vector<Car*> foundCars = dealership.searchByModel(model);
                displaySearchResults(foundCars, "model", model);
            }
            else if (searchChoice == 3) {
                int year = getValidatedInt("Enter year: ");
                vector<Car*> foundCars = dealership.searchByYear(year);
                displaySearchResults(foundCars, "year", to_string(year));
            }
            else {
                cout << "Invalid search option. Please try again.\n";
            }

            cout << "Press Enter to continue...";
            cin.get(); 
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break; 
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}