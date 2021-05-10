#include <iostream>
#include <fstream>
#include "Account.h"
#include "AccountList.h"

using namespace std;

AccountList::AccountList() {}

AccountList::AccountList(string filename) {
	this->filename = filename;
}

AccountList::AccountList(vector<string> accountList, int numCopies, int id) {
	this->accountList = accountList;
	this->numCopies = numCopies;
	this->id = id;
}

AccountList::~AccountList(){}

bool AccountList::getDatas() {

}