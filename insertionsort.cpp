#include<iostream>
using namespace std;
template <class T>
class selection
{

	T *a;
	int i,j,temp,n;
public: 
	selection()
	{
		i=0;
		j=0;
		temp=0;
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
		
	//(5,4,3,2,1)(4,5,3,2,1)
		for(i=1;i<=n-1;i++)
		{	temp = a[i];//4
			j=i-1;//0
			while(j>=0&&a[j]>temp)//t,
			{
				a[j+1]=a[j];
				j--;//-1
			}
			a[++j]=temp;
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
selection <int>  sl;
sl.getvalue();
sl.swapsort();
sl.print();
return 0;
}

