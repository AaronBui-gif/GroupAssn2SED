
//
// Created by Huy Bui Thanh on 27/04/2021.
//

#include "Item.h"
#include<iostream>
#include<string>

using namespace std;


Item::Item() {

}

//
Item::Item (string id, string title, Type rentType, string loanType, int numberOfCopies, float fee, Genre genre) {

    this->id = id;
    this->title = title;
    this->rentType = rentType;
    this->loanType = loanType;
    this->numberOfCopies = numberOfCopies;
    this->fee = fee;
    this->genre = genre;
    this->status = Status::AVAILABLE;
}

Item::Item(string id, string title, Type rentType, string loanType, int numberOfCopies, float fee) {

    this->id = id;
    this->title = title;
    this->rentType = rentType;
    this->loanType = loanType;
    this->numberOfCopies = numberOfCopies;
    this->fee = fee;
    this->status = Status::AVAILABLE;
}

Item::~Item(){}
    /*** GETTER ***/
    string Item::getID() { return this->id; }
    string Item::getTitle() { return this->title; }
    Type Item::getRentType() { return rentType; }
    string Item::getLoanType() { return loanType; }
    int Item::getNumberOfCopies() { return numberOfCopies; }
    float Item::getFee() { return fee; }
    Genre Item::getGenre() { return genre; }
    Status Item::getStatus() { return status; }

    /*** SETTER ***/
    void Item::setID(string id) { this->id = id; }
    void Item::setTitle(string title) { this->title = title; }
    void Item::setRentType(Type rentType) {
        if (rentType == Type::Record) {
            this->rentType = Type::Record;
        }
        else if (rentType == Type::Record) {
            this->rentType = Type::Record;
        }
        else if (rentType == Type::Game) {
            this->rentType = Type::Game;
        }
    }

    void Item::setLoanType(string loanType) { this->loanType = loanType; }
    void Item::setNumberOfCopies(int numberOfCopies) { this->numberOfCopies = numberOfCopies; }
    void Item::setFee(float fee) { this->fee = fee; }
    void Item::setGenre(Genre genre) { 
        if (genre == Genre::Action) {
            this->genre = Genre::Action;
        } 
        else if (genre == Genre::Horror) {
            this->genre = Genre::Horror;
        }
        else if (genre == Genre::Comedy) {
            this->genre = Genre::Comedy;
        }
        else if (genre == Genre::Drama) {
            this->genre = Genre::Drama;
        }
    }
    void Item::setStatus(Status status) {
        if (status == Status::AVAILABLE) {
            this->status = Status::AVAILABLE;
        }
        else {
            this->status = Status::BORROWED;
        }
    }

