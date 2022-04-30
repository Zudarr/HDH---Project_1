#include "ReadData.h"

#include <vector>

using namespace std;


int ReadData(LPCWSTR  drive, int readPoint, BYTE* sector, int bytes)
{
	int retCode = 0;
	DWORD bytesRead;
	HANDLE device = NULL;
	device = CreateFile(drive,    // Drive to open
		GENERIC_READ,           // Access mode
		FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
		NULL,                   // Security Descriptor
		OPEN_EXISTING,          // How to create
		0,                      // File attributes
		NULL);                  // Handle to template

	if (device == INVALID_HANDLE_VALUE) // Open Error
	{
		printf("CreateFile: %u\n", GetLastError());

		return 1;
	}

	SetFilePointer(device, readPoint, NULL, FILE_BEGIN);//Set a Point to Read

	if (!ReadFile(device, sector, bytes, &bytesRead, NULL))
	{
		printf("ReadFile: %u\n", GetLastError());

	}
}


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


uint64_t LE_read_reverse( uint8_t* start_byte, string Hex_offset,unsigned int total )
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


void print_txt_data( byte* data)
{
	if(data!=nullptr)
	{
		char* output = (char*)data;
		string text(output);
		cout << text;
	}
	
}


std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}