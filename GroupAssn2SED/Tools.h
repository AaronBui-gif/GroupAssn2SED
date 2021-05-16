#pragma once

#include <iostream>
#include <string>

using namespace std;

// To lower case
string toLowerCase(string input);

// Numeric to-string functions
int strToInt(string str);
float strToFloat(string str);

string intToStr(int num);
string intToStr(int num, int length);
string floatToStr(float num);