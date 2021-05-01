//
// Created by Huy Bui Thanh on 27/04/2021.
//

#ifndef TESTING_ACCOUNT_H
#define TESTING_ACCOUNT_H


class Account {
private:
    int id;
    string name;
    string address
        string phoneNumber;
    int listOfRentals;
    string type;
public:
    Account();
    Account(string id, string name, string address, string phone);

    ~Account();

    // Getter Functions
    string getID();
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


#endif //TESTING_ACCOUNT_H
