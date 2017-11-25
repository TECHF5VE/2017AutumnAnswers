
   
   #include <iostream>
using namespace std;

class List
{
private:
	int data[10];
	int size;
public:
	List():size(0){}
	void Push_front(int _data);
	int GetData(int i);
	void Show();
};

void List::Push_front(int _data)
{
	if(size>=10)	return;
	for(int i=size;i>0;i--)
		data[i]=data[i-1];
	data[0]=_data;
	size++;
} 
int List::GetData(int i)
{
	if(i>=size) return 0;
	return data[i];
}

void List::Show()
{
	for(int i=0;i<size-1;i++)
		cout<<data[i]<<" -> ";
	
	cout<<data[size-1]<<endl;

}
int main(int argc,char** argv)
{
	List l1;
	List l2;
	List ans;
		
	int tmp;

	cout<<"请输入数1，用空格分开:"<<endl;
	for(int i=0;i<3;i++)	 
	{
		cin>>tmp;
		l1.Push_front(tmp);
	}
	
	l1.Show();	
	cout<<"请输入数2，用空格分开:"<<endl;
	for(int i=0;i<3;i++)	 
	{
		cin>>tmp;
		l2.Push_front(tmp);
		ans.Push_front(tmp+l1.GetData(i));
	}
	l2.Show();
	cout<<"结果为:"<<endl;	
	ans.Show();

	return 0;
}
   
   
   
