/*** Libraries ***/
#include <iostream>
#include <string>
#include "Item.h"
#include "ItemList.h"
#include "Account.h"
#include "AccountList.h"

using namespace std;

/*** Calling functions ***/
void displayMembers();
void displayMenu();
void getOptions(ItemList* itemList, AccountList* accountList);

/*** Main function ***/
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Error input argument. It should contain 3 argument." << endl;
        return -1;
    }

    // Create item list file from the command line argument
    ItemList* itemList = new ItemList(argv[1]);

    // Import items from file
    //itemList->importItems();

    // Create account list file from the command line argument
    AccountList* accountList = new AccountList(argv[2]);

    // Import accounts from file
    //accountList->importAccounts();

    // Call process menu
    getOptions(itemList, accountList);

    // Delete vectors
    delete itemList;
    delete accountList;

    return 0;
}

/*** Function to exit program and display group members ***/
void displayMembers() {
    cout << "Closing Genie's video store app" << endl << "Good bye!!!" << endl;
    cout << "*************************************************" << endl;
    cout << "ASSIGNMENT 2 GROUP 3" << endl;
    cout << "s3740934, s3740934@rmit.edu.vn, Huy, Bui Thanh" << endl;
    cout << "s3764704, s3764704@rmit.edu.vn, Hoang, Nguyen Huy" << endl;
    cout << "s3795370, s3795370@rmit.edu.vn, Dung, Ho Minh" << endl;
    cout << "s3799602, s3799602@rmit.edu.vn, Tri, Lai Nghiep" << endl;
    cout << "s3879052, s3879052@rmit.edu.vn, Long, Nguyen Dich" << endl;
    cout << "*************************************************" << endl;
}

/*** Function to display menu in command window ***/
void displayMenu() {
    cout << "********************************" << endl;
    cout << "Welcome to Genie's video store" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add a new item" << endl;
    cout << "2. Update an existing item" << endl;
    cout << "3. Delete an existing item" << endl;
    cout << "4. Add new customer" << endl;
    cout << "5. Add new customer" << endl;
    cout << "6. Update an existing customer" << endl;
    cout << "7. Promote an existing customer" << endl;
    cout << "8. Rent an item" << endl;
    cout << "9. Return an item" << endl;
    cout << "10. Display all items sort by ID" << endl;
    cout << "11. Display all items sort by name" << endl;
    cout << "12. Display out-of-stock items" << endl;
    cout << "13. Display all customers sort by ID" << endl;
    cout << "14. Display all customers sort by name" << endl;
    cout << "15. Display guest customers" << endl;
    cout << "16. Display regular customers" << endl;
    cout << "17. Display VIP customers" << endl;
    cout << "18. Search items or customers" << endl;
    cout << "Exit" << endl << endl;
}

/*** Function to process menu ***/
void getOptions(ItemList* itemList, AccountList* accountList) {
    /*** Declare variables ***/
    string input = "";

    while (true) {
        /*** Display Menu ***/
        displayMenu();

        /*** Get user input ***/
        cout << "Select: ";
        getline(cin, input);


        if (input.compare("1") == 0) {
            itemList->addItem();
        }

        // If input is 2: Update an existing item
        else if (input.compare("2") == 0) {
            itemList->updateItem();
        }

        // If input is 3: Delete an existing item
        else if (input.compare("3") == 0) {
            itemList->delItem();
        }

        // If input is 4: Increase number of stocks of existing items
        else if (input.compare("4") == 0) {
            itemList->addStockNum();
        }

        // If input is 5: Add new customer
        else if (input.compare("5") == 0) {
            //accountList->addAccount();
        }

        // If input is 6: Update an existing customer
        else if (input.compare("6") == 0) {
            //accountList->updateAccount();
        }

        // If input is 7: Promote an existing customer
        else if (input.compare("7") == 0) {
            //accountList->promote();
        }

        // If input is 8: Rent an item
        else if (input.compare("8") == 0) {
            //accountList->borrowedItem(itemList);
        }

        // If input is 9: Return an item
        else if (input.compare("9") == 0) {
            //accountList->returnedItem(itemList);
        }

        // If input is 10: Display all items sort by ID
        else if (input.compare("10") == 0) {
            cout << endl;
            itemList->sortID();
            itemList->displayAll();
        }

        // If input is 11: Display all items sort by title
        else if (input.compare("11") == 0) {
            cout << endl;
            itemList->sortTitle();
            itemList->displayAll();
        }

        // If input is 12: Display out-of-stock items
        else if (input.compare("12") == 0) {
            //cout << endl;
            //itemList->displayOutOfStockItems();
        }

        // If input is 13: Display all customers sort by ID
        else if (input.compare("13") == 0) {
            //cout << endl;
            //accountList->sortID();
            //accountList->displayGuests();
            //accountList->displayRegulars();
            //accountList->displayVIPs();
        }

        // If input is 14: Display all customers sort by name
        else if (input.compare("14") == 0) {
            //cout << endl;
            //accountList->sortName();
            //accountList->displayGuests();
            //accountList->displayRegulars();
            //accountList->displayVIPs();
        }

        // If input is 15: Display guest customers
        else if (input.compare("15") == 0) {
            //cout << endl;
            //accountList->displayGuests();
        }

        // If input is 16: Display regular customers
        else if (input.compare("16") == 0) {
            //cout << endl;
            //accountList->displayRegulars();
        }

        // If input is 17: Display VIP customers
        else if (input.compare("17") == 0) {
            //cout << endl;
            //accountList->displayVIPs();
        }

        // If input is 18: Search items or customers
        else if (input.compare("18") == 0) {

            // Enter selection to search items or customers
            while (true) {
                cout << endl << "Enter an option below to search items or customers." << endl;
                cout << "1. Search items" << endl;
                cout << "2. Search customers" << endl;
                cout << "3. Return to menu" << endl;

                /*** Get user input ***/
                cout << "Select: ";
                getline(cin, input);

                // If input = 1: Search items
                if (input.compare("1") == 0) {
                    while (true) {
                        // Enter selection to search by ID or title
                        cout << endl << "Enter an option below to search by ID or title." << endl;
                        cout << "1. Search by ID" << endl;
                        cout << "2. Search by title" << endl;
                        cout << "3. Return to menu" << endl;

                        // Get user input
                        cout << "Select: ";
                        getline(cin, input);

                        // If input = 1: Search by ID
                        if (input.compare("1") == 0) {
                            /*itemList->displaysearchID();
                            break;*/
                        }
                        // If input = 1: Search by title
                        else if (input.compare("2") == 0) {
                           /* itemList->displaysearchTitle();
                            break;*/
                        }
                        else if (input.compare("3") == 0) {
                            cout << "Returning to menu " << endl;
                            cout << "**********************************************" << endl;
                            break;
                        }
                        else {
                            cout << "Invalid search category selection." << endl;
                            continue;
                        }
                    }
                }

                // If input = 2: Search accounts
                else if (input.compare("2") == 0) {
                    while (true) {
                        cout << endl << "Enter an option below to search by ID or title." << endl;
                        cout << "1. Search by ID" << endl;
                        cout << "2. Search by name" << endl;
                        cout << "3. Return to menu" << endl;

                        // Get user input
                        cout << "Select: ";
                        getline(cin, input);

                        // If input = 1: Search by ID
                        if (input.compare("1") == 0) {
                            //accountList->displaysearchID();
                            break;
                        }

                        // If input = 2: Search by name
                        else if (input.compare("2") == 0) {
                            //accountList->displaysearchName();
                            break;
                        }

                        // If input = 3: Return to menu
                        else if (input.compare("3") == 0) {
                            cout << "Returning to menu" << endl;
                            cout << "***************************************" << endl;
                            break;
                            break;
                        }

                        // Others are error
                        else {
                            cout << "Input is incorrect. Please enter again" << endl;
                            continue;
                        }
                    }
                }

                // If input = 3: Return to menu
                else if ((input.compare("3") == 0)) {
                    cout << "Returning to menu" << endl;
                    cout << "*************************" << endl;
                    break;
                }

                // Others are error
                else {
                    cout << "Invalid input. Please enter again" << endl;
                    continue;
                }
            }
        }

        // If user input Exit
        else if (input == "Exit" || input == "exit" || input == "EXIT") {
            displayMembers();
            break;
        }

        // If user input is empty
        else if (input.empty()) {
            cout << "Input cannot be empty. Please enter again." << endl;
        }
    }
}