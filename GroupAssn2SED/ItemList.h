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
	void addItem(Item* item);
	void updateItem();
	bool delItem(int itemPos);
	void delItem();

	void modifyStock(int index, int modifyBy);
	void addStockNum();
	bool getDatas();

	int searchByID(string id);

	//--Assisting functions--
	bool isValid(string id);
};
#endif