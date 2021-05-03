//
// Created by Huy Bui Thanh on 27/04/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Item.h"

using namespace std;

bool isNumber(const string& num);
bool getDatas(string filename, Item item1, string filename2);
void printMenu();
void getOption();

/*** MAIN FUNCTION ***/
int main(int argc, char* argv[]) {
    /*** Declare variables ***/
    Item item1;
    if (argc != 3) {
        cout << "Must contain 3 arguments" << endl;
        return -1;
    }

    string filename1 = argv[1];
    string filename2 = argv[2];

    bool checkFile = getDatas(filename1, item1, filename2);
    if (checkFile == false) {
        return -1;
    }


    printMenu();
    getOption();
}

/*** FUNCTION to check if a number ***/
bool isNumber(string& num) {
    string::const_iterator it = num.begin();
    while (it != num.end() && isdigit(*it)) ++it;
    return !num.empty() && it == num.end();
}

/***  FUNCTION to  get datas from file txt ***/
bool getDatas(string filename, Item item1, string filename2) {
    string RECORD = "Record";
    string DVD = "DVD";
    int count = 0;
    vector<string>::iterator i;
    vector< vector<string>> data;
    ifstream inFile1(filename, ios::in | ios::binary);
    ifstream inFile2(filename2, ios::in | ios::binary);
    if (!inFile1) {
        cerr << "Cannot open file" << endl;
        return false;
    }
    else if (!inFile2) {
        cerr << "Cannot open file" << endl;
        return false;
    }
    while (inFile2){
        string s;
        if (!getline(inFile1, s)) break;
        cout << s << endl;
        istringstream stringstream(s);
        vector<string> record;

        while (stringstream) {
            string word;
            if (!getline(stringstream, word, ',')) {
                count++;
                if (count == 4) {
                    if (word == RECORD) {
                        
                    }
                    else if (word == DVD) {

                    }
                }
                break;
            }
            record.push_back(word);

            //cout << word << endl;
        }
        for (i = record.begin(); i < record.end(); i++)
        {
            cout << "i:" << *i << endl;
        }
    
        data.push_back(record);
 
    }
    return true;
}

/*** FUNCTION to print out menu ***/
void printMenu() {
    cout << endl << "******************************" << endl
        << "Welcome to Genie�s video store" << endl
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
    int num{};
    do {
        cin >> input;
        if (isNumber(input) == true) {
           num= stoi(input);
        }
        if (input == "1") {
            cout << "1" << endl;
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

