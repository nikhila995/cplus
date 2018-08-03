#include<iostream>
using namespace std;
template <class T>
class linear_search
{
T *a;
int size;

public:
void getsize(int n)
{
a=new T[n];
size=n;
}
void getelements()
{
cout<<"enter elements\n";
for(int i=0;i<size;i++)
cin>>a[i];
}
void linearsearch()
{
T sele;
int count=0,i;
int loc;
cout<<"enter element to search\n";
cin>>sele;
for(i=0;i<size;i++)
{
if(a[i]==sele)
{
cout<<"element found\n";
count=1;
loc=i;
}
}
if(count==1)
{
cout<<"search element "<<sele<<" is found at loction "<<loc<<endl;
}
if(count==0)
{
cout<<"element not found\n";
}
}
};
int main()
{
class linear_search<char> l;
int ele;
cout<<"enter no: of elements of array \n";
cin>>ele;
l.getsize(ele);
l.getelements();
l.linearsearch();
return 0;
}
		
		
