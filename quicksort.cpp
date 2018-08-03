#include<iostream>
using namespace std;
template <class T>
class quick_sort
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
cout<<"enter elements to sort\n";
for(int i=0;i<size;i++)
cin>>a[i];
}
void quicksort(int low,int high)
{
	int i,j;
	T p;
	p=a[low];
	i=low+1;
	j=high;
	if(low<high)
	{
		while(1)
		{
			while(i<=high && a[i]<p)
				i++;
			while(a[j]>p)
				j--;
			if(i<j)
				{T t;
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			else
				break;
		}
		T temp;
		temp=a[low];
		a[low]=a[j];
		a[j]=temp;
		quicksort(low,j-1);
		quicksort(j+1,high);
	}
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
class quick_sort<char> q;
int ele;
cout<<"enter no: of elements to sort \n";
cin>>ele;
q.getsize(ele);
q.getelements();
q.quicksort(0,ele-1);
q.print();
return 0;
}

