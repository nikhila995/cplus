#include<iostream>
using namespace std;
class q
{
int *qu;
int size;
int f,r;
public:
		q();
		void enq(int);
		int dq();
		
		bool overflow();
		bool underflow();
		void display();
		void getsize(int);
		~q();
};
q::q()
{
	qu=NULL;
	size=0;
	f=r=-1;
}
q::~q()
{
	delete []qu;
	size=0;
	f=r=-1;
}
void q::getsize(int n)//void q::getsize()
{	//cin>>n;
	qu=new int[n];
	size=n;
}
bool q::overflow()
{
return(f==((r+1)%size));
}
bool q::underflow()
{
return((r==-1)&&(f==-1));
}
int q::dq()
{
	int x=-999;
		if(!underflow())
		{
			x=qu[f];
			cout<<"\nelement deleted is : \n"<<x<<endl;
			if(f==r)
				f=r=-1;
			else 
				f=(f+1)%size;
		}
		else cout<<"\nunderflow\n";
return x;
}
void q::enq(int ele)
{
	if(!overflow())
	{
		if(r==-1&&f==-1)
		f++;  

		r=(r+1)%size;
		qu[r]=ele;
	}
	else
	cout<<"\nqueue is full \n";
}
void q::display()
{
	if(!underflow())
	{ int i;
		cout<<"\nqueue elements are\n";
		for(i=f;i!=r;i=(i+1)%size)
		//for(i=f;i<=r;i++)
		{
			cout<<qu[i]<<"\t"<<endl;
			
		}
		cout<<qu[i]<<"\t"<<endl;
	}
}
int main()
{
class q o;
o.getsize(5);
o.enq(6);
o.enq(2);
o.enq(5);
//cout<<"queue elements are\n";
o.display();
o.dq();
//cout<<"\nqueue elements are\n";
o.display();
cout<<"\ninserting elements\n";
o.enq(1);
o.enq(8);
o.enq(9);
//cout<<"\nqueue elements are\n";
o.display();
cout<<"delete ele\n";
o.dq();
o.dq();
o.dq();
o.dq();
cout<<"\nremaining\n";
o.display();
o.dq();
return 0;
}



