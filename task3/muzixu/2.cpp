#include<iostream>
#include<string>
using namespace std;
int main()
{
	void *m=operator new(8);
	int *p=reinterpret_cast<int*>(m);
	p[0] = 2147483647; p[1] = -2147483647; p[1]--;
	cout << p[0] << " " << p[1] << endl;
	unsigned short *q=reinterpret_cast<unsigned short*>(p);
	q[0] = 65525; q[1] = 65524; q[2] = 65523; q[3] = 65522;
	cout << q[0] << " " << q[1] << " " << q[2] << " " << q[3]<<endl;
	char *a = reinterpret_cast<char*>(m);
	*a = char(-128);
	unsigned short*b = reinterpret_cast<unsigned short*>(a+sizeof(char));
	*b = 34811;
	unsigned char*c = reinterpret_cast<unsigned char*>(b+sizeof(unsigned short));
	*c = unsigned char(255);
	unsigned int*d = reinterpret_cast<unsigned int*>(c+sizeof(char));
	*d = 4294967295;
	cout <<short(*a) <<" "<< *b <<" "<<short(*c) <<" "<< *d << endl;
	a = reinterpret_cast<char*>(m);
	*a='A';
	char *w=reinterpret_cast<char*>(a+sizeof(char));
    *w='H';*(w+1)='e';*(w+2)='l';*(w+3)='l';*(w+4)='o';*(w+5)='!';*(w+6)='\0';
	cout<<*a<<' ';
	while (*w!='\0'){cout<<*w;w++;}
	cout<<endl;
return 0;
}