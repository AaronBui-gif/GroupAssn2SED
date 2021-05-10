//
// Created by Huy Bui Thanh on 27/04/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Item.h"
#include "ItemList.h"
#include "AccountList.h"

using namespace std;

bool isNumber(const string& num);
bool getDatas(string filename, Item item1, string filename2);
void printMenu();
void getOption();

/*** MAIN FUNCTION ***/
int main(int argc, char* argv[]) {
    /*** Declare variables ***/
    Item item1;
    bool get_datas;
    if (argc != 3) {
        cout << "Must contain 3 arguments" << endl;
        return -1;
    }

    string filename1 = argv[2];
    string filename2 = argv[1];
    ItemList itemlist(filename1);
    AccountList accountList(filename2);
    accountList.getDatas();
    printMenu();
    getOption();
  
    
}

/*** FUNCTION to check if a number ***/
bool isNumber(string& num) {
    string::const_iterator it = num.begin();
    while (it != num.end() && isdigit(*it)) ++it;
    return !num.empty() && it == num.end();
}

/*** FUNCTION to print out menu ***/
void printMenu() {
    cout << endl << "******************************" << endl
        << "Welcome to Genie’s video store" << endl
        << "Enter an option below." << endl
        << "1.Add a new item, update or delete an existing item" << endl
        << "2.Add new customer or update an existing customer" << endl
        << "3.Promote an existing customer" << endl
        << "4.Rent an item" << endl
        << "5.Return an item" << endl
        << "6.Display all items" << endl
        << "7.Display out-of-stock items" << endl
        << "8.Display all customers" << endl
        << "9.Display group of customers" << endl
        << "10.Search items or customers" << endl
        << "Exit." << endl;
}

/*** FUNCTION to get input option from the user ***/
void getOption() {
    // Declare variables
    ItemList itemList;
    string input;
    string input2;
    int num{};
    int num1{};
    do {
        cin >> input;
        if (isNumber(input) == true) {
           num= stoi(input);
        }
        if (input == "1") {
            cout << "1. Add a new item" << endl;
            cout << "2. Update an item" << endl;
            cout << "3. Delete an item" << endl;
            cout << "4. Return to menu" << endl;
            do {
                cin >> input2;
                if (isNumber(input2) == true) {
                    num1 = stoi(input2);
                }
                if (input2 == "1") {
                    string inputID, inputTitle, inputRent, inputLoan;
                    int inputNumCopies;
                    float inputFee;
                    string inputGenre;
                    Type getRentType;
                    Genre getGenre;
                    string inputStatus;
                    Status getStatus;
                    cout << "Enter rent type: ";
                    cin >> inputRent;
                    cout << endl;
                    if (inputRent == "record" | inputRent == "Record" || inputRent == "RECORD" || inputRent == "records"| inputRent == "Records" || inputRent == "RECORDS") {
                        getRentType = Type::Record;
                    }
                    else if (inputRent == "dvd" | inputRent == "Dvd" || inputRent == "DVD") {
                        getRentType = Type::DVD;
                    }
                    else if (inputRent == "game" | inputRent == "Game" || inputRent == "GAME") {
                        getRentType = Type::Game;
                    }
                    else {
                        cout << "Invalid rent input" << endl;
                        break;
                    }
                    if (inputRent == "record" | inputRent == "Record" || inputRent == "RECORD" || inputRent == "records" | inputRent == "Records" || inputRent == "RECORDS" || inputRent == "dvd" | inputRent == "Dvd" || inputRent == "DVD") {
                        cout << "Enter an id: ";
                        cin >> inputID;
                        //if (itemList.validateID(inputID) == true) { 
                        cout << endl;
                        cout << "Enter the title: ";
                        cin >> inputTitle;
                        cout << endl;
                        cout << "Enter loan type: ";
                        cin >> inputLoan;
                        cout << endl;
                        cout << "Enter number of copies: ";
                        cin >> inputNumCopies;
                        cout << endl;
                        cout << "Enter rental fee: ";
                        cin >> inputFee;
                        cout << endl;
                        cout << "Enter Genre: ";
                        cin >> inputGenre;
                        if (inputGenre == "action" || inputGenre == "Action" || inputGenre == "ACTION") {
                            getGenre = Genre::Action;
                        }
                        else if (inputGenre == "horror" || inputGenre == "Horror" || inputGenre == "HORROR") {
                            getGenre = Genre::Horror;
                        }
                        else if (inputGenre == "drama" || inputStatus == "Drama" || inputStatus == "DRAMA") {
                            getGenre = Genre::Drama;
                        }
                        else if (inputGenre == "comedy" || inputGenre == "Comedy" || inputGenre == "COMEDY") {
                            getGenre = Genre::Comedy;
                        }
                        else {
                            cout << "Invalid input for genre" << endl;
                            break;
                        }
                        cout << endl;
                        cout << "Enter rental status: ";
                        cin >> inputStatus;
                        if (inputStatus == "available" || inputStatus == "Available" || inputStatus == "AVAILABLE") {
                            getStatus = Status::AVAILABLE;
                        }
                        else if (inputStatus == "borrowed" || inputStatus == "Borrowed" || inputStatus == "BORROWED") {
                            getStatus = Status::BORROWED;
                        }
                        else {
                            cout << "Invalid input for status" << endl;
                            break;
                        }
                        cout << endl;
                        itemList.addItem(new Item(inputID, inputTitle, getRentType, inputLoan, inputNumCopies, inputFee, getGenre));
                    }
                    else {
                        cout << "Enter an id: ";
                        cin >> inputID;
                        //if (itemList.validateID(inputID) == true) { 
                        cout << endl;
                        cout << "Enter the title: ";
                        cin >> inputTitle;
                        cout << endl;
                        cout << "Enter loan type: ";
                        cin >> inputLoan;
                        cout << endl;
                        cout << "Enter number of copies: ";
                        cin >> inputNumCopies;
                        cout << endl;
                        cout << "Enter rental fee: ";
                        cin >> inputFee;
                        cout << endl;
                        cout << "Enter rental status: ";
                        cin >> inputStatus;
                        if (inputStatus == "available" || inputStatus == "Available" || inputStatus == "AVAILABLE") {
                            getStatus = Status::AVAILABLE;
                        }
                        else if (inputStatus == "borrowed" || inputStatus == "Borrowed" || inputStatus == "BORROWED") {
                            getStatus = Status::BORROWED;
                        }
                        else {
                            cout << "Invalid input for status" << endl;
                            break;
                        }
                        cout << endl;
                        itemList.addItem(new Item(inputID, inputTitle, getRentType, inputLoan, inputNumCopies, inputFee));
                    }
                }
                else if (input2 == "2") {

                }
                else if (input2 == "3") {

                }
                else if (input2 == "4") {
                    cout << "Returning to menu" << endl;
                    cout << "*************************************************************************" << endl;

                    break;
                }
            } while (num1 < 1 & num1 > 4);
        }
        else if (input == "2") {

        }
        else if (input == "3") {

        }
        else if (input == "4") {

        }
        else if (input == "5") {

        }
        else if (input == "6") {

        }
        else if (input == "7") {

        }
        else if (input == "8") {

        }
        else if (input == "9") {

        }
        else if (input == "10") {

        }
        else if (input == "Exit" || input == "exit") {
            cout << "Closing Genie's video store app" << endl;
            cout << "Good Bye" << endl;
            cout << "*********************************************************************************************************" << endl;
            break;
        }
    } while (num < 1 && num > 10);
}

