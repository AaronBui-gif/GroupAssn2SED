#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;

enum AccountType;
class AccountList {
private:
	vector<Account*> accountList;
	int numAccount;
	string filename;
	AccountType accountType;
	int id;
public:
	AccountList();
	AccountList(string filename);
	AccountList(vector<Account*> accountList, int numAccount, int id, AccountType accountType);
	~AccountList();
	void addAccount(Account* account);
	bool updateAccount(Account* account);
	bool validateAccount(string input);
	bool promoteAccount(enum AccountType);
	bool getDatas();
};