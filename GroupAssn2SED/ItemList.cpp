/***  Calling libraries ***/
#include "ItemList.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Item.h"

using namespace std;

ItemList::ItemList(){
	vector<Item*> itemList = {};
	id = 0;
}

ItemList::ItemList(vector<Item*> itemList, int id) {
	this->itemList = {};
	this->id = id;
}

ItemList::~ItemList(){}

vector<Item*> ItemList::addItem(vector<Item*> itemList) {

	return itemList;
}

