#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	stack<char> binPower, binTail;		
	queue<char> binResult, binDecimal;	
	long long  power;				
	long long  inputInteger;		
	long long  output = 0;			
	double input, inputDecimal;		
	cout << "Enter a float:";
	cin >> input;

	if (input >= 0)
	{
		binResult.push(0);
	}
	else
	{
		binResult.push(1);
		input = -input;
	}

	inputInteger = (long long)input;
	inputDecimal = input - (double)inputInteger;

	if (inputInteger == 0)
	{
		power = -1;
	    if (inputDecimal == 0)
		{
			for (int i = 0; i < 24; i++)
			{
				binDecimal.push(0);
			}
		}
		else
		{
			while (binDecimal.size() != 24)
			{
				binDecimal.push((int)(inputDecimal * 2));
				inputDecimal = inputDecimal * 2 - (int)(inputDecimal * 2);
				if (binDecimal.front() == 0)
				{
					binDecimal.pop();
					--power;
				}
			}
			binDecimal.pop();
		}

		power += 127;
		while (power > 0)
		{
			binPower.push(power % 2);
			power /= 2;
		}
	}
	else
	{
		while (inputInteger > 0)
		{
			binTail.push(inputInteger % 2);
			inputInteger /= 2;
		}
		power = binTail.size() - 1 + 127;
		binTail.pop();
		int length = 23-binTail.size();
		for (int i = 0; i < length; i++)
		{
			binDecimal.push((int)(inputDecimal * 2));
			inputDecimal = inputDecimal * 2 - (int)(inputDecimal * 2);
		}

		while (power > 0)
		{
			binPower.push(power % 2);
			power /= 2;
		}

	}
	for (unsigned int i = 0; i < 8 - binPower.size(); ++i)
	{
		binResult.push(0);
	}
	while (!binPower.empty())
	{
		binResult.push(binPower.top());
		binPower.pop();
	}
	while (!binTail.empty())
	{
		binResult.push(binTail.top());
		binTail.pop();
	}
	while (!binDecimal.empty())
	{
		binResult.push(binDecimal.front());
		binDecimal.pop();
	}

	power = 2147483648;
	while (!binResult.empty())
	{
		output += binResult.front()*power;
		binResult.pop();
		power /= 2;
	}
	cout << "0x" << hex << output << endl << dec << endl;

	
	
	
	
	
	
	
	void *mem = operator new(8);
	int *ptr1_a, *ptr1_b;

	
	ptr1_a = static_cast<int*>(mem);
	ptr1_b = ptr1_a+1;
	*ptr1_a = ((unsigned)~0) >> 1;
	*ptr1_b = 1 << 31;
	cout << "第一轮：\n [" << *ptr1_a << ", " << *ptr1_b << "]\n";

	
	unsigned short *ptr2_a, *ptr2_b, *ptr2_c, *ptr2_d;
	ptr2_a = static_cast<unsigned short*>(mem);
	ptr2_b = ptr2_a+1;
	ptr2_c = ptr2_b+1;
	ptr2_d = ptr2_c+1;
	*ptr2_a = 65525;
	*ptr2_b = 65524;
	*ptr2_c = 65523;
	*ptr2_d = 65522;
	cout << "第二轮：\n [" << *ptr2_a << ", " << *ptr2_b << ", " << *ptr2_c << ", " << *ptr2_d << "]\n";

	
	char *ptr3_a;
	unsigned short *ptr3_b;
	unsigned char *ptr3_c;
	unsigned int *ptr3_d;
	ptr3_a = static_cast<char*>(mem);
	ptr3_b = reinterpret_cast<unsigned short*>(ptr3_a + 1);
	ptr3_c = reinterpret_cast<unsigned char*>(ptr3_b + 1);
	ptr3_d = reinterpret_cast<unsigned*>(ptr3_c + 1);
	*ptr3_a = -128;
	*ptr3_b = 34811;
	*ptr3_c = ~0;
	*ptr3_d = 4294967295;
	cout << "第三轮：\n [" << (int)*ptr3_a << ", " << *ptr3_b << ", " << (int)*ptr3_c << ", " << *ptr3_d << "]\n";

	
	char *ptr4_a;
	char *ptr4_b;
	ptr4_a = static_cast<char*>(mem);
	ptr4_b = ptr4_a+1;
	*ptr4_a = 'A';
	ptr4_b = "hello!\0";
	cout << "第四轮：\n [" << *ptr4_a << ", " << ptr4_b << "]\n";
	return 0;
}