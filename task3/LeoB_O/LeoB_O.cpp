#include <iostream>
#include <stack>
#include <queue>
using namespace std;


int main()
{
	/*****������תʮ���������*****/
	stack<char> binPower, binTail;		//������ָ����β��
	queue<char> binResult, binDecimal;	//�����ƽ����С��
	long long int power;				//ʮ���Ƶ�ָ����ֵ & ����������ÿλ�����Ƶ�Ȩ
	long long int inputInteger;			//�����ʮ���� ��������
	long long int output = 0;			//���
	double input, inputDecimal;			//�����Լ������С������
	cout << "Enter a float:";
	cin >> input;

	//����λ
	if (input >= 0)
	{
		binResult.push(0);
	}
	else
	{
		binResult.push(1);
		input = -input;
	}

	inputInteger = input;
	inputDecimal = input - inputInteger;

	//�����С��1.0����
	if (inputInteger == 0)
	{
		power = -1;
		//�����Ʊ���С����������������Ϊ0����Ҫȥ����ͷ��0
		if (inputDecimal == 0)
		{
			for (int i = 0; i < 24; i++)
			{
				binDecimal.push(0);
			}
		}
		//�����Ʊ���С����ȥ����ͷ��0
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

		//�����Ʊ���ָ��
		power += 127;
		while (power > 0)
		{
			binPower.push(power % 2);
			power /= 2;
		}
	}
	//����Ǵ��ڵ���1.0��С��
	else
	{
		//����β��
		while (inputInteger > 0)
		{
			binTail.push(inputInteger % 2);
			inputInteger /= 2;
		}
		power = binTail.size() - 1 + 127;
		binTail.pop();
		int length = 32 - binResult.size();
		for (int i = 0; i < length; i++)
		{
			binDecimal.push((int)(inputDecimal * 2));
			inputDecimal = inputDecimal * 2 - (int)(inputDecimal * 2);
		}

		//����ָ��
		while (power > 0)
		{
			binPower.push(power % 2);
			power /= 2;
		}

	}
	
	//������
	for (int i = 0; i < 8 - binPower.size(); ++i)
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

	//������תʮ����
	power = 2147483648;
	while (!binResult.empty())
	{
		output += binResult.front()*power;
		binResult.pop();
		power /= 2;
	}
	//ʮ���������
	cout << "0x" << hex << output << endl << dec << endl;

	
	/*****Dynamic Memory allocate*****/
	void *mem = operator new(8);
	int *ptr1_a, *ptr1_b;

	//��һ��
	ptr1_a = static_cast<int*>(mem);
	ptr1_b = ptr1_a + 1;
	*ptr1_a = ~0u >> 1;
	*ptr1_b = 1 << 31;
	cout << "1st Round��\n [" << *ptr1_a << ", " << *ptr1_b << "]\n\n";

	//�ڶ���
	unsigned short *ptr2_a, *ptr2_b, *ptr2_c, *ptr2_d;
	ptr2_a = static_cast<unsigned short*>(mem);
	ptr2_b = ptr2_a + 1;
	ptr2_c = ptr2_b + 1;
	ptr2_d = ptr2_c + 1;
	*ptr2_a = 65525;
	*ptr2_b = 65524;
	*ptr2_c = 65523;
	*ptr2_d = 65522;
	cout << "2nd Round��\n [" << *ptr2_a << ", " 
		 << *ptr2_b << ", " << *ptr2_c << ", " << *ptr2_d << "]\n\n";

	//������
	char *ptr3_a;
	unsigned short *ptr3_b;
	unsigned char *ptr3_c;
	unsigned *ptr3_d;
	ptr3_a = static_cast<char*>(mem);
	ptr3_b = reinterpret_cast<unsigned short*>(ptr3_a + 1);
	ptr3_c = reinterpret_cast<unsigned char*>(ptr3_b + 1);
	ptr3_d = reinterpret_cast<unsigned*>(ptr3_c + 1);
	*ptr3_a = -128;
	*ptr3_b = 34811;
	*ptr3_c = ~0;
	*ptr3_d = 4294967295;
	cout << "3rd Round��\n [" << static_cast<int>(*ptr3_a) << ", " 
		 << *ptr3_b << ", " << static_cast<int>(*ptr3_c) << ", " << *ptr3_d << "]\n\n";

	//������
	char *ptr4_a;
	char *ptr4_b;
	ptr4_a = static_cast<char*>(mem);
	ptr4_b = ptr4_a + 1;
	*ptr4_a = 'A';
	ptr4_b = "Hello!";
	cout << "4th Round��\n [" << *ptr4_a << ", " << ptr4_b << "]\n\n";

	system("pause");
	return 0;
}