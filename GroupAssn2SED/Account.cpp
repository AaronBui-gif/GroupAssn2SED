//
// Created by Huy Bui Thanh on 27/04/2021.
//

// Calling libraries
#include "Account.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// class Account
// Default constructor
Account::Account() {

}

// Constructor
Account::Account(int id, string name, string address, string phoneNumber, int listOfRental) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->listOfRentals = listOfRental;
}

// Deconstructor
Account::~Account() {
}
    // Getter Fuctions
    int Account::getID() { return this->id; }
    string Account::getName() { return this->name; }
    string Account::getAddress() { return this->address; }
    string Account::getPhoneNumber() { return this->phoneNumber; }
    int Account::getListOfRentals() { return this->listOfRentals; }

    // Setter Functions
    void Account::setID() { this->id = id; }
    void Account::setName() { this->name = name; }
    void Account::setAddress() { this->address = address; }
    void Account::setPhoneNumber() { this->phoneNumber = phoneNumber; }
    void Account::setListOfRentals() { this->listOfRentals = listOfRentals; }


    // Default Constructor
    GuessAccount::GuessAccount() {
        id = 0;
        name = "";
        address = "";
        phoneNumber = "";
        listOfRentals = 0;
    }
    // Constructor
    GuessAccount::GuessAccount(int id, string name, string address, string phoneNumber, int listOfRentals) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->listOfRentals = listOfRentals;
    }
    // Deconstructor
    GuessAccount::~GuessAccount(){}

    // class RegularAccount inherits from class AccounT

    RegularAccount::RegularAccount(){}
    RegularAccount::RegularAccount(int id, string name, string address, string phoneNumber, int listOfRentals) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->listOfRentals = listOfRentals;
    }

    RegularAccount::~RegularAccount(){}

    VipAccount::VipAccount(){}

    VipAccount::VipAccount(int id, string name, string address, string phoneNumber, int listOfRentals) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->listOfRentals = listOfRentals;
    }

    VipAccount::~VipAccount(){}