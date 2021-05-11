//
// Created by Huy Bui Thanh on 27/04/2021.
//

#ifndef TESTING_ACCOUNT_H
#define TESTING_ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string id;
    string name;
    string address;
    string phoneNumber;
    string listOfRentals;
public:
    Account();
    Account(string id, string name, string address, string phone, string listOfRentals);

    ~Account();

    // Getter Functions
    string getID();
    string getName();
    string getAddress();
    string getPhoneNumber();
    string getListOfRentals();

    // Setter Functions
    void setID(string id);
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string phoneNumber);
    void setListOfRentals(string listOfRentals);

    string toString();
};

class GuestAccount :public Account {
protected:
    string id;
    string name;
    string address;
    string phoneNumber;
    string listOfRentals;
public:
    GuestAccount();
    GuestAccount(string id, string name, string address, string phoneNumber, string listOfRentals);
    ~GuestAccount();
    string getID();
    string getName();
    string getAddress();
    string getPhoneNumber();
    string getListOfRentals();

    // Setter Functions
    void setID(string id);
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string phoneNumber);
    void setListOfRentals(string listOfRentals);

    string toString();
};

// class RegularAccount inherits from class Account
class RegularAccount :public Account {
protected:
    string id = "";
    string name = "";
    string address = "";
    string phoneNumber = "";
    string listOfRentals = "";
public:
    RegularAccount();
    RegularAccount(string id, string name, string address, string phoneNumber, string listOfRentals);
    ~RegularAccount();

    string getID();
    string getName();
    string getAddress();
    string getPhoneNumber();
    string getListOfRentals();

    // Setter Functions
    void setID(string id);
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string phoneNumber);
    void setListOfRentals(string listOfRentals);

    string toString();
};

// class VipAccount inherits from class Account
class VipAccount :public Account {
protected:
    string id = "";
    string name = "";
    string address = "";
    string phoneNumber = "";
    string listOfRentals = "";
public:
    VipAccount();
    VipAccount(string id, string name, string address, string phoneNumber, string listOfRentals);
    ~VipAccount();

    string getID();
    string getName();
    string getAddress();
    string getPhoneNumber();
    string getListOfRentals();

    // Setter Functions
    void setID(string id);
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string phoneNumber);
    void setListOfRentals(string listOfRentals);

    string toString();
};
#endif //TESTING_ACCOUNT_H
