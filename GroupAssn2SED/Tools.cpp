#include "Tools.h"

/*** Convert string to all lower case ***/
string toLowerCase(string input)
{
	// Create an empty output string
	string output = "";

	// Iterate over string
	for (int i = 0; i < input.length(); i++)
	{
		// Convert each character to lower case and add to output string
		output = output + (char)tolower(input[i]);
	}

	return output;
}

/*** Convert string to integer ***/
int strToInt(string str)
{
	return stoi(str);
}

/*** Convert string to float ***/
float strToFloat(string str)
{
	return stof(str);
}

/*** Convert integer to string ***/
string intToStr(int num)
{
	return to_string(num);
}

/*** Convert integer to string and format string with a determinded string length ***/
string intToStr(int num, int length)
{
	// Convert integer to string
	string str = intToStr(num);

	// Add 0 to the beginning of string if needed
	while (str.length() < length)
	{
		str = "0" + str;
	}

	return str;
}

/*** Convert float to string ***/
string floatToStr(float num)
{
	return to_string(num);
}