#include<iostream>
using namespace std;
int main()
{
	int a[100],i,j,l,n;

	cout<<"enter no of ele"<<endl;
	cin>>n;
	cout<<"enter the elemens"<<endl;
	for(i=0;i<n;i++)
	cin>>a[i];

	for(i=0;i<n-1;i++)
	{
		l=i;
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			l=j;
	
		}
	if(i!=l)
	{
		int t;
		t=a[i];
		a[i]=a[l];
		a[l]=t;
	}
}
cout<<"sorted elements\n";

	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
		
}
return 0;
}

