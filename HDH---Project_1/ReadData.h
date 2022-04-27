#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <Windows.h>
using namespace std;

int hexCharToInt(char a);
string hexToString(std::string str);
string ReadtoString(BYTE* data, string offsetHex, unsigned int bytes);