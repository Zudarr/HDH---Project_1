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
uint64_t LE_read_reverse( uint8_t* start_byte, string Hex_offset,unsigned int total );   //tên hàm cũ : ReadIntReverse
void print_txt_data( byte* data); // tên hàm cũ : void printTextData(byte* data, int size);