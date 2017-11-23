#include<iostream>
using namespace std;
void Binary(float a1) 
{
	unsigned int* pa = nullptr;
	pa = (unsigned int*)&a1;
	cout << hex << "a=0x" << *pa << endl;
}

int main() 
{
	float a = 3.14159;
	Binary(a);
}