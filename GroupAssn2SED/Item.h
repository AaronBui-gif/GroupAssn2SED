#pragma once

/*** Libraries ***/
#include <iostream>
#include <string>

using namespace std;

enum class RentalType { MOVIE_RECORD, DVD, VIDEO_GAME, UNSPECIFIED };

enum class Status { BORROWED, AVAILABLE };

enum class Genre { ACTION, HORROR, DRAMA, COMEDY, UNSPECIFIED };

enum class LoanType { TWO_DAY, ONE_WEEK };

class Item {
private:
	// Declare variables
	string id = "";
	string title = "";
	LoanType loanType = LoanType::TWO_DAY;
	int stock = 0;
	float rentalFee = 0;
	Status status = Status::AVAILABLE;

public:
	Genre genre = Genre::UNSPECIFIED;
	// Default constructor
	Item();

	// Constructor
	Item(string id, string title, LoanType loanType, int stock, float rentalFee);

	// Destructors
	~Item();

	// Getters
	string getID();
	string getTitle();
	Genre getGenre();
	LoanType getLoanType();
	int getStock();
	float getFee();
	Status getStatus();

	// Setters
	void setID(string id);
	void setTitle(string title);
	void setGenre(Genre genre);
	void setLoanType(LoanType loanType);
	void setStock(int stock);
	void setRentalFee(float rentalFee);
	void setStatus(Status status);

	virtual RentalType getRentalType() const = 0;

	bool updateCopies(int num);
	string itemToString();

	void displayAllItems();
};

/*** Class Movie Record inherits from class Item ***/
class MovieRecord : public Item {
public:
	// Default Constructor
	MovieRecord();

	// Constructor
	MovieRecord(string id, string title, LoanType loanTye, Genre genre, int stock, float rentalFee);

	// Override
	RentalType getRentalType() const {
		return RentalType::MOVIE_RECORD;
	}
};

/*** Class DVD inherits from class Item ***/
class DVD : public Item {
public:
	// Default Constructor
	DVD();

	// Constructor
	DVD(string id, string title, LoanType loanType, Genre genre, int stock, float rentalFee);

	// Override
	RentalType getRentalType() const {
		return RentalType::DVD;
	}
};

/*** Class VideoGmae inherits from class Item ***/
class VideoGame : public Item {
public:
	// Default Constructor
	VideoGame();

	// Constructor
	VideoGame(string id, string title, LoanType loanType, int stock, float rentalFee);

	// Override
	RentalType getRentalType() const {
		return RentalType::VIDEO_GAME;
	}
};

string rentalTypeToString(RentalType rentalType);
string statusToString(Status status);
string loanTypeToString(LoanType loanType);
string genreToString(Genre genre);
int strToInt(string str);
float strToFloat(string str);

string intToStr(int num);
string intToStr(int num, int length);
string floatToStr(float num);