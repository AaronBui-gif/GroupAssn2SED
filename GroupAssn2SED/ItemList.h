#pragma once

#ifndef TESTING_ITEMLIST_H
#define TESTING_ITEMLIST_H
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class ItemList {
public:
	/*** Declare variables ***/
	vector<Item*> itemList;
	int numItems;
	int id;
	string filename;

	ItemList(string filename);
	ItemList();
	ItemList(vector<Item*> itemList, int id, int numItems);
	~ItemList();
	void addItem(Item* item);
	bool getDatas();
};
#endif