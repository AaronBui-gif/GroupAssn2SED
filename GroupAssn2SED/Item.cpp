//
// Created by Huy Bui Thanh on 27/04/2021.
//

#include "Item.h"

using namespace std;
class Item {
private:
    int id;
    string title;
    string rentType;
    string loanType;
    int numberOfCopies;
    float fee;
    string genre;
    Status status{
        AVAILABLE,
        BORROWED
    };

public:
    /*** GETTER ***/
    int getID() const { return id; }
    string getTitle() const { return title; }
    string getRentType() const { return returnType; }
    string getLoanType() const { return loanType; }
    int getNumberOfCopies() const { return numberOfCopies; }
    float getFee() const { return fee; }
    string getGenre() const { return genre; }
    Status getStatus() { return this->status; }

    /*** SETTER ***/
    void setID(int id) { this->id = id; }
    void setTitle(string title) { this->title = title; }
    void setRentType(string rentType) { this->rentType = rentType; }
    void setLoanType(string loanType) { this->loanType = loanType; }
    void setNumberOfCopies(int numberOfCopies) { this->numberOfCopies = numberOfCopies; }
    void setFee(float fee) { this->fee = fee; }
    void setGenre(string genre) { this->genre = genre; }
    void setStatus(Status status) {
        if (status == Status::AVAILABLE) {
            this->status = Status::AVAILABLE;
        }
        else {
            this->status = Status::BORROWED;
        }
    }
};
