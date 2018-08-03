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
		//~q();
};
q::q()
{
	qu=NULL;
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
return(r==size-1);
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
cout<<"\nelement deleted is : \n"<<x;
if(f==r)
f=r=-1;
else 
f++;
}
else cout<<"\nunderflow\n";
return x;
}
void q::enq(int ele)
{
if(!overflow())
{
if(r==-1&&f==-1)
{f++;   }
qu[++r]=ele;
}
else
cout<<"\nqueue is full \n";
}
void q::display()
{
if(!underflow())
{
for(int i=f;i<=r;i++)
{
cout<<qu[i]<<"\t"<<endl;
}
}
else
cout<<"no elements to display\n";
}
int main()
{
class q o;
o.getsize(5);
o.enq(6);
o.enq(2);
o.enq(5);
cout<<"queue elements are\n";
o.display();
o.dq();
cout<<"\nqueue elements are\n";
o.display();

return 0;
}



