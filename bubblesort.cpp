#include<iostream>
using namespace std;
int main()
{
	int a[100],i,j,n,flag;
	cout<<"enter no of ele"<<endl;
	cin>>n;
	cout<<"enter the elemens"<<endl;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<=n-2-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int t;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			flag=1;
			}
		}
	
		if(flag==0)
		break;
	}
		cout<<"sorted elements\n";

	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
		
}
}
