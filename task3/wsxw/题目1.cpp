#include<iostream>
using namespace std;
int main()
{
	int m = 0, n = 0, i;
	float a;
	int A[101], B[101];
	cout << "ÇëÊäÈëaµÄÖµ:";
	cin >> a;
	int p = int(a);
	float q = a - p;
	while (p != 0) {
		if (p % 2 == 0)A[m] = 0;
		else A[m] = 1;
		p = p / 2;
		m++;
	}
	while (q != 0) {
		if (q * 2 < 1) {
			B[n] = 0;
			q = q * 2;
			n++;
		}
		else {
			B[n] = 1;
			q = q * 2 - 1;
			n++;
		}
	}
	for (i = m - 1; i >= 0; i--)
		cout << A[i];
	cout << ".";
	for (i = 0; i < n; i++)
		cout << B[i];
	system("pause");
	return 0;
}