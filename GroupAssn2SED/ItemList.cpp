/***  Calling libraries ***/
#include "ItemList.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Item.h"

using namespace std;

ItemList::ItemList(string filename) {
	this->filename = filename;
}

ItemList::ItemList(){
	vector<Item*> itemList = {};
	id = 0;
}

ItemList::ItemList(vector<Item*> itemList, int id, int numItems) {
	this->itemList = itemList;
	this->id = id;
	this->numItems = numItems;
}

ItemList::~ItemList(){}

//--Setters--
void ItemList::setItemList(vector<Item*> itemlist) { this->itemList = itemlist; }
void ItemList::setNumItem(int itemNum) { this->numItems = itemNum; }

//--Getters--
vector<Item*> ItemList::getItemList() { return this->itemList; }
int ItemList::getNumItem() { return this->numItems; }

bool ItemList::getDatas() {
	return true;
}

//========================Ability functions==============================
//--Add items FUNCTIONS--
 void ItemList::addItem(Item* item) {
	this->itemList.push_back(item);
	this->numItems++;
	this->id++;
}

//--Update items FUNCTIONS--
void ItemList::updateItem() {
	vector<Item*> tempItemList = this->getItemList();
	string input = "";
	int itemIndex = 0;

	//1. Get the ID
	while (true) {
		cout << "-------------\nEnter item's ID need to update: ";
		getline(cin, input);

		//If input is empty
		if (input.empty()) {
			cerr << "Error: Input cannot be empty!" << endl;
			continue;
		}

		//ID validation
		if (!this->isValid(input)) {
			cerr << "Error: ID must follow the format Ixxx-yyyy." << endl;
			continue;
		}

		//Locating to the exact item
		itemIndex = this->searchByID(input);

		//If ID exist in the items.txt
		if (itemIndex == -1) {
			cerr << "Error: ID does not exist!" << endl;
			continue;
		}

		//In case none of bugs found in ID then break the loop
		//and move to update the published year.
		break;
	}

	//2. Update published year
	int pub_year = 0;

	while (true) {
		cout << "-------------\nEnter published year need to update OR press Enter to skip: ";
		getline(cin, input);

		//Press Enter to skip
		if (input.empty()) break;

		//Check length of year (yyyy)
		if (input.length() != 4) {
			cerr << "Error: Year's length must be 4" << endl;
			continue;
		}

		//Check non-integer validation
		for (char& ch : input) {
			if (!isdigit(ch)) {
				cerr << "Error: All element in year must be integer!" << endl;
				continue;
			}
		}

		//Check year range
		if (input.compare("2021") > 0 || input.compare("1900") < 0) {
			cerr << "Error: year must from 1900 - 2021" << endl;
			continue;
		}

		//Update the new ID
		string new_id = tempItemList[itemIndex]->getID();
		new_id = new_id.substr(0, 5) + input;
		tempItemList[itemIndex]->setID(new_id);

		//Update ItemList
		this->setItemList(tempItemList);

		//In case none of bugs found in published year then 
		//break the loop and move to update the title.
		break;
	}

	//3. Update title
	while (true) {
		cout << "-------------\nEnter Title need to update OR press Enter to skip: ";
		getline(cin, input);

		//Press Enter to skip
		if (input.empty()) break;

		//Set new title
		tempItemList[itemIndex]->setTitle(input);

		//Update ItemList
		this->setItemList(tempItemList);

		//In case none of bugs found in title then 
		//break the loop and move to update the title.
		break;
	}

	//4. Update the loan type
	while (true) {
		cout << "-------------\nEnter Loan type need to update OR press Enter to skip: ";
		cout << "1. Two days" << endl << "2. One week" << endl;
		getline(cin, input);

		// Press Enter to skip
		if (input.empty()) break;

		if (input == "1") {
			//Change the loan type
			tempItemList[itemIndex]->setLoanType(LoanType::TWO_DAY);

			//Update ItemList
			this->setItemList(tempItemList);

			break;
		}

		if (input == "2") {
			//Change the loan type
			tempItemList[itemIndex]->setLoanType(LoanType::ONE_WEEK);

			//Update ItemList
			this->setItemList(tempItemList);

			break;
		}

		// Print error message
		cerr << "Error: Invalid selection input!" << endl;
	}

	//5. Update quantity
	while (true) {
		cout << "-------------\nEnter the amount of copies need to update OR press Enter to skip: ";
		getline(cin, input);

		//Press Enter to skip
		if (input.empty()) break;

		//Check non-integer validation
		for (char& ch : input) {
			if (!isdigit(ch)) {
				cerr << "Error: Number of copies must be integer!" << endl;
				continue;
			}
		}

		//Add new stock copies
		tempItemList[itemIndex]->setNumberOfCopies(stoi(input));

		//Update ItemList
		this->setItemList(tempItemList);

		//In case none of bugs found then break 
		//the loop and move to update the title.
		break;
	}

	//6. Update rental fee
	int flag = 0;
	while (true) {
		cout << "-------------\nEnter the rental fee need to update OR press Enter to skip: ";
		getline(cin, input);

		//Press Enter to skip
		if (input.empty()) break;

		// Check non - integer validation
			for (char& ch : input) {
				if (!isdigit(ch)) {
					if (ch == '.') flag++;
					else flag--;
				}
			}

		if (flag != 1) {
			cerr << "Error: Fee must be float!" << endl;
			flag = 0;
			continue;
		}


		//Add new rental fee
		tempItemList[itemIndex]->setFee(stof(input));

		//Update ItemList
		this->setItemList(tempItemList);

		//In case none of bugs found then break 
		//the loop and move to update the title.
		break;
	}

	//7. Update genre
	Genre genre = tempItemList[itemIndex]->getGenre();
	Type type = tempItemList[itemIndex]->getRentType();
	
	if (type == Type::Record || type == Type::DVD) {
		while (true) {
			cout << "Which Genre you need to update OR press Enter to exit to menu bar:" << endl;
			cout << "1. Action" << endl;
			cout << "2. Horror" << endl;
			cout << "3. Drama" << endl;
			cout <<	"4. Comedy" << endl;
			getline(cin, input);

			// If input is empty	
			if (input.empty()) break;


			// Get genre based on user selection
			if (input == "1"){
				genre = Genre::Action;
				break;
			}

			if (input == "2"){
				genre = Genre::Horror;
				break;
			}

			if (input == "3"){
				genre = Genre::Drama;
				break;
			}

			if (input == "4"){
				genre = Genre::Comedy;
				break;
			}

			cout << "Invalid selection input!" << endl;
		}

		// Set the genre in item list
		tempItemList[itemIndex]->setGenre(genre);

		// Update the ItemList
		this->setItemList(tempItemList);
	}
}

//--Delete Item with given position--
bool ItemList::delItem(int itemPos) {
	//Create a temp vector as a copy of the vector ItemList
	vector<Item*> tempItemList = this->getItemList();

	//Delete the item at specific position
	tempItemList.erase(tempItemList.begin() + itemPos);

	//Update the ItemList and its number
	this->setItemList(tempItemList);
	this->setNumItem(this->getNumItem() - 1);
	return true;
}

//--Delete Item--
void ItemList::delItem() {
	vector<Item*> tempItemList = this->getItemList();
	int itemIndex = 0;
	string input = "";

	while (true) {
		cout << "-------------\nEnter Item's ID to delete: " << endl;
		getline(cin, input);

		// Check if input is not empty
		if (input.empty()) {
			cerr << "Error: IDs cannot be empty." << endl;
			continue;
		}

		//ID validation
		if (!this->isValid(input)) {
			cerr << "Error: ID must follow the format Ixxx-yyyy." << endl;
			continue;
		}

		//Locating to the exact item
		itemIndex = this->searchByID(input);

		//In case ID not exist
		if (itemIndex == -1) {
			cerr << "Error: ID does not exist!" << endl;
			continue;
		}

		//In case none of bugs found then break the loop
		//and move to choosing deleting options.
		break;
	}

	// Choose to delete item or copies of that item
	while (true) {
		// Prompt user to choose a number
		cout << "-------------\nWhich options do you want to delete?" << endl;
		cout << "1. Remove the entire item" << endl
			<< "2. Remove copies" << endl;
		cout << "Selection: ";
		getline(cin, input);

		// Delete the entire item with its index
		if (input == "1") {
			this->delItem(itemIndex);
			break;
		}

		//Delete the copies
		if (input == "2") {
			// Flag to detect illegal character when error checking integer
			bool flag = true;

			// Loop does not break until a valid input is inserted
			while (true) {
				cout << "-------------\nEnter number of copies to delete: ";
				getline(cin, input);

				// Check if string is empty
				if (input.empty()) {
					cerr << "Error: Input cannot be empty!" << endl;
					continue;
				}

				// Check if string only contains digits
				for (char& ch : input) {
					if (!isdigit(ch)) {
						flag = false;
						break;
					}
				}

				// If flag is false meaning that a character is not a digit
				if (flag == false) {
					cerr << "Error: Invalid number of copies input." << endl;

					// Reset flag
					flag = true;
					continue;
				}

				// Check if current copy is smaller than the user input
				if (tempItemList[itemIndex]->getNumberOfCopies() < stoi(input)) {
					cerr << "Error: Your input need to larger than the current copy!" << endl
						 << "Current copy: " << tempItemList[itemIndex]->getNumberOfCopies() << endl;
					continue;
				}
				break;
			}

			// Provoking function to delete copies
			this->modifyStock(itemIndex, -stoi(input));
			break;
		}

		// Print error message
		cerr << "Error: Invalid selection input!" << endl;
	}
}

//--Increase number of copies--
void ItemList::addStockNum() {

}

void ItemList::modifyStock(int index, int modifyBy) {
	vector<Item*> tempItemList = this->getItemList();

	// Create a copy of the current number of copies in stock
	int currentCopy = tempItemList[index]->getNumberOfCopies();

	// If add in stock
	if (modifyBy >= 0) {
		// Increase the current copy
		tempItemList[index]->setNumberOfCopies(currentCopy + modifyBy);

		// Check if item is now available
		if (tempItemList[index]->getNumberOfCopies() >= 1) {
			// Change to Available status
			tempItemList[index]->setStatus(Status::AVAILABLE);
		}
	}

	// If remove in stock
	else {
		// Check status of item if number of copies in stock = 0
		if (tempItemList[index]->getNumberOfCopies() == 0)
			// Change to Borrowed status
			tempItemList[index]->setStatus(Status::BORROWED);

		else {
			// Remove copies from the copy
			tempItemList[index]->setNumberOfCopies(currentCopy + modifyBy);

			// Check if item is now out of stock
			if (tempItemList[index]->getNumberOfCopies() == 0)
				// Set status of item to borrowed
				tempItemList[index]->setStatus(Status::BORROWED);
		}
	}

	// Set the vector of item points as the copy
	this->setItemList(tempItemList);
}

//--Search by ID--
int ItemList::searchByID(string id) {
	vector<Item*> tempItemList = this->getItemList();
	int num = this->getNumItem();

	for (int index = 0; index < num; index++) {
		if (tempItemList[index]->getID() == id) return index;
	}

	return -1;
}


//========================Assisting functions==============================
//--ID Validation--
bool ItemList::isValid(string id) {
	//Check length
	if (id.length() != 9) return false;

	//Check prefix character
	if (id[0] != 'I' || id[4] != '-') return false;

	//Check publish year (1900-2021)
	if (stoi(id.substr(5, 9)) > 2021 || stoi(id.substr(5, 9)) < 1900) return false;

	//Check if any non-integer character exist, except 'I' and '-'
	for (char& ch : id) {
		if (ch == 'I' || ch == '-') continue;
		if (!isdigit(ch)) return false;
	}
	return true;
}