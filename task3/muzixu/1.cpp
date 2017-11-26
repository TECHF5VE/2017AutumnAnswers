#include<iostream>
using namespace std;
void main()
{
	int x=0,y=0,i;
	float a;
	int A[101],B[101];
	cin>>a;
	int p=int(a);
	float q=a-p;
	while (p!=0){
		if(p%2==0)A[x]=0;
		else A[x]=1;
		p=p/2;
		x++;
	}
	while (q!=0) {
		if (q*2<1) {
			B[y]=0;
			q=q*2;y++;
		}
		else {
			B[y]=1;
			q=q*2-1;y++;
		}
	}
	for (i=x-1;i>= 0;i--)
		cout<<A[i];
	cout<<".";
	for (i=0;i<y;i++)
		cout<<B[i];
}
