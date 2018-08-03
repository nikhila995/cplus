#include<iostream>
using namespace std;
template <class T>
class selection
{

	T **a;
	int i,j,l,n,k;
public: 
	selection()
	{
		i=0;
		j=0;
		l=0;
		n=0;
		a=NULL;
	}
	void getvalue()
	{
	cout<<"enter no of ele"<<endl;
	cin>>n;
	a=new T[n];
	cout<<"enter the elemens"<<endl;
	for(i=0;i<n;i++)
	cin>>a[i];
	}
	void swapsort()
	{	
	for(k=0;k<n-1;k++)
	{
		T ch=a[k];
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
			T t;
			t=a[i];
			a[i]=a[l];
			a[l]=t;
		}
	}
}
}
	void print()
	{

		cout<<"sorted elements\n";

		for(i=0;i<n;i++)
		{
		cout<<a[i]<<endl;
		
		}	
	}
};
int main()
{
selection <char>  sl;
sl.getvalue();
sl.swapsort();
sl.print();
return 0;
}

