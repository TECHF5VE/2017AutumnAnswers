#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[16] = { 0 }, b[24] = { 0 }, c[8] = { 0 }, d[23] = { 0 }, e[32] = { 0 };
	char p[8] = { 0 };
	double num; 
	int integer, power;
	double decimal;
	cin >> num;
	if (num > 0)  a[0] = 0;
	else a[0] = 1;
	num = fabs(num);

	integer = (int)num;
	decimal = num - (double)integer;

	if (integer == 0){
		for (int i = 1; i < 16; ++i)
			a[i] = 0;
		for (int j = 0 ; j < 24; ++j){
			double t = decimal * 2;
			b[j] = (int)t;
			decimal = t - b[j];
		}
		int tem;
		for(int j=0;j<24;++j){
			if(b[j]!=0){
				tem=j;
			   power=126-j;
			}
			if(b[j]!=0) break;
		}
		for (int i = 7; i >= 0; --i){
			int t = power % 2;
			power = power / 2;
			c[i] = t;
		}
		e[0] = a[0];
		for (int i = 1; i < 9; ++i){
			e[i] = c[i - 1];
		}
		for (int i = 9; i < 32; ++i){
			e[i] = b[tem+i-8];
		}
	}

	else {
		for (int i = 15; i >0; --i){
			int t = integer % 2;
			integer = integer / 2;
			a[i] = t;
		}
		for (int j = 0; j < 24; ++j){
			double t = decimal * 2;
			b[j] = (int)t;
			decimal = t - b[j];
		}
		int temp=0;
		for (int i = 1; i < 16; ++i){
			if (a[i] != 0){
				temp = i;
				int t = 15 - i;
				power = 127 + t;
			}
			if (a[i] != 0) break;
		}
		for (int i = 0; i < 15 - temp; ++i){
			d[i] = a[temp + 1 + i];
		}
		for (int i = 15 - temp ;i < 23; ++i){
			d[i] = b[i + temp - 15];
		}

		for (int i = 7; i >= 0; --i){
			int t = power % 2;
			power = power / 2;
			c[i] = t;
		}
		e[0] = a[0];
		for (int i = 1; i < 9; ++i){
			e[i] = c[i - 1];
		}
		for (int i = 9; i < 32; ++i){
			e[i] = d[i - 9];
		}
	}
	unsigned int output=0,pow = 2147483648;
	for(int i=0;i<32;++i){
		output+=(int)e[i]*pow;
		pow/=2;
	}
	
	cout << "0x" << hex << output << endl ;
	


		void *mem=operator new(8);
		//第一轮
		int *ptr1=static_cast<int*>(mem);
		int *ptr2=ptr1+1;
		*ptr1=((unsigned)~0)>>1;
		*ptr2=1<<31;
		cout<<"第一轮:["<<dec<<*ptr1<<","<<*ptr2<<"]\n";

        //第二轮
		unsigned short *ptr3,*ptr4,*ptr5,*ptr6;
		ptr3=static_cast<unsigned short*>(mem);
		ptr4=ptr3+1;
		ptr5=ptr4+1;
		ptr6=ptr5+1;
		*ptr3=65525;
		*ptr4=65524;
		*ptr5=65523;
		*ptr6=65522;
		cout<<"第二轮:["<<*ptr3<<","<<*ptr4<<","<<*ptr5<<","<<*ptr6<<"]\n";

		//第三轮
		char*ptr7;
		unsigned short*ptr8;
		unsigned char*ptr9;
		unsigned int*ptr10;
		ptr7=static_cast<char*>(mem);
		ptr8=reinterpret_cast<unsigned short*>(ptr7+1);
		ptr9=reinterpret_cast<unsigned char*>(ptr8+1);
		ptr10=reinterpret_cast<unsigned int*>(ptr9+1);
		*ptr7=-128;
		*ptr8=34811;
		*ptr9=255;
		*ptr10=4294967295;
		cout<<"第三轮:["<<(int)*ptr7<<","<<*ptr8<<","<<(int)*ptr9<<","<<*ptr10<<"]\n";

		//第四轮
		char *ptra,*ptrb;
		ptra=static_cast<char*>(mem);
		ptrb=ptra+1;
		*ptra='A';
		ptrb="hello!\0";
		cout<<"第四轮:["<<*ptra<<','<<ptrb<<"]\n";

		return 0;
}
