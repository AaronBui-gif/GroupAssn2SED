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

	//1. Update ID
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

		//If ID exist in the items.txt
		if (!this->searchByID(input)) {
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

		//Check if non-integer exist
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

	//4. Update genre
	Genre genre = tempItemList[itemIndex]->getGenre();
	
	
	while (true) {

		//In case none of bugs found in Genre then 
		//break the loop and move to update the title.
		break;
	}
}

//--Search by ID--
bool ItemList::searchByID(string id) {
	vector<Item*> tempItemList = this->getItemList();
	int num = this->getNumItem();

	for (int index = 0; index < num; index++) {
		if (tempItemList[index]->getID() == id) return true;
	}

	return false;
}


 void ItemList::delItem(int itemPos) {
	//Create a temp vector as a copy of the vector ItemList
	vector<Item*> tempItemList = this->getItemList();

	//Delete the item at specific position
	tempItemList.erase(tempItemList.begin() + itemPos);
	
	//Update the ItemList and its number
	this->setItemList(tempItemList);
	this->setNumItem(this->getNumItem() - 1);
 }

 void ItemList::addStockNum() {

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