#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a[23] = { 0 }, b[100] = { 0 }, c[32] = { 0 }, d[8] = { 0 };
	int i = 0, j, e = 0, int_x, n, p;
	float x, dot;
	cin >> x;

	if (x < 0)
	{
		c[0] = 1;
		x = -x;
	}
	else c[0] = 0;
	int_x = (int)x;
	dot = x - (int)x;

	if (int_x == 0)
	{
		for (i = 0; i < 23; i++)
		{
			dot = dot * 2;
			if (dot == 1)
			{
				b[i] = 1; break;
			}
			if (dot > 1)
			{
				b[i] = 1;
				dot = dot - 1;
			}
			else b[i] = 0;
		}
		for (j = 0; j < 23; j++)
			if (b[j] != 0)
			{
				e = 126 - j;
				break;
			}
		for (i = 8; i > 0; i--)
		{
			c[i] = e % 2;
			e = e / 2;
		}
		j = 0;
		for (n = 9; n < 32; n++)
		{
			c[n] = b[j];
			j++;
		}
		cout << "0x";
		for (i = 0; i < 8; i++)
		{
			d[i] = c[4 * i] * 8 + c[4 * i + 1] * 4 + c[4 * i + 2] * 2 + c[4 * i + 3];
			if (d[i] > 9)
			{
				n = d[i] % 9;
				switch (n)
				{
				case 1:cout << "a"; break;
				case 2:cout << "b"; break;
				case 3:cout << "c"; break;
				case 4:cout << "d"; break;
				case 5:cout << "e"; break;
				case 6:cout << "f"; break;
				}
			}
			else cout << d[i];
		}
	}

	if (int_x != 0)
	{
		do {
			a[i] = int_x % 2;
			int_x = int_x / 2;
			i++;
		} while (int_x != 0);
		e = --i + 127;
		for (j = 8; j > 0; j--)
		{
			c[j] = e % 2;
			e = e / 2;
		}
		for (p = 0; p < 23; p++)
		{
			dot = dot * 2;
			if (dot == 1) {
				b[p] = 1;
				break;
			}
			if (dot > 1)
			{
				b[p] = 1;
				dot = dot - 1;
			}
			else b[p] = 0;
		}
		j = 9;
		for (i--; i >= 0; i--)
		{
			c[j] = a[i];
			j++;
		}
		i = 0;
		for (; j < 32; j++)
		{
			c[j] = b[i];
			i++;
			if (j == 31) break;
		}
		cout << "0x";
		for (i = 0; i < 8; i++)
		{
			d[i] = c[4 * i] * 8 + c[4 * i + 1] * 4 + c[4 * i + 2] * 2 + c[4 * i + 3];
			if (d[i] > 9)
			{
				n = d[i] % 9;
				switch (n)
				{
				case 1:cout << "a"; break;
				case 2:cout << "b"; break;
				case 3:cout << "c"; break;
				case 4:cout << "d"; break;
				case 5:cout << "e"; break;
				case 6:cout << "f"; break;
				}
			}
			else cout << d[i];
		}
		}
}
