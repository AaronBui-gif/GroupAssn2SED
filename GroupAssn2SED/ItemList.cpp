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

bool ItemList::getDatas() {
	return true;
}

 void ItemList::addItem(Item* item) {
	this->itemList.push_back(item);
	this->numItems++;
	this->id++;
}
