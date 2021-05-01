//
// Created by Huy Bui Thanh on 27/04/2021.
//

#include "Account.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Account {
private:
    int id;
    string name;
    string address;
    string phoneNumber;
    int listOfRentals;
    string type;

public:
    Account();
    Account(int id, string name, string address, string phoneNumber, int listOfRental);
    ~Account();
    // Getter Fuctions
    int getID() { return this->id; }
    string getName() { return this->name; }
    string getAddress() { return this->address; }
    string getPhoneNumber() { return this->phoneNumber; }
    int getListOfRentals() { return this->listOfRentals; }

    // Setter Functions
    void setID() { this->id = id; }
    void setName() { this->name = name; }
    void setAddress() { this->address = address; }
    void setPhoneNumber() { this->phoneNumber = phoneNumber; }
    void setListOfRentals() { this->listOfRentals = listOfRentals; }

};
    // Default constructor
    Account::Account() {
        id = 0;
        name = "";
        address = "";
        phoneNumber = "";
        listOfRentals = 0;
    }

    // Constructor
    Account::Account(int id, string name, string address, string phoneNumber, int listOfRental) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->listOfRentals = listOfRental;
    }

    Account::~Account() {
    }


