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
    id = "";
    name = "";
    address = "";
    phoneNumber = "";
    listOfRentals = "";
}

// Constructor
Account::Account(string id, string name, string address, string phoneNumber, string listOfRental) {
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
    string Account::getID() { return this->id; }
    string Account::getName() { return this->name; }
    string Account::getAddress() { return this->address; }
    string Account::getPhoneNumber() { return this->phoneNumber; }
    string Account::getListOfRentals() { return this->listOfRentals; }

    // Setter Functions
    void Account::setID(string id) { this->id = id; }
    void Account::setName(string name) { this->name = name; }
    void Account::setAddress(string address) { this->address = address; }
    void Account::setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
    void Account::setListOfRentals(string listOfRentals) { this->listOfRentals = listOfRentals; }


    // Default Constructor
    GuessAccount::GuessAccount() {
        id = "";
        name = "";
        address = "";
        phoneNumber = "";
        listOfRentals = "";
    }
    // Constructor
    GuessAccount::GuessAccount(string id, string name, string address, string phoneNumber, string listOfRentals) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->listOfRentals = listOfRentals;
    }
    // Deconstructor
    GuessAccount::~GuessAccount(){}


    // Getter Fuctions
    string GuessAccount::getID() { return this->id; }
    string GuessAccount::getName() { return this->name; }
    string GuessAccount::getAddress() { return this->address; }
    string GuessAccount::getPhoneNumber() { return this->phoneNumber; }
    string GuessAccount::getListOfRentals() { return this->listOfRentals; }

    // Setter Functions
    void GuessAccount::setID(string id) { this->id = id; }
    void GuessAccount::setName(string name) { this->name = name; }
    void GuessAccount::setAddress(string address) { this->address = address; }
    void GuessAccount::setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
    void GuessAccount::setListOfRentals(string listOfRentals) { this->listOfRentals = listOfRentals; }

    // class RegularAccount inherits from class AccounT

    RegularAccount::RegularAccount(){}
    RegularAccount::RegularAccount(string id, string name, string address, string phoneNumber, string listOfRentals) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->listOfRentals = listOfRentals;
    }

    RegularAccount::~RegularAccount(){}

    VipAccount::VipAccount(){}

    VipAccount::VipAccount(string id, string name, string address, string phoneNumber, string listOfRentals) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->listOfRentals = listOfRentals;
    }

    VipAccount::~VipAccount() {}

    // Getter Fuctions
    string VipAccount::getID() { return this->id; }
    string VipAccount::getName() { return this->name; }
    string VipAccount::getAddress() { return this->address; }
    string VipAccount::getPhoneNumber() { return this->phoneNumber; }
    string VipAccount::getListOfRentals() { return this->listOfRentals; }

    // Setter Functions
    void VipAccount::setID(string id) { this->id = id; }
    void VipAccount::setName(string name) { this->name = name; }
    void VipAccount::setAddress(string address) { this->address = address; }
    void VipAccount::setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
    void VipAccount::setListOfRentals(string listOfRentals) { this->listOfRentals = listOfRentals; }


  