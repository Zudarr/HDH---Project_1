#include "ReadData.h"

int hexCharToInt(char a) {
	if (a >= '0' && a <= '9')
		return(a - 48);
	if (a >= 'A' && a <= 'Z')
		return(a - 55);
	return(a - 87);
}

string hexToString(string str) {
	stringstream HexString;
	for (int i = 0; i < str.length(); i++) {
		char a = str.at(i++);
		char b = str.at(i);
		int x = hexCharToInt(a);
		int y = hexCharToInt(b);
		HexString << (char)((16 * x) + y);
	}
	return HexString.str();
}


string ReadtoString(BYTE* data, string offsetHex, unsigned int bytes)
{
	const int offset = stoi(offsetHex, nullptr, 16);

	int len = offset + bytes;
	stringstream ss;
	ss << hex;
	for (int i = offset; i < len; i++)
	{
		ss << setw(2) << setfill('0') << (int)data[i];
		ss << " ";
	}
	string result;
	while (!ss.eof())
	{
		string temp;
		ss >> temp;
		result += hexToString(temp);
	}
	return result;
}

uint64_t LE_read_reverse( uint8_t* start_byte, string Hex_offset,unsigned int total )   //tên hàm cũ : ReadIntReverse
{
    // truyền vào tổng số byte cần đọc, toàn bộ offset, vị trí bắt đầu => giá trị cần đọc ở dạng decimal

	const int offset_byte = stoi(Hex_offset, nullptr, 16);

	start_byte = start_byte + offset_byte;
	uint64_t total_byte = 0;
	int i;
	for (i = total - 1; i >= 0; i--)
		total_byte = (total_byte << 8) | start_byte[i];

	return total_byte;
}
void print_txt_data( byte* data)  // tên hàm cũ : void printTextData(byte* data, int size);
{
	if(data!=nullptr)
	{
		output=(char*)data
		string text(output);

		cout << text;
	}
	
}