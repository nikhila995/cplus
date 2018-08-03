#include<iostream>
using namespace std;
template <class T>
class binary_search
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
void binarysearch()
{
T sele;
int low=0;
int count=0;
int high=size-1;
int mid;
cout<<"enter element to serach\n";
cin>>sele;


while(low<=high)
{
	mid=(low+high)/2;
	if(a[mid]<sele)
		low=mid+1;
	else if(a[mid]>sele)
		high=mid-1;
	else
		{
		cout<<"search element "<<sele<<" is found at loction "<<mid<<endl;
		count=1;
		break;
		}
}
	if(count==0)
	cout<<"not found\n";
}
};
int main()
{
class binary_search<char> b;
int ele;
cout<<"enter no: of elements of array \n";
cin>>ele;
b.getsize(ele);
b.getelements();
b.binarysearch();
return 0;
}
		
		
