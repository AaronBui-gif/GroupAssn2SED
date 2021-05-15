#ifndef TESTING_ITEM_H
#define TESTING_ITEM_H

#include <iostream>
#include <string>
enum class Status { AVAILABLE, BORROWED };

enum class Type { Record, DVD, Game };

enum class Genre { Action, Horror, Drama, Comedy };

enum class LoanType { TWO_DAY, ONE_WEEK };

using namespace std;

class Item {
private:
    string id;
    string title;
    Type rentType;
    LoanType loanType;
    int numberOfCopies;
    float fee;
    Genre genre;
    Status status;
public:
    Item();
    Item(string id, string title, Type rentType, LoanType loanType, int numberOfCopies, float fee, Genre genre);
    Item(string id, string title, Type rentType, LoanType loanType, int numberOfCopies, float fee);
    ~Item();
    string getID();
    string getTitle();
    Type getRentType();
    LoanType getLoanType();
    int getNumberOfCopies();
    float getFee();
    Genre getGenre();
    Status getStatus();

    void setID(string id);
    void setTitle(string title);
    void setRentType(Type rentType);
    void setLoanType(LoanType loanType);
    void setNumberOfCopies(int numberOfCopies);
    void setFee(float fee);
    void setGenre(Genre genre);
    void setStatus(Status status);

};


#endif //TESTING_ITEM_H
