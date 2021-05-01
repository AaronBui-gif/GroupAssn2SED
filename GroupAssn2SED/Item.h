//
// Created by Huy Bui Thanh on 27/04/2021.
//

#ifndef TESTING_ITEM_H
#define TESTING_ITEM_H


class Item {
private:
    int id;
    string title;
    string rentType;
    string loanType;
    int numberOfCopies;
    float fee;
    string genre;
public:
    int getID();
    string getTitle();
    string getRentType();
    string getLoanType();
    int getNumberOfCopies();
    float getFee();
    string getGenre();

    void setID(int id);
    void setTitle(string title);
    void setRentType(string rentType);
    void setLoanType(string loanType);
    void setNumberOfCopies(int numberOfCopies);
    void setFee(float fee);
    void setGenre(string genre);

};


#endif //TESTING_ITEM_H
