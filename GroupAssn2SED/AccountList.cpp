#include <iostream>
#include <fstream>
#include "Account.h"
#include "AccountList.h"
#include <sstream>
using namespace std;

enum AccountType {
	Regular,
	Guest,
	Vip
};

AccountList::AccountList() {}

AccountList::AccountList(string filename) {
	this->filename = filename;
}

AccountList::AccountList(vector<Account*> accountList, int numAccount, int id, AccountType accountType) {
	this->accountList = accountList;
	this->numAccount = numAccount;
	this->id = id;
	this->accountType = accountType;
}

AccountList::~AccountList(){}

bool AccountList::getDatas() {
	/*** Variables ***/
	ifstream accountFile(this->filename);
	string line;
	vector<string> datas;

	/*** File cannot be found ***/
	if (!accountFile) {
		cerr << "Cannot open a file" << endl;
		return false;
	}

	/*** Read one line each time in file***/
	while (getline(accountFile, line))
	{
		istringstream ss(line);
		string word;
		string array[6];
		int i = 0;
		bool cont = false;
		cout << "Line: " << endl;
		cout << line << endl;
		while (getline(ss, word, ',')) { // Read indivial word in line separated by comma
			
			if (i == 0) {
				char character = word.at(0);
				if (character == 'C') { // If the first word is Cxxx then allow array to insert words.
					cont = true;
				}
				else { // else don't
					cont = false;
				}
			}
			if (cont == true) { // boolean is true then array is inserted.
				array[i] = word;				
				i++;			
				if (i == 5) { i = 0; }
			}
			
		}
		cout << "Array" << endl;
		for (int y = 0; y < 6; y++)
		{
			cout << array[y] << " ";
		}
		cout << endl;
		if (array[5] == "VIP") {
			VipAccount* vipaccount = new VipAccount(array[0], array[1], array[2], array[3], array[4]);
			this->id++;
		}
		else if (array[5] == "Guess") {
			GuessAccount* guessaccount = new GuessAccount(array[0], array[1], array[2], array[3], array[4]);
			this->id++;
		}
		else if (array[5] == "Regular") {
			RegularAccount* account = new RegularAccount(array[0], array[1], array[2], array[3], array[4]);
			this->id++;
		}
	}
	return true;
}

/*** FUNCTION to add account ***/
void AccountList::addAccount(Account* account) {
	this->accountList.push_back(account);
	this->numAccount++;
	this->id++;
}

/*** FUNCTION to update account in database (e.g text files) ***/
bool AccountList::updateAccount(Account* account) {
	ofstream writeAccount("customers.txt");
	if (!writeAccount) {
		cerr << "Cannot open file to write" << endl;
		return false;
	}
	writeAccount.write((char*)&account, sizeof(account));
	return true;
}

/*** FUNCTION to validate id of user input ***/
bool AccountList::validateAccount(string input) {
	if (input.length() != 4 || input[0] != 'C') {
		cout << "Account id format is wrong." << endl;
		cout << "Please enter at this format: Cxxx" << endl;
		return false;
	}

	for (int i = 1; i < 4; i++)
	{
		if (isdigit(input[i]) == false) {
			return false;
		}
	}
	return true;
}

/*** FUNCTION to promote a Guest to Regular ***/
bool AccountList::promoteAccount(AccountType accountType) {
	if (accountType == AccountType::Guest) {
		cout << "Your account was promoted from Guest to Regular account" << endl;
		this->accountType = AccountType::Regular;
		return true;
	}
	else if (accountType == AccountType::Regular) {
		cout << "Your account was promoted from Regular to VIP account" << endl;
		this->accountType = AccountType::Vip;
		return true;
	}
	else {
		return false;
	}
}

