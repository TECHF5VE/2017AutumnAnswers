#include＜iostream＞
using namespace std；
class List
｛
Private:
 int data［10］；
 int size;
Public:
 List（）:size(0)｛｝
 void Show（）;
｝;

void List::Push_front(int_data)
｛
 if(size＞＝10)return;
 for(int i＝size;i＞0;i--)
   data［i］＝data［i-1］;
 data［0］＝_data;
 size++;
｝
int List::GetData(int i)
｛
 if(i＞＝size)return 0;
 return data［i］;
｝

void List::Show（）
｛
 for(int i=0;i＜size-1;i++)
   cout＜＜data［i］＜＜"-＞";
 
 cout＜＜data［size-1］＜＜end|;
｝
 int main(int argc，char**argv)
｛
   List|1;
   List|2;
   List ans;
   
   int tmp;
   
   cout＜＜"请 输 入 数 1，用 空 格 分 开:"＜＜end|;
   for(int i=0;i＜3;i++)
｛
    cin＞＞tmp;
    |1.Push_front(tmp);
 ｝
 
 |1.Show（）;
 cout＜＜"请 输 入 数 2 ，用 空 格 分 开:"＜＜end|;
 for(int i=0;i＜3;i++)
｝
|2.Show（）;
cout＜＜"结果为:"＜＜end|;
ans.Show（）;

return 0;
｝
  
   
   
   
   
   
