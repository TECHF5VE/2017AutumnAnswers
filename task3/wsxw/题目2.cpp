#include<iostream>
using namespace std;
int main()
{
	int *p;
	p = new int[2];
	p[0] = 2147483647; p[1] = -2147483647; p[1]--;
	cout << p[0] << " " << p[1] << endl;
	unsigned short *q = reinterpret_cast<unsigned short*>(p);
	q[0] = 65525; q[1] = 65524; q[2] = 65523; q[3] = 65522;
	cout << q[0] << " " << q[1] << " " << q[2] << " " << q[3] << endl;
	char *a = reinterpret_cast<char*>(q);
	a[0] = char(-128);
	unsigned short*b = reinterpret_cast<unsigned short*>(a + sizeof(char));
	*b = 34811;
	unsigned char*c = reinterpret_cast<unsigned char*>(b + sizeof(unsigned short));
	*c = unsigned char(255);
	unsigned int*d = reinterpret_cast<unsigned int*>(c + sizeof(unsigned char));
	*d = 4294967295;
	cout << (short)a[0] << " " << *b << " " << (short)*c << " " << *d << endl;
	char *e = reinterpret_cast<char*>(q);
	e[0] = 'A';
	cout << e[0]<<" ";
	char *f = reinterpret_cast<char*>(e + sizeof(char));
	f[0] = 'h'; f[1] = 'e'; f[2] = 'l'; f[3] = 'l'; f[4] = 'o'; f[5] = '!'; f[6] = '\0';
	int i = 0;
	while (i < 7) {
		cout << f[i];
		i++;
	}
	system("pause");
	return 0;
}