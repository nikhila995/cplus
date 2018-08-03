 #include<iostream>

using namespace std;
class deque{
int f,r;
int size;
int *q;
public:

void get_size(int);
deque();
void insert_front(int);
void insert_rear(int);
int delete_front();
int delete_rear();
bool underflow();
bool overflow();
void display();
~deque();
};

deque :: deque()
{
size=0;
f=r=-1;
q=NULL;
}

void deque :: get_size(int n)
{
q= new int[n];
size=n;
}

bool deque:: overflow()
{
return(r==size-1);
}
bool deque::underflow()
{
return((f==-1)&&(r==-1));
}


void deque:: insert_front(int ele)    //????whts happening
{
if(!overflow())
{
if(r==-1 && f==-1)
{
q[f]=ele;
f++;
}
else
{
for(int i=r+1;i>f;i--)
{
q[i]=q[i-1];
}
q[f]=ele;
r++;
cout<<"insert front r:"<<r<<endl;
cout<<"f:"<<f<<endl;
}
}
else
cout<<"overflow"<<endl;
}



void deque::insert_rear(int ele)
{
if(!overflow())
{
if(r==-1 && f==-1)
f++;
q[++r]=ele;
cout<<"insert rear r:"<<r<<endl;
cout<<"f:"<<f<<endl;
}
else
cout<<"queue overflow"<<endl;
}

int deque :: delete_rear()
{
int x=-999;
if(!underflow())
{
x=q[r];
if(f==r)
f=r=-1;
else
r--;
}
else
cout<<"queue underflow"<<endl;
cout<<"deleted rear:"<<x<<endl;
return x;
}

int deque:: delete_front()
{
int x=-999;
if(!underflow())
{
x=q[f];
if(f==r)
f=r=-1;
else
f++;
}
else
cout<<"queue underflow"<<endl;
cout<<"deleted front:"<<x<<endl;
return x;
}

void deque::display()
{
cout<<"elements in queue"<<endl;
if(!underflow())
{
for(int i=f;i<=r;i++)
{
cout<<q[i]<<endl;
}
}
else
cout<<"no elements in queue"<<endl;
}


deque ::~deque()
{
delete q;
size=0;
f=r=-1;
}


class stack : public deque
{
public:
void push(int x)
{
insert_rear(x);
}
int pop()
{
delete_rear();
}
};



int main()
{
deque l;
l.get_size(5);
l.insert_rear(3);
l.insert_front(4);
l.insert_front(5);
l.insert_rear(9);
l.insert_front(1);
l.display();
l.delete_rear();
l.delete_front();
cout<<"after deletion"<<endl;
l.display();


stack s;
s.get_size(5);
s.push(0);
s.push(1);
s.push(7);
s.push(5);
s.display();
s.pop();
cout<<"stack elemnets"<<endl;
s.display();
return 0;
}
