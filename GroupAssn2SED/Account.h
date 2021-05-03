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
    int id;
    string name;
    string address;
    string phoneNumber;
    int listOfRentals;
public:
    Account();
    Account(int id, string name, string address, string phone, int listOfRentals);

    ~Account();

    // Getter Functions
    int getID();
    string getName();
    string getAddress();
    string getPhoneNumber();
    int getListOfRentals();

    // Setter Functions
    void setID();
    void setName();
    void setAddress();
    void setPhoneNumber();
    void setListOfRentals();

    //Function 
};

class GuessAccount :public Account {
protected:
    int id;
    string name;
    string address;
    string phoneNumber;
    int listOfRentals;
public:
    GuessAccount();
    GuessAccount(int id, string name, string address, string phoneNumber, int listOfRentals);
    ~GuessAccount();
};

// class RegularAccount inherits from class Account
class RegularAccount :public Account {
protected:
    int id = 0;
    string name = "";
    string address = "";
    string phoneNumber = "";
    int listOfRentals = 0;
public:
    RegularAccount();
    RegularAccount(int id, string name, string address, string phoneNumber, int listOfRentals);
    ~RegularAccount();
};

// class VipAccount inherits from class Account
class VipAccount :public Account {
protected:
    int id = 0;
    string name = "";
    string address = "";
    string phoneNumber = "";
    int listOfRentals = 0;
public:
    VipAccount();
    VipAccount(int id, string name, string address, string phoneNumber, int listOfRentals);
    ~VipAccount();
};
#endif //TESTING_ACCOUNT_H
