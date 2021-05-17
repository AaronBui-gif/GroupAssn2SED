#pragma once

#ifndef TESTING_ITEMLIST_H
#define TESTING_ITEMLIST_H
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class ItemList {
private:
	/*** Declare variables ***/
	vector<Item*> itemList;
	int numItems;
	int id;
	string filename;

public:
	ItemList(string filename);
	ItemList();
	ItemList(vector<Item*> itemList, int id, int numItems);
	~ItemList();

	//--Getters--
	vector<Item*> getItemList();
	int getNumItem();

	//--Setters--
	void setItemList(vector<Item*> itemlist);
	void setNumItem(int itemNum);

	//--Ability to operate with files--
	//1. Add, update and delete items
	void addItem();
	void addItem(Item* item);
	void updateItem();
	bool delItem(int itemPos);
	void delItem();

	//2. 
	void modifyStock(int index, int modifyBy);
	void addStockNum();
	bool getDatas();

	//3. Search methods
	int searchID(string id);

	//4. Sorting methods
	void sortID();
	void sortTitle();

	//5. Display and search methods
	void displayAll();

	//--Assisting functions--
	bool isValid(string id);
	string convertLower(string input);
	string generateItemID(int publishYear);
};

#endif