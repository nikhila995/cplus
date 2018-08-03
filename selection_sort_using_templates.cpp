#include<iostream>
using namespace std;
template <class T>
class selection
{

	T *a;
	int i,j,l,n;
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
		for(i=0;i<n-1;i++)
	{
		l=i;
		//cout<<"********1"<<endl;
		//cout<<a[l]<<endl;
		for(j=i+1;j<n;j++)
		{
			//cout<<"********2"<<endl;
			//cout<<a[j]<<endl;
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

