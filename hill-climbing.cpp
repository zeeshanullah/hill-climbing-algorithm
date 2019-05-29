#include<iostream>
#include<stdio.h>
#include<conio.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

////////////////////////////////////////////
struct QNode
{
	int data;
	int heuristic;
	QNode();
	QNode(int data);
	QNode& print();
	QNode *next;
	QNode *left;
	QNode *right;
};
QNode::QNode()
{
	data=0;
	next=NULL;
	right=NULL;
	left=NULL;
}
QNode::QNode(int data)
{
	this->data = data;
	next = NULL;
	right=NULL;
	left=NULL;
}
QNode& QNode::print()
{
	cout<<this->data<<"\t";
	return *this;
}
///////
class CStack //LIFO
{
 	public:
 		QNode *top;
 		int count;
		QNode* getTop();
 		CStack(); //Null Constructor
 		CStack(QNode *&top); //Parametric constructor 
		CStack(CStack &obj); //Copy Constructor
		CStack& Push(QNode *& ptr); 
 		QNode* Pop();
 		int get();
 		CStack & operator =(CStack &src); 		
		bool IsnotEmpty() const;
 		bool IsEmpty() const;
 		int GetCount() const;
 		QNode* Peak()  const;
 		CStack&  print();
 		~CStack();
};
int CStack::get()
{
	return top->data;
}
QNode* CStack::getTop()
{
	return top;
}
void copy_list(QNode *&dptr,QNode *&sptr)
{
	if (sptr)
	{
		dptr = new QNode(*sptr);
		copy_list(dptr->next,sptr->next);
	}
	else dptr = NULL;
}
CStack::CStack(){top = NULL;count = 0;}
//Parametric Constructor 
CStack::CStack(QNode *& top) 
{
	this->top = top;
 	count = 1;
 	top = NULL;
}
//Copy Constructor
CStack::CStack(CStack & obj)
{
	QNode * sptr, * dptr;
	sptr=top=obj.top; count=obj.count;
	if (sptr)
	{
		top=dptr=new QNode(*sptr);
		while(sptr->next)
 	   {
		// sptr = sptr->next;
		 dptr->next = new QNode(*sptr->next);
		 sptr = sptr->next;

		 dptr = dptr ->next;
	   }
	}
	/*
	void copy_list(tNode *& dptr,tNode *& sptr);
	copy_list(top,obj.top);
*/
}
CStack& CStack::Push(QNode *& ptr)
{
	ptr->next = top;
	top = ptr;
	ptr = NULL;
	++count; 
	return *this;
}
QNode* CStack::Pop()
{
	QNode* topt = top;
	top = top-> next;
	--count;
	topt->next = NULL;
	return topt;
}
CStack& CStack::operator =(CStack &src)
{
 	if (top)
 	{CStack tmp; tmp.top = top;}
 	CStack tmp(src);
 	top = tmp.top;
	tmp.top = NULL;
 	return *this;
}
bool CStack::IsnotEmpty() const
{
	if (top)
	return true;
	else return false;
}
bool CStack::IsEmpty() const
{
	if (top)
	return false;
	else 
	return true;
}
int CStack::GetCount() const
{
	return count;
}
QNode* CStack::Peak()  const
{
	QNode *tp = new QNode(top->data);
	tp->next = NULL;
	int a = top->data;
	cout<<a;
	return tp;
}
CStack& CStack::print()
{
	QNode * tp = top;
	while(tp)
	{
		cout<<tp->data;
		cout << " ";
		tp = tp-> next;
	}
}
void Delete_list(QNode *ptr)
{
	if (ptr)
	{
		Delete_list (ptr->next);
		delete ptr;	
	}
}
CStack::~CStack()
{
	/*tNode *sptr = top;
	while(top)
	{
		top = top->next;
		delete sptr;
		sptr = top;
	}
	*/
	void Delete_list(QNode *ptr);
	Delete_list(top);
}

