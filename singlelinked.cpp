#include<iostream>
using namespace std;
struct node
{
int data;
int sele;
struct node* next;
};
class linkedd
{
struct node *l;
public:
	void inbeg(int);
	void inend(int);
	void inbefore(int,int);
	void inafter(int,int);
	int delfirst();
	int dellast();
	void delespec(int ele);
	void reverse();
	void travelforward();
	void display(struct node*);
	void getsize(int);
	void print();
	void travelbackward();
	linkedd();
	//~linkedd();
};
/*constructor!!!!!!!*/
linkedd::linkedd()
{
l=NULL;
}
/*display!!!!!*/
void linkedd::display(struct node* curr)
{
if(curr->next!=NULL)
display(curr->next);//recursive
cout<<curr->data<<"\t";
cout<<endl;
}
void linkedd::travelbackward()
{
if(l!=NULL)
display(l);//wrapper call
}
/*printing the list*/
void linkedd::print()
{
if(l!=NULL)
	{
		struct node *curr;
		curr=l;
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
void linkedd::inbeg(int ele)
{
struct node *temp;
temp=new node;
temp->data=ele;
temp->next=l;
l=temp;
}
/*insertion of element in end*/
void linkedd::inend(int ele)
{
struct node *temp;
temp=new node;
temp->data=ele;
temp->next=NULL;
if(l==NULL)
l=temp;
else
{
struct node* curr;
curr=l;
while(curr->next!=NULL)
curr=curr->next;
curr->next=temp;
}
}
/*insertion of element after some element in list*/
void linkedd::inafter(int sele,int ele)
{
if(l!=NULL)
{
struct node* curr;
curr=l;
while(curr!=NULL&&curr->data!=sele)
curr=curr->next;
if(curr!=NULL)
{
struct node* temp;
temp=new node;
temp->data=ele;
temp->next=curr->next;
curr->next=temp;
}
else
cout<<"\nele not found";
}
else
cout<<"\nlist is empty";
}
/*insertion of element before any element in list*/
void linkedd::inbefore(int sele,int ele)
{	if(l!=NULL)
	{	if(l->data==sele)
		{	struct node* temp;
			temp=new node;
			temp->data=ele;
			temp->next=l;
			l=temp;
		}else
			{
			struct node* curr;
			curr=l;
			while(curr->next!=NULL&&curr->next->data!=sele)
				curr=curr->next;
				if(curr->next!=NULL)
				{	struct node* temp;
					temp=new node;
					temp->data=ele;
					temp->next=curr->next;
					curr->next=temp;
					
				}else
				cout<<"\nele not found";
				
				}//else
	
	}//main if else
	else
	cout<<"\nlist is empty";
}//function
/*deletion of first element  in the list*/
int linkedd:: delfirst()
{
	int x= -999;
	if(l!=NULL)
	{
		struct node *temp;
		temp=l;
		x=temp->data;
		l=temp->next;
		delete temp;
	}
	else
	cout<<"list empty";
	return x;
}
/*deletion of last element  in the list*/
int linkedd:: dellast()
{
	int x=-999;
	if(l!=NULL)
	{
		struct node *temp;
		if(l->next==NULL)
		{
			temp==l;
			x=temp->data;
			l=NULL;
			delete temp;
		}
		else
		{
		struct node *curr;
		curr=l;
		while(curr->next->next!=NULL)
		curr=curr->next;
		temp=curr->next;
		x=temp->data;
		curr->next=NULL;
		delete temp;
		}
}
else
cout<<"list is empty";
return x;
}
/*rverse of element in the lit*/
void linkedd :: reverse()
{
	struct node *temp,*R;
	R=NULL;
	while(l!=NULL)
	{
		temp=l;
		l=temp->next;
		temp->next=R;
		R=temp;
	}
	l=R;
}
/*void linkedd :: ~linkedd()
{
	struct node *temp;
	while(l!=NULL)
	{
		temp=l;
		l=temp->next;
		delete temp;
	}
}*/
/* deletion of specific element*/
void linkedd:: delespec(int ele)
{
	
	if(l!=NULL)
	{
		
		if(l->data==ele)
		{
			
			struct node *temp;
			temp=l;
			l=temp->next;
			delete temp;
		}
		else
		{
			
			struct node *curr;
				curr =l;
			while(curr->next!=NULL && curr->next->data!=ele)
				curr=curr->next;
			if(curr->next!=NULL)
			{
				
				struct node *temp;
					temp=curr->next;
				curr->next=temp->next;
				delete temp;
			}
			else
				cout<<"ele not found";
		}
}
else
	cout<<"list is empty";
}
/*travel forward elements are*/
void linkedd:: travelforward()
{
	if(l!=NULL)
	{
		struct node *curr;
		curr=l;
		while(curr!=NULL)
		{
			cout<<curr->data<<endl;
			curr=curr->next;
		}
	}
	else
		cout<<"list is empty";
}			



int main()
{
	linkedd lo;
		cout<<".......inserting first element in list......."<<"\n"<<endl;
		lo.inbeg(1);
	lo.print();
		cout<<".......inserting element after  first element in list......."<<"\n"<<endl;
		lo.inafter(1,4);
	lo.print();
		cout<<".......inserting element 3 before  4  in list......."<<"\n"<<endl;
		lo.inbefore(4,3);
	lo.print();
		cout<<".......inserting element in begining......."<<"\n"<<endl;
		lo.inbeg(8);
	lo.print();
	cout<<".......inserting element 5 after  4 in list......."<<"\n"<<endl;	
		lo.inafter(4,5);
	lo.print();
	cout<<".......inserting element 6 before 4 in list......."<<"\n"<<endl;
		lo.inbefore(4,6);
	lo.print();
	cout<<".......delete first element......."<<"\n"<<endl;
		lo.delfirst();
	lo.print();
	cout<<".......delete last element......."<<"\n"<<endl;
		lo.dellast();
	lo.print();
	cout<<".......delete specific element i.e 6......."<<"\n"<<endl;
		lo.delespec(6);
	lo.print();
		cout<<"travelforward element"<<endl;
		lo.travelforward();
	cout<<".......reverse the list......"<<"\n"<<endl;
		lo.reverse();
	lo.print();
	//lo.print();
return 0;
}

