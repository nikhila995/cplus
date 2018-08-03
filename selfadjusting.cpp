#include<iostream>
using namespace std;
struct node
{
int data;
struct node* next;
};
class linkedd
{
	struct node *L;
	
	public:
	void inend(int);
	void display(struct node*);
	void print();
	void selfadjust(int);
	linkedd();
	//~linkedd();
};
/*constructor!!!!!!!*/
linkedd::linkedd()
{
L=NULL;

}

/*printing the list*/
void linkedd::print()
{
if(L!=NULL)
	{
		struct node *curr;
		curr=L;
		cout<<"elements of the L1 are\n";
		while(curr!=NULL)
		{
			cout<<curr->data<<endl;
			curr=curr->next;
		}
	}
	else
		cout<<"list is empty";
}
void linkedd::inend(int s1)
{
cout<<"enter  the  elements u want to insert in L1\n";
for(int i=0;i<s1;i++)
{
int ele;
cout<<"element "<<(i+1)<<endl;
cin>>ele;
struct node *temp;
temp=new node;
temp->data=ele;
temp->next=NULL;
if(L==NULL)
L=temp;
else
{
struct node* curr;
curr=L;
while(curr->next!=NULL)
curr=curr->next;
curr->next=temp;
}
}
}
void linkedd::selfadjust(int sele)
{
cout<<"hai\n";
if(L!=NULL)
{
struct node* curr1;
cout<<"pp**************************pp\n";
curr1=L;
cout<<"pp----------------------pp\n";
while(curr1->data!=sele&&curr1->next!=NULL)
cout<<"pp++++++++++++++++++++pp\n";
curr1=curr1->next;
cout<<"pp))))))))))))))))))))))))))))))))pp\n";
struct node* temp;
temp =new node;
cout<<"pp:::::::::::::::::::::::::::::::::::::::::::::::::::::pp\n";
temp->data=curr1->data;
temp->next=L;


}
else
cout<<"list empty\n";
}
int main()
{
		class linkedd l;
		int size;
		cout<<"enter size for L1\n";
		cin>>size;
		l.inend(size);
		l.print();
		l.selfadjust(1);
		l.print();
		//l.print();
return 0;
}	