//////
class CQueue
{
	public:
		QNode *head,*tail;
		int count;
		CQueue();
		CQueue(QNode* &ptr);
		CQueue(CQueue& src);
		CQueue& operator=(CQueue &src);
		CQueue& Add(QNode* &ptr);
		QNode* Remove();
		bool IsEmpty();
		int GetCount()const;
		int get();
		QNode* getHead();
		CQueue& Print();
		~CQueue();
};
CQueue::CQueue()		//Null constructor
{
	head=tail=NULL;
	count=0;
}
CQueue::CQueue(QNode* &ptr)		//parametric constructor
{
	head=tail=ptr;
	count=1;
	ptr=NULL;
}
CQueue::CQueue(CQueue& obj)		//copy constructor
{
	QNode* copy_queue(QNode* &dptr, QNode* &sptr,QNode *tail);
	this->tail=copy_queue(head,obj.head,NULL);
	this->count=obj.count;
	
}
QNode* copy_queue(QNode* &dptr, QNode* &sptr,QNode *tail)		//copy queue
{
	if(sptr)
	{
		dptr= new QNode(*sptr);
		copy_queue(dptr->next,sptr->next,dptr);	
	}
	else
	{
		dptr=NULL;
		return tail;
	}
	
}
CQueue& CQueue::operator=(CQueue &src)		//assignment operator
{
	if(head)
	{
		CQueue temp;
		temp.head=head;
	}
	CQueue temp(src);
	head=temp.head;
	tail = temp.tail;
	temp.head=temp.tail=NULL;
	count=src.count;
	return *this;
}
CQueue& CQueue::Add(QNode* &ptr)		//Add
{
	if(head)
	{
		tail->next=ptr;
		tail=tail->next;		
	}
	else
	{
		head=tail=ptr;
	}
	++count;
	return *this;
}
QNode* CQueue::Remove()		//remove
{
	QNode *ptr=head;
	if(head==tail)
	{
		head=tail=NULL;
		count=0;
	}
	else
	{
		head=head->next;
		ptr->next=NULL;
		--count;
	}
	return ptr;
}
bool CQueue::IsEmpty()		//IsEmpty
{
	if(!head)
		return true;
	else
		return false;
}
int CQueue::GetCount()const		//get count
{
	return count;
}
int CQueue::get()
{
	return head->data;
}
QNode* CQueue::getHead()
{
	return head;
}
CQueue& CQueue::Print()		//print
{
	QNode* tp=head;
	while (tp)
	{
		tp->print();
		tp = tp->next;
	}
	return *this;
}
CQueue::~CQueue()		//destructor
{
	void delete_queue(QNode *ptr);
	delete_queue(head);
}
void delete_queue(QNode *ptr)	//delete queue
{
	if(ptr)
	{
		delete_queue(ptr->next);
		delete ptr;
	}	
}


//////////////////////////////////////////////////////////////////////
class binaryTree
{
private:
        QNode *root;
public:
        binaryTree();
        
        QNode * getRoot();
        void insertNode(int value,int priority);
		bool IsEmpty();
        void print(QNode * Root);
        void InfixPrint(QNode * Root);
        void PostPrint(QNode * Root);
        void PrePrint(QNode * Root); 
		int insearch(QNode * Root,int value);   
		int presearch(QNode * Root,int value); 
		int postsearch(QNode * Root,int value);
		void display(QNode * Root, int level); 
};

binaryTree::binaryTree()
{
    root = NULL;                    
}

