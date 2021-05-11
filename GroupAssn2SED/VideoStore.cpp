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
bool getUserInputForAddItem();
bool getUserInputForAddAccount();
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
    AccountList accountList;
    string input;
    string input2;
    string input3;
    int num{};
    int num1{};
    int num2{};
    while (true) {
        cin >> input;
        if (isNumber(input) == true) {
            num = stoi(input);
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
                    bool executeOption1 = getUserInputForAddItem();
                    if (executeOption1 == true) {
                        cout << "Add item successfully" << endl;
                        printMenu();
                        break;
                    }
                    else {
                        cout << "Add item fail" << endl;
                        printMenu();
                        break;
                    }
                }
                else if (input2 == "2") {

                    break;
                }
                else if (input2 == "3") {

                    break;
                }
                else if (input2 == "4") {
                    cout << "Returning to menu" << endl;
                    cout << "*************************************************************************" << endl;
                    printMenu();
                    break;
                }
            } while (num1 < 1 & num1 > 4);
        }
        else if (input == "2") {
            cout << "1. Add a new account" << endl;
            cout << "2. Update an account" << endl;
            do {
                cin >> input3;
                if (isNumber(input3) == true) {
                    num2 = stoi(input3);
                }
                if (input3 == "1") {
                    bool executeOption2 = getUserInputForAddAccount();
                    if (executeOption2 == true) {
                        cout << "Add account successfully" << endl;
                        printMenu();
                        break;
                    }
                    else {
                        cout << "Add account fail" << endl;
                        printMenu();
                        break;
                    }
                }
            } while (num2 < 1 & num2 > 4);
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
            accountList.displayAllAccount();
        }
        else if (input == "10") {

        }
        else if (input == "Exit" || input == "exit") {
            cout << "Closing Genie's video store app" << endl;
            cout << "Good Bye" << endl;
            cout << "*********************************************************************************************************" << endl;
            break;
        }
    }
}

bool getUserInputForAddItem() {
    string inputID, inputTitle, inputRent, inputLoan;
    int inputNumCopies;
    float inputFee;
    string inputGenre;
    Type getRentType;
    Genre getGenre;
    string inputStatus;
    Status getStatus;
    ItemList itemList;
    cout << "Enter rent type: ";
    cin >> inputRent;
    cout << endl;
    if (inputRent == "record" | inputRent == "Record" || inputRent == "RECORD" || inputRent == "records" | inputRent == "Records" || inputRent == "RECORDS") {
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
        return false;
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
            return false;
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
        itemList.addItem(new Item(inputID, inputTitle, getRentType, inputLoan, inputNumCopies, inputFee));
    }
    return true;
}

bool getUserInputForAddAccount() {
    string id, name, address, phoneNumber, listOfRentals;
    AccountList accountList;
    cout << "Enter id for user: ";
    cin >> id;
    // validate user ID;
    cout << endl;
    cout << "Enter name for user: ";
    cin >> name;
    cout << endl;
    cout << "Enter address for user: ";
    cin >> address;
    cout << endl;
    cout << "Enter phone number for user: ";
    cin >> phoneNumber;
    cout << endl;
    cout << "List of Rentals: ";
    cin >> listOfRentals;
    cout << endl;
    accountList.addAccount(new Account(id, name, address, phoneNumber, listOfRentals));
    return true;
}