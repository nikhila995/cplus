#include<iostream>
using namespace std;
class heapsort
{
int *a;
int n;
int lpi;
public:
	void getsize(int size)
	{
		a=new int[size];
		n=size;
	}
	void getelements()
	{
		cout<<"enter elements to sort\n";
		for(int i=0;i<n;i++)
			cin>>a[i];
			lpi=(n/2)-1;
	}
	void heap_sort()
	{
		int i,j,t;
		for(i=lpi;i>=0;i--)
			build_heap(i,n);
		for(j=0;j<n-1;j++)
		{	
			t=a[0];
			a[0]=a[n-1-j];
			a[n-1-j]=t;
			
			build_heap(0,(n-1-j));
		}
		
	}

	void build_heap(int i,int n)
	{
		int temp=a[i],c;
		for(;2*i+1<n;i=c)
		{
			c=2*i+1;
			if((c+1)<n && a[c+1]>a[c])
				c++;
			if(temp<a[c])
			{	a[i]=a[c];
				//temp=a[i];
				//a[i]=a[c];
				//a[c]=temp;
			}
			else
				break;
		}
		a[i]=temp;
	}
	void print()
	{
		cout<<"sorted array :\n";
		for(int i=0;i<n;i++)
			cout<<a[i]<<endl;
	}
};
int main()
{
class heapsort h;
int ele;
cout<<"enter no: of elements to sort \n";
cin>>ele;
h.getsize(ele);
h.getelements();
h.heap_sort();
h.print();
return 0;
}
                                                                                                                                                                                                                                                      
