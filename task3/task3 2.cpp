#include <iostream>
using namespace std;
int main() 
{
	char *b = new char[8];//��̬����64bits�ڴ�

	*(int*)b = 2147483647;
	*(int*)(b + 4) = (-2147483647 - 1);
	cout << "1st Round:" << endl;
	cout << "["<< *(int*)b << "," << *(int*)(b + 4) <<"]"<< endl;//��һ������

	*(unsigned short*)b = 65525;
	*(unsigned short*)(b+2)= 65524;
	*(unsigned short*)(b+4) = 65523;
	*(unsigned short*)(b + 6) = 65522;
	cout << "2st Round:" << endl;
	cout << "[" << *(unsigned short*)b << "," << *(unsigned short*)(b + 2) << "," << *(unsigned short*)(b + 4) << "," << *(unsigned short*)(b + 6) << "]" << endl;//�ڶ�������

	*(char*)b = -128;
	*(unsigned short*)(b + 1) = 34811;
	*(unsigned char*)(b + 3) = 255;
	*(unsigned int*)(b + 4) = 4294967295;
	cout << "3st Round:" << endl;
	cout << "[" << (int)*b << "," << *(unsigned short*)(b + 1) << "," << (int)*(unsigned char*)(b + 3) << "," << *(unsigned int*)(b + 4) << "]" << endl;//����������

	*b = 'A';
	strcpy_s(b + 1, 7, "hello!\0");
	cout << "4st Round:" << endl;
	cout << "[" << "'"<<*b << "'"<<"," <<"\""<< *(b + 1) <<*(b+2)<<*(b+3)<<*(b+4)<<*(b+5)<<*(b+6)<<"\\0"<<"\""<<"]"<< endl;//����������

	delete[]b;
	return 0;
	
}