#include<iostream>
using namespace std;
class mergesort
{
int *a;
int size;
public:
void getsize(int n)
{
a=new int[n];
size=n;
}
void getelements()
{
cout<<"enter elements to sort\n";
for(int i=0;i<size;i++)
cin>>a[i];
}

void split_sort(int low,int high)
{
		if(low<high)
	{
	 int mid=(low+high)/2;
	split_sort(low,mid);
	split_sort(mid+1,high);
	merge(low,mid,high);
	}
}
void merge(int n1s,int n1e,int n2e)
{
	int n2s=n1e+1;//mid+1
	int s=n2e-n1s+1;
	int *L,i,j,k=0;
	L=new int[s];
	i=n1s;
	j=n2s;
	while(i<=n1e && j<=n2e)
	{
		if(a[i]<a[j])
		L[k++]=a[i++];
		else
		L[k++]=a[j++];
	}
	while(i<=n1e)
		L[k++]=a[i++];
	while(j<=n2e)
		L[k++]=a[j++];
	while(k>0&&n2e>=0)
		
		a[n2e--]=L[--k];
	delete L;
}
void print()
{
	cout<<"sorted array :\n";
	for(int i=0;i<size;i++)
	cout<<a[i]<<endl;
}
};
int main()
{
class mergesort m;
int ele;
cout<<"enter no: of elements to sort \n";
cin>>ele;
m.getsize(ele);
m.getelements();
m.split_sort(0,ele-1);
m.print();
return 0;
}

