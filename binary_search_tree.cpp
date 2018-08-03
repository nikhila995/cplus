#include<iostream>
#include<string.h>
using namespace std;
struct node 
{
	int data;
	struct node *left,*right;
	
};
class binarystree
{
	struct node *bst;
public:
	binarystree()
	{
		bst=NULL;
	}


//...............function to insert node in tree.................

	void insert(int ele)
	{
		struct node *temp;
		temp=new node;
		temp->data=ele;
		temp->left=temp->right=NULL;	//prepare a memory for node which is to be inserted
		if(bst==NULL)	//if tree is empty 
		{
			bst=temp;	//insert first node of tree
	
		}

		else		//if tree already has some node
		{	
			struct node *curr;	//take one running pointer of type struct
			curr=bst;	//starts from the root node
			while(1)
			{
				if(ele<curr->data)	//if data of node which is to be inserted is less than tha data of  									current pointing node
				{
					if(curr->left==NULL)	//left subtree is empty
					{
						curr->left=temp;	
						break;	//we came out from loop after inserting node at its appropriate 								location

					}
					else	//left subtree is not empty i-e it has subtree 
						curr=curr->left;
				}
				else 	//it goes to right subtree
				{
					if(curr->right==NULL)	//right subtree is empty
					{
						curr->right=temp;
						break;
					}
					else	//right subtree is not empty i-e it has subtree 
						curr=curr->right; //move to next right higher subtree
				}
			}	

		}
			

	}

//............function to delete specific node from tree................

	void delete_spec(int ele)
	{
		if(bst!=NULL)
			bst=delete_ele(ele,bst);
		else
			cout<<"tree is empty";		
	}

	struct node *delete_ele(int ele,struct node *curr)
	{
		if(curr!=NULL)
		{
		
			if(ele>curr->data)
				curr->right=delete_ele(ele,curr->right);
			else
			{
				if(ele<curr->data)
				{
					curr->left=delete_ele(ele,curr->left);
				        cout<<"Current is at left substree"<<endl;
				}	
				else	//element found at any node
				{
					cout<<"\nfounded element have either two child or one child\n";
					if(curr->left!=NULL  && curr->right!=NULL)	//if founded node has two child
					{
						cout<<"\nfounded element has two child\n";
						curr->data=maxFindEle(curr->left);
						curr->left=delete_ele(curr->data,curr->left);
					}
					else	//founded node has only one child or no child
					{
						cout<<"\nfounded element has either one child or leaf node\n";
						struct node *temp;
						temp=curr;
						cout<<"value of temp=\n"<<temp;
						if(curr->left!=NULL)
							curr=curr->left;
						else
							curr=curr->right;
						delete temp;
					}
					
				}
			
			
		}
		}
		else
			cout<<"element not found";
	return curr;

	}


	
//.............function to calculate no. of leaf node...............

	int noOfLeafNode()
	{
	if(bst!=NULL)
		return(NLN(bst));
	else
		return 0;
	}

	int NLN( struct node *curr)
	{
		if(curr==NULL)
			return 0;
		if(curr->left==NULL && curr->right==NULL)
			return 1;
		return(NLN(curr->left) + (NLN(curr->right)));
	}
	

//................function to calculate no. of non leaf node...........		

	int noOfNonLeafNode()
	{
		if(bst!=NULL)
			return(NNLN(bst));
		else
			return 0;		

	}
	
	int NNLN( struct node *curr)
	{
		if(curr==NULL) //if node dosn't exist
			return 0;
		if(curr->left==NULL && curr->right==NULL)	//if node has no left and right child i-e its a leaf node
			return 0;
		return(NNLN(curr->left) + NNLN(curr->right)+1);	
	}

//.....................function to calculate height...............
	
	int height()
	{
		int h=-99;
		if(bst!=NULL)
		{
			struct node *temp;
			temp=bst;
			if(bst!=NULL)
			{
				h=heightofnode(temp);	
			}
			
		}
		else
		cout<<"Empty  tree";
			return h;
	} 
	int heightofnode(struct node *curr)
	{
		if(curr==NULL)
			return(-1);
		if(curr->left==NULL && curr->right==NULL)
			return 0;
		return (max(heightofnode(curr->left),heightofnode(curr->right))+1);
	}

	/*int maxHeight(struct node *curr)
	{
		if(curr->left>curr-right)

			return curr->left;
		else
			return curr->right;

	}*/

//............function to find maximum element of the tree..............

	int maxFindEle(struct node *curr)
	{
		int x=-999;
		if(curr!=NULL)
		{
			while(curr->right!=NULL)
				curr=curr->right;
			
			x=curr->data;
			return x;
		}
	
	}

	/*int maxe()
	{
		int mx;
		struct node *curr;
		curr=bst;
		if(curr!=NULL)
			mx=maxFindEle(curr);
		return mx;
	}*/

//..........function to find minimum element of the tree......

	int minFindEle(struct node *curr)
	{
		int x=-999;
		if(curr!=NULL)
		{
			while(curr->left!=NULL)
				curr=curr->left;
			x=curr->data;
			return x;
		}
	
	}
	
	/*int min()
	{
		int mn;
		struct node *curr;
		curr=bst;
		if(curr!=NULL)
			mn=minFindEle(curr);
		return mn;
	}*/


//..........function to traverse tree in Inoder.......
		
	void Inorder()
	{
		if(bst!=NULL)
		{
			printI(bst);
		}

	}

	void printI(struct node *curr)
	{
		if(curr!=NULL)
		{
			printI(curr->left);
			cout<<curr->data<<" |";
			printI(curr->right);
		}
		
	}
	
//.............function to preorder traversal of tree.............

	void preorder()
	{
		if(bst!=NULL)
		{
			printpre(bst);
		}
	}


	void printpre(struct node *curr)
	{
		if(curr!=NULL)
		{
			cout<<curr->data<<" |";
			printpre(curr->left);
			printpre(curr->right);
		}
		
	}



//.............function to postorder traversal of tree.............

	void postorder()
	{
		if(bst!=NULL)
		{
			printpost(bst);
		}
	}


	void printpost(struct node *curr)
	{
		if(curr!=NULL)
		{
			
			printpost(curr->left);
			printpost(curr->right);
			cout<<curr->data<<" |";
		}
		
	}
//............mirror..................
	/*void print_mirror(struct node * curr)
	{
		if(curr==NULL ||(curr->left==NULL &&  curr->right==NULL))
		{
			;
		}
		else
		{
			struct node *temp;
			temp=curr->left;
			curr->left=curr->right;
			curr->right=temp;
		
			mirror(curr->left);
			mirror(curr->right);
		}
	}
	void mirror()
	{
		
		if(bst!=NULL)
		{
		print_mirror(bst);
		}
	}*/
		

//...............destructor.....................

	~binarystree()
	{
		
		if(bst!=NULL)
		{
			delete_tree(bst);
		}
	}
		void delete_tree(struct node *curr)
		{
			if(curr!=NULL)	//curr points bst at this point i-e if bst has some node
			{
				delete_tree(curr->left);
				delete_tree(curr->right);
				delete curr;
			}
		}
	
	friend istream& operator >>(istream& in,binarystree &);

};
	istream& operator >>(istream& in,binarystree &b)
	{
		int a;
		in>>a;
		b.insert(a);
		return in;
	}
	

int main()
{
	binarystree bs;
	int n,d;
	cout<<"\n......enter the size of your tree.......\n";
	cin>>n;
	cout<<"\n......enter node of your tree......\n";
	for(int i=0;i<n;i++)
		cin>>bs;

	int l=bs.noOfLeafNode();
	cout<<"\n....total no of leaf node of your tree is:...\n";
	cout<<l;

	int nl=bs.noOfNonLeafNode();
	cout<<"\n....total no of non leaf node of your tree is:...\n";
	cout<<nl;
	cout<<"...\nenter node for that u want to know hieght...\n";
	int n1;
	
	n1=bs.height();
	cout<<"height of the tree is : "<<n1<<endl;
	int ele;
	cout<<"\n.......maximum element of the tree is:....\n";
	cin>>ele
	int mx=bs.maxFindEle(ele);
	cout<<mx;

	cout<<"\n.......manimum element of the tree is:....\n";
	int mn=bs.min();
	cout<<mn;

	cout<<"\n............Inorder traversal of tree.............\n";
	bs.Inorder();

	cout<<"\n............Preorder traversal of tree.............\n";
	bs.preorder();

	cout<<"\n............Postorder traversal of tree.............\n";
	bs.postorder();
	
	cout<<"\n..............enter the node u want to delete........\n";
	cin>>d;
	bs.delete_spec(d);
	
	//cout<<"\n............mirror image of elements..................\n";
	//bs.mirror();

	int l1=bs.noOfLeafNode();
	cout<<"\n....total no of leaf node of your tree is:...\n";
	cout<<l;

	int nl1=bs.noOfNonLeafNode();
	cout<<"\n....total no of non leaf node of your tree is:...\n";
	cout<<nl;
	

	cout<<"\n";
	return 0;

}















