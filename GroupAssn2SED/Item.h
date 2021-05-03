//
// Created by Huy Bui Thanh on 27/04/2021.
//

#ifndef TESTING_ITEM_H
#define TESTING_ITEM_H

#include <iostream>
#include <string>
enum Type;
enum Status;
enum Genre;

using namespace std;

class Item {
public:
    int id;
    string title;
    Type rentType;
    string loanType;
    int numberOfCopies;
    float fee;
    Genre genre;
    Status status;

    Item();
    Item(int id, string title, Type rentType, string loanType, int numberOfCopies, float fee, Genre genre, Status status);
    ~Item();
    int getID();
    string getTitle();
    Type getRentType();
    string getLoanType();
    int getNumberOfCopies();
    float getFee();
    Genre getGenre();
    Status getStatus();

    void setID(int id);
    void setTitle(string title);
    void setRentType(Type rentType);
    void setLoanType(string loanType);
    void setNumberOfCopies(int numberOfCopies);
    void setFee(float fee);
    void setGenre(Genre genre);
    void setStatus(Status status);
};


#endif //TESTING_ITEM_H
