#include<iostream>
using namespace std;
struct node{
	int data;
	
	struct node *next,*prev;
};
class Dlist
{
	struct node *dll;
	public:
		void insert_beg(int);
		void insert_end(int);
		void insert_after(int,int);
		void insert_before(int,int);
		int delete_first();
		int delete_last();
		int delete_spec(int);
		void travel_forward();
		void travel_back();
		void display();
		void  reverse();
		Dlist();
		~Dlist();
		
};
//constructor
Dlist :: Dlist()
{
	dll=NULL;
}
//insert beg
void Dlist :: insert_beg(int ele)
{
	struct node *temp;
	temp=new node;
	temp->data=ele;
	temp->prev=NULL;
	temp->next=dll;
	if(dll!=NULL)
	dll->prev=temp;
	dll=temp;
}
//insert end
void Dlist :: insert_end(int ele)
{
	struct node *temp;
	temp=new node;
	temp->data =ele;
	temp->next=NULL;
	if(dll==NULL)
	{
	temp->prev=NULL;
	dll=temp;
	}
	else
	{
	struct node *current;
	current = dll;
	while(current->next!=NULL)
	current = current ->next;
	temp->prev=current;
	current ->next=temp;
	}
}
// Insertion after an element
void Dlist :: insert_after(int sele, int ele)
{
if(dll!=NULL)
{
	struct node *current;
	current=dll;
while(current!=NULL && current->data!=sele)
	current = current->next;
if(current!=NULL)
{
	struct node *temp;
	temp=new node;
	temp->data=ele;
	temp->next=current->next;
	temp->prev=current;
if(current->next!=NULL)
	current->next->prev=temp;
	current->next=temp;
}
else
	cout<<"element not found";

}   
else
	cout<<"list is empty";
}
//insert before
void Dlist::insert_before(int sele, int ele)
{
	if(dll!=NULL)
{
	struct node *current;
	current=dll;
	while(current!=NULL && current->data!=sele)
	current=current->next;
	if(current!=NULL)
	{
		struct node *temp;
		temp=new node;
		temp->data=ele;
		temp->next=current;
		temp->prev=current->prev;
		if(current->prev!=NULL)
		current->prev->next=temp;
		else
		dll=temp;	
		current->prev=temp;
}
else
		cout<<"element not found";
}
else
		cout<<"list is empty";
}



//display
void Dlist :: travel_forward()
{
	if(dll!=NULL)
	{
		struct node *current;
		current=dll;
		cout<<"elements in the list are : "<<endl;
		while(current!=NULL)
		{
			cout<<current->data<<endl;
			current=current->next;
		}
	}
	else
	cout<<"list is empty";
}
void Dlist::display()
{	
travel_forward();
}
void Dlist:: reverse()
{
travel_back();
}
void Dlist :: travel_back()
{
	if(dll!=NULL)
	{
		struct node *current;
		current=dll;
		cout<<"elements in the list are : "<<endl;
		while(current!=NULL)
		{
			cout<<current->data<<endl;
			current=current->prev;
		}
	}
	else
	cout<<"list is empty";
}
int Dlist:: delete_first()
{
	int x= -999;
	if(dll!=NULL)
	{
		struct node *temp;
		temp=dll;
		x=temp->data;
		dll=temp->next;
		if(temp->next!=NULL)
		temp->next->prev=NULL;
		delete temp;
	}
	else
	cout<<"list empty";
	return x;
}
int Dlist:: delete_last()
{
	int x= -999;
	if(dll!=NULL)
	{struct node *curr;
		curr=dll;
		while(curr->next!=NULL)
		curr=curr->next;
		x=curr->data;
		if(curr->prev==NULL)
		dll=NULL;
		else
		curr->prev->next=NULL;
		delete curr;
	}
	else 
		cout<<"list is empty";
	return x;
}
int  Dlist::delete_spec(int ele)
{
	if(dll!=NULL)
	{
	struct node *curr;
	curr=dll;
	while(curr!=NULL&&curr->data!=ele)
	curr=curr->next;
	if(curr!=NULL)
	{
			if(curr->prev!=NULL)
			curr->prev->next=curr->next;
			else
			dll=curr->next;
			if(curr->next!=NULL)
			curr->next->prev=curr->prev;
		delete curr;
	}
	else 
		cout<<"element not found "<<endl;
	}
		else cout<<"list is empty"<<endl;
	
}
	




//destructor
Dlist :: ~Dlist()
{
	struct node *temp;
	while(dll!=NULL)
{
	temp=dll;
	dll=temp->next;
	delete temp;
}
}
int main()
{
	Dlist Dl;
	Dl.insert_beg(12);
	Dl.insert_end(13);
	Dl.insert_beg(11);
	Dl.display();
	cout<<"insertion after"<<endl;
	Dl.insert_after(12,7);
	Dl.display();
	cout<<"insert before"<<endl;
	Dl.insert_before(7,9);
	Dl.display();
	Dl.delete_spec(13);
	Dl.display();
	return 0;
}
