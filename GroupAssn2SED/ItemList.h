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
	int id;


	ItemList();
	ItemList(vector<Item*> itemList, int id);
	~ItemList();
	vector<Item*> addItem(vector<Item*> itemList);
};
#endif