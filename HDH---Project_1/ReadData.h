#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <Windows.h>
using namespace std;

int ReadData(LPCWSTR drive, int readPoint, BYTE* sector, int bytes);// thêm tham số bytes cần đọc -> đây không còn là hàm đọc sector nên t đổi tên
int hexCharToInt(char a);
string hexToString(std::string str);
string ReadtoString(BYTE* data, string offsetHex, unsigned int bytes);
uint64_t LE_read_reverse( uint8_t* start_byte, string Hex_offset,unsigned int total );   //tên hàm cũ : ReadIntReverse
void print_txt_data( byte* data); // tên hàm cũ : void printTextData(byte* data, int size);
std::wstring s2ws(const std::string& s);