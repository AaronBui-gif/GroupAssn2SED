#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;

class AccountList {
private:
	vector<string> accountList;
	int numCopies;
	string filename;
	int id;
public:
	AccountList();
	AccountList(string filename);
	AccountList(vector<string> accountList, int numCopies, int id);
	~AccountList();
	void addAccount(Account* account);
	void deleteAccount(Account* account);
	bool getDatas();
};