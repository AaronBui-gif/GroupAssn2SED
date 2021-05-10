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

    //Function 
};

class GuessAccount :public Account {
protected:
    string id;
    string name;
    string address;
    string phoneNumber;
    string listOfRentals;
public:
    GuessAccount();
    GuessAccount(string id, string name, string address, string phoneNumber, string listOfRentals);
    ~GuessAccount();
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
};

// class RegularAccount inherits from class Account
class RegularAccount :public Account {
protected:
    string id = 0;
    string name = "";
    string address = "";
    string phoneNumber = "";
    string listOfRentals = 0;
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
};

// class VipAccount inherits from class Account
class VipAccount :public Account {
protected:
    string id = 0;
    string name = "";
    string address = "";
    string phoneNumber = "";
    string listOfRentals = 0;
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
};
#endif //TESTING_ACCOUNT_H