QNode * binaryTree::getRoot()
{
    return root;     
}
void binaryTree::insertNode(int value,int priority)
{
    QNode *newNode = new QNode;
    newNode->data = value;
    newNode->heuristic = priority;
	newNode->left = NULL;
    newNode->right = NULL;
    QNode *current = root;
    QNode *tailCurrent = NULL; 
    if(root == NULL)
    {
       root = newNode;     
    } 
    else
    {
       while(current != NULL)
       {
           if(value > current->data)
           {
              tailCurrent = current;
              current = current->right;      
           }
           else
           {
              tailCurrent = current;
              current = current->left; 
           }          
       }
       if(tailCurrent->data > value)
       {
           tailCurrent->left = newNode;                 
       }
       else
       {
           tailCurrent->right = newNode;
       } 
    }
}
void binaryTree::print(QNode * Root)
{
    cout<< Root->data <<" "; 
}
void binaryTree::InfixPrint(QNode * Root)
{
    if( Root != NULL)
    {
       InfixPrint(Root->left);
       print(Root);
       InfixPrint(Root->right);
    } 
}
void binaryTree::PostPrint(QNode * Root) 
{
    if( Root != NULL)
    {
       InfixPrint(Root->left);
       InfixPrint(Root->right);
       print(Root); 
    } 
}
void binaryTree::PrePrint(QNode * Root) 
{
    if( Root != NULL)
    {
       print(Root); 
       InfixPrint(Root->left);
       InfixPrint(Root->right); 
    }
}

void binaryTree::display(QNode * Root, int level)
{
    int i;
    if (Root != NULL)
    {
        display(Root->right, level+1);
        cout<<endl;
        if (Root == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"\t";
		}
        cout<<Root->data;
        display(Root->left, level+1);
    }
}
bool binaryTree::IsEmpty()		//IsEmpty
{
	if(!root)
		return true;
	else
		return false;
}
/////////////////////////////////////////////////////////////////
int main()
{
    
    binaryTree tree;
    //int response;
    CStack Open,Close;
    CQueue openQueue, closeQueue;
    QNode *optr,*cptr;
    QNode *temp;
	int length,val,find=0;
	cout<<"Enter array length:\t";
	cin>>length;
	int arr[length];
	int hv[length];
	cout<<"Enter nodes and their heristic of "<< endl;
	for(int i=0;i<length;++i)
	{
		cout<<"Element "<<i+1<<":\t";
		cin>>arr[i];
		cout << "\n";
		cout << "Its heuristic value" << i+1 << ":\t";
		cin>>hv[i];
		
	}    
    for(int i=0;i<length;++i)
    {
        tree.insertNode(arr[i],hv[i]);
    }
    
   		cout<<"Enter value to find:\t";
		cin>>val;
		optr=tree.getRoot();
		Open.Push(optr);
    
		while(Open.IsnotEmpty())
    	{
    		cout<<"\n\nOpen Queue\n";
    		Open.print();
    
    		cout<<"\nClose Queue\n";
    		if(closeQueue.IsEmpty())
    			cout<<"NULL";
    		else
    			closeQueue.Print();
			optr=Open.getTop();
    	
			if(Open.get()==val)
    		{
    			find=1;
    			break;
    		}
    		else
    		{
    			find=0;
    			Open.Pop()->data;
				cptr=optr;
    			closeQueue.Add(cptr);
    		if((optr->right != NULL) && (optr->left != NULL)){
    		
    			if(optr->right->heuristic > optr->left->heuristic){
    				Open.Push(optr->left);
    				Open.Push(optr->right);
    				
    			}
    			else{
    				Open.Push(optr->right);
    				Open.Push(optr->left);
    				
    			}
    			}
				else if((optr->right) != NULL && (optr->left == NULL)){
    			
				Open.Push(optr->right);
    			} else if((optr->left) != NULL && (optr->right == NULL)){
    			
					Open.Push(optr->left);
    			}
    		
    		
				
    		}
    }
    if(find==1)
    {
    	cout<<"\nValue is found and path is:\n"<<endl;
    	if(closeQueue.IsEmpty()){
    		cout << "It is root node";
		}else
		closeQueue.Print();
    	cout<<endl;
    	cout<<endl;
    }
    else
    	cout<<"\n\nNot Found\n\n";
    	
  
   return 0;
}
