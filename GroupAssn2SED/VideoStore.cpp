//
// Created by Huy Bui Thanh on 27/04/2021.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*** MAIN FUNCTION ***/
int main(int argc, char* argv[]) {
    printMenu();
    getOption();
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
    string input;
    do {
        getline(cin, input);
        if (input.compare("1")) {

        }
        else if (input.compare("1")) {

        }
        else if (input.compare("2")) {

        }
        else if (input.compare("3")) {

        }
        else if (input.compare("4")) {

        }
        else if (input.compare("5")) {

        }
        else if (input.compare("6")) {

        }
        else if (input.compare("7")) {

        }
        else if (input.compare("8")) {

        }
        else if (input.compare("9")) {

        }
        else if (input.compare("Exit")) {
            cout << "Closing Genie's video store app" << endl;
            cout << "Good Bye" << endl;
            cout << "******************************" << endl;
        }
        else {
            cout << "User's input is invalid" << endl;
            cout << "Please enter again" << endl;
        }
    } while (input < "1" && input > "10");
}
