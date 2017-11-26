#include <iostream>
#include <string.h>
using namespace std;
int main() {
	char *b = new char[8];

	*(reinterpret_cast<int*>(b)) = 2147483647;
	*(reinterpret_cast<int*>(b + 4)) = (-2147483647 - 1);
	cout << "1st Round:" << endl;
	cout << "["<< *(reinterpret_cast<int*>(b)) << "," << *(reinterpret_cast<int*>(b + 4))  <<"]"<< endl;//第一轮输出

	*(reinterpret_cast<unsigned short*>(b)) = 65525;
	*(reinterpret_cast<unsigned short*>(b+2)) = 65524;
	*(reinterpret_cast<unsigned short*>(b + 4)) = 65523;
	*(reinterpret_cast<unsigned short*>(b + 6)) = 65522;
	cout << "2st Round:" << endl;
	cout << "[" << *(reinterpret_cast<unsigned short*>(b)) << "," << *(reinterpret_cast<unsigned short*>(b + 2))
		<< "," << *(reinterpret_cast<unsigned short*>(b + 4)) << "," << *(reinterpret_cast<unsigned short*>(b + 6)) << "]" << endl;;//第二轮输出

	*(reinterpret_cast<char*>(b)) = -128;
	*(reinterpret_cast<unsigned short*>(b + 1)) = 34811;
	*(reinterpret_cast<unsigned char*>(b + 3) )= 255;
	*(reinterpret_cast<unsigned int*>(b + 4)) = 4294967295;
	cout << "3st Round:" << endl;
	cout << "[" << (int)*(reinterpret_cast<char*>(b)) << "," << *(reinterpret_cast<unsigned short*>(b + 1)) << ","
		<< (int)(*(reinterpret_cast<unsigned char*>(b + 3))) << "," << *(reinterpret_cast<unsigned int*>(b + 4)) << "]" << endl;;//第三轮输出
	
	*b = 'A';
	strcpy_s(b + 1, 7, "hello!\0");
	cout << "4st Round:" << endl;
	cout << "[" << "'"<<*b << "'"<<"," <<"\""<< *(b + 1) <<*(b+2)<<*(b+3)<<*(b+4)<<*(b+5)<<*(b+6)<<"\\0"<<"\""<<"]"<< endl;;//第四轮输出

	delete[]b;
	return 0;
	
}
