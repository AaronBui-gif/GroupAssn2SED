/*** Libraries ***/
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

// Default Constructor
Item::Item() {}

// Constructor
Item::Item(string id, string title, LoanType loanType, int stock, float rentalFee) {
	this->id = id;
	this->title = title;
	this->loanType = loanType;
	this->stock = stock;
	this->rentalFee = rentalFee;
}

// Destructor
Item::~Item() {
	cout << "All copies of this item are removed." << endl;
}

// Getters
/*** Get id ***/
string Item::getID() {
	return this->id;
}

/*** Get title ***/
string Item::getTitle() {
	return this->title;
}

/*** Get genre ***/
Genre Item::getGenre() {
	return this->genre;
}

/*** Get loan type ***/
LoanType Item::getLoanType() {
	return this->loanType;
}

/*** Get stock ***/
int Item::getStock() {
	return this->stock;
}

/*** Get rental fee ***/
float Item::getFee()
{
	return this->rentalFee;
}

/*** Get status ***/
Status Item::getStatus() {
	return this->status;
}

// Setters
/*** Set id ***/
void Item::setID(string id) {
	this->id = id;
	return;
}

/*** Set title ***/
void Item::setTitle(string title) {
	this->title = title;
	return;
}

/*** Set genre ***/
void Item::setGenre(Genre genre) {
	if (genre == Genre::ACTION) {
		this->genre = Genre::ACTION;
	}
	if (genre == Genre::HORROR) {
		this->genre = Genre::HORROR;
	}
	if (genre == Genre::DRAMA) {
		this->genre = Genre::DRAMA;
	}
	if (genre == Genre::COMEDY) {
		this->genre = Genre::COMEDY;
	}
	else
		this->genre = Genre::UNSPECIFIED;
}

/*** Set loan type ***/
void Item::setLoanType(LoanType loanType) {
	if (loanType == LoanType::TWO_DAY) {
		this->loanType = LoanType::TWO_DAY;
	}
	else
		this->loanType = LoanType::ONE_WEEK;
}

/*** Set stock ***/
void Item::setStock(int stock) {
	this->stock = stock;
	return;
}

/*** Set rental fee ***/
void Item::setRentalFee(float rentalFee) {
	this->rentalFee = rentalFee;
	return;
}

/*** Set status ***/
void Item::setStatus(Status status) {
	if (status == Status::AVAILABLE) {
		this->status = Status::AVAILABLE;
	}
	else
		this->status = Status::BORROWED;
}

/*** Update number of copies of this item ***/
bool Item::updateCopies(int num) {
	// Modify number of copies in stock
	this->stock += num;

	// Print message
	cout << "Successfully added " << num << ". " << this->title << " currently has: " << this->stock << endl;

	return true;
}

/*** Display all information of this item ***/
string Item::itemToString() {
	return "ID = " + this->id + ", title = " + this->title + ", rental type = " + rentalTypeToString(this->getRentalType()) + ", genre = " + genreToString(this->getGenre()) + ", loan type = " + loanTypeToString(this->getLoanType()) + ", copies = " + intToStr(this->stock) + ", rental fee = " + floatToStr(this->rentalFee) + ", status = " + statusToString(this->getStatus());
}

// Default Constructor
MovieRecord::MovieRecord() {}

// Constructor
MovieRecord::MovieRecord(string id, string title, LoanType loanType, Genre genre, int stock, float rentalFee) : Item(id, title, loanType, stock, rentalFee) {
	this->genre = genre;
}

// Constructor
DVD::DVD() {}

// Constructor
DVD::DVD(string id, string title, LoanType loanType, Genre genre, int stock, float rentalFee) : Item(id, title, loanType, stock, rentalFee) {
	this->genre = genre;
}

// Constructor
VideoGame::VideoGame() {}

// Constructor
VideoGame::VideoGame(string id, string title, LoanType loanType, int stock, float rentalFee) : Item(id, title, loanType, stock, rentalFee) {
	this->genre = Genre::UNSPECIFIED;
}

/*** Convert string to loan type ***/
LoanType strToLoanType(string str) {
	if (str == "1-week") {
		return LoanType::ONE_WEEK;
	}
	else {
		return LoanType::ONE_WEEK;
	}
}

/*** Convert string to genre ***/
Genre strToGenre(string str) {
	if (str.compare("Comedy") == 0 || str.compare("Comedy") == 1) {
		return Genre::COMEDY;
	}
	if (str.compare("Action") == 0 || str.compare("Action") == 1) {
		return Genre::ACTION;
	}
	if (str.compare("Horror") == 0 || str.compare("Horror") == 1) {
		return Genre::HORROR;
	}
	if (str.compare("Drama") == 0 || str.compare("Drama") == 1) {
		return Genre::DRAMA;
	}
	else {
		return Genre::UNSPECIFIED;
	}
}
/*** Convert rental type to string ***/
string rentalTypeToString(RentalType rentalType) {
	switch (rentalType) {
	case RentalType::MOVIE_RECORD: {
		return "Record";
	}
	case RentalType::DVD: {
		return "DVD";
	}
	case RentalType::VIDEO_GAME: {
		return "Game";
	}
	default: {
		return "UNSPECIFIED";
	}
	}
}

/*** Convert status to string ***/
string statusToString(Status status) {
	switch (status) {
	case Status::BORROWED: {
		return "BORROWED";
	}
	default: {
		return "AVAILABLE";
	}
	}
}

/*** Convert loan type to string ***/
string loanTypeToString(LoanType loanType) {
	switch (loanType) {
	case LoanType::ONE_WEEK: {
		return "1-week";
	}
	default: {
		return "2-day";
	}
	}
}

/*** Convert genre to string ***/
string genreToString(Genre genre) {
	switch (genre) {
	case Genre::ACTION: {
		return "Action";
	}
	case Genre::HORROR: {
		return "Horror";
	}
	case Genre::DRAMA: {
		return "Drama";
	}
	case Genre::COMEDY: {
		return "Comedy";
	}
	default: {
		return "UNSPECIFIED";
	}
	}
}

void Item::displayAllItems() {
	cout << "ID = " << this->getID()
		 << ", title = " << this->getTitle()
		 << ", rental type = " << rentalTypeToString(this->getRentalType())
		 << ", genre = " << genreToString(this->getGenre())
		 << ", loan type = " << loanTypeToString(this->getLoanType())
		 << ", copies = " << this->getStock()
		 << ", rental fee = " << this->getFee()
		 << ", status = " << statusToString(this->getStatus());
}
