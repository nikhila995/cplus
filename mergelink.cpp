#include<iostream>
using namespace std;
struct node
{
int data;
struct node* next;
};
class linkedd
{
	struct node *L1;  //first linked list
	struct node *L2;	//second linked list
	struct node *L3;	//resultant merged linked list
	public:
	void inbeg1(int);	//add elements at begining in list1
	void inbeg2(int);	//add elements at begining in list2
	void display(struct node*);
	void print1();	//print elements  in list1
	void print2();	//print elements  in list2	
	void merge(int,int);
	void print3();	//print elements of resultant list3
	linkedd();
	//~linkedd();
};
/*constructor!!!!!!!*/
linkedd::linkedd()	// initialize lists
{
L1=NULL;
L2=NULL;
L3=NULL;
}
/*display!!!!!*/
void linkedd::display(struct node* curr)
{
if(curr->next!=NULL)
display(curr->next);//recursive
cout<<curr->data<<"\t";
cout<<endl;
}
/*printing the list*/
void linkedd::print1()
{
if(L1!=NULL)
	{
		struct node *curr;
		curr=L1;
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
void linkedd::print3()
{
if(L3!=NULL)
	{
		struct node *curr;
		curr=L3;
		cout<<"elements of the L3 are\n";
		while(curr!=NULL)
		{
			cout<<curr->data<<endl;
			curr=curr->next;
		}
	}
	else
		cout<<"list is empty";
}			
/*insertion of element in begning*/
void linkedd::inbeg1(int s1)
{
int ch1;
ch1=s1;
cout<<"size of the list L1 is\n";
cout<<ch1<<endl;
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
if(L1==NULL)
L1=temp;
else
{
struct node* curr;
curr=L1;
while(curr->next!=NULL)
curr=curr->next;
curr->next=temp;
}
}
}
void linkedd::print2()
{
if(L2!=NULL)
	{
		struct node *curr;
		curr=L2;
		cout<<"elements L2 are\n";
		while(curr!=NULL)
		{
			cout<<curr->data<<endl;
			curr=curr->next;
		}
	}
	else
		cout<<"list is empty";
}		
/*insertion of element in begning*/
void linkedd::inbeg2(int s2)
{
int ch2;
ch2=s2;
cout<<"size of the list L2 is\n";
cout<<ch2<<endl;
cout<<"enter  the  elements u want to insert in L2\n";
for(int i=0;i<s2;i++)
{
int ele;
cout<<"element "<<(i+1)<<endl;
cin>>ele;
struct node *temp;
temp=new node;
temp->data=ele;
temp->next=NULL;
if(L2==NULL)
L2=temp;
else
{
struct node* curr;
curr=L2;
while(curr->next!=NULL)
curr=curr->next;
curr->next=temp;
}
}
}
void linkedd::merge(int L1size,int L2size)
{
	//struct node *str1=L1;

	//truct node *str2=L2;

	if(L1!=NULL && L2!=NULL)
	{

		//cout<<"In if"<<endl;
	struct node* curr1;
	struct node* curr2;
	struct node* curr3;
		curr1=L1;
		curr2=L2;
		curr3=L3;
	
	while(curr1!=NULL && curr2!=NULL)
	{	
		if(curr1->data < curr2->data)
		{
			struct node *temp;
			temp=new node;
			temp->data=curr1->data;
			temp->next=L3;
			L3=temp;
			curr1=curr1->next;
			curr3=L3;
			curr3->next=curr2;
		}
		else
		{
			struct node *temp;
			temp=new node;
			temp->data=curr2->data;
			temp->next=L3;
			L3=temp;
			curr2=curr2->next;
			curr3=L3;
			curr3->next=curr2;	
		}
	}//while
		
	}
	else
		cout<<" cannot merge\n";
	
}
		
int main()
{
		class linkedd l;

		int size1,size2;

			cout<<"enter size for L1\n";
			cin>>size1;

		l.inbeg1(size1);

		l.print1();
		cout<<"--------------------LIST 2------------------------\n";

			cout<<"enter size for L1\n";
			cin>>size2;

		l.inbeg2(size2);
		
		l.print2();
	
		l.merge(size1,size2);
l.print3();
return 0;
}

