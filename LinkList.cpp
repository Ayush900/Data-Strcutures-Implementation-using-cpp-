#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
		int data;
		node* next;
		
		node(int x)
		{
			data = x;
			next = NULL;
		}
		
};

class linklist
{
	public:
		node* head;
		node* tail;
		
		linklist()
		{
			head = NULL;
			tail = NULL;
		}
		
		void insertAtend(int x)
		{
			if(head==NULL){
				head=new node(x);
				tail=head;
			}
			else{
				node *temp=new node(x);
				tail->next=temp;
				tail=temp;
			}
		}

		void print()
		{
			node *temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"--> ";
				temp=temp->next;
			}

		}
		
		int size()
		{
			int s =0;
			node* temp = head;
			while(temp!=NULL)
			{
				s++;
				temp=temp->next;
			}
			return s;
		}
		
		void delatpos(int pos)
		{
			if(pos == 0)
			{
				node* t = head;
				head=head->next;
				delete t;
			}
			else
			{
				node* temp = head;
				node* temp1 = temp->next;
				int ct = 1;
				while(ct!=pos)
				{
					temp=temp->next;
					temp1=temp1->next;
					ct++;
				}
				temp->next=temp1->next;
				delete temp1;				
			}
			return;
		
		}
		
		
	
};


node* reversell(node* head)
{
	node* current = head;
	node* prev = NULL;
	node* n;
	while(current!=NULL)
	{
		n = current->next;
		current ->next = prev;
		prev = current;
		current = n;
	}
	
	return prev;
}

node* findmid(node* head)
{
	node* s = head;
	node* f = head->next;
	while(f!=NULL && f->next!=NULL)
	{
		s=s->next;
		f=f->next->next;
	}
	return s;
}

node* kappend(int n,int k,node* head)
{
	if(k>=n)
	{
		return head;
	}
	else
	{
		int c=1;
		node* f=head;
		while(c<=k-1)
		{
			f=f->next;
			c++;
		}
		
		node* s = head;
		while(f->next!=NULL)
		{
			s=s->next;
			f=f->next;
		}
		node* temp = head;
		while(temp->next!=s)
		{
			temp=temp->next;
		}
		f->next =head;
		temp->next =NULL;
		head = s;
		return head;
	}
}

node* mergell(node*a,node*b)
{
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}
	node* c;
	if(a->data < b->data)
	{
		c=a;
		c->next = mergell(a->next,b);
	}
	else
	{
		c=b;
		c->next = mergell(a,b->next);
	}
	return c;
}

node* mergesortll(node* head)
{
	if(head==NULL || head->next == NULL)
	{
		return head;
	}
	
	node* mid = findmid(head);
	node* head1 = head;
	node* head2 = mid->next;
	mid->next = NULL;
	head1 = mergesortll(head1);
	head2 = mergesortll(head2);
	head = mergell(head1,head2);
	return head;
}

int main()
{
	linklist l;
	l.insertAtend(5);
	l.insertAtend(4);
	l.insertAtend(9);
	l.insertAtend(1);
	l.insertAtend(6);
	l.print();
	cout<<endl;
	int n = l.size();
	cout<<n;
	cout<<endl;
	l.head = mergesortll(l.head);
	l.print();
//	l.delatpos(0);
//	l.print();
//	l.head = reversell(l.head);
//	l.print();

//	l.head = kappend(n,1,l.head);
//	l.print();

//	node* mid = findmid(l.head);
//	cout<<mid->data;

	l.head = mergesortll(l.head);
	return 0;
}

//#include<iostream>
//using namespace std;
//
//class node{
//	public:
//		int data;
//		node* next;
//
//		node(int x)
//		{
//			data = x;
//			next = NULL;
//		}
//
//};
//
//
//class linkedlist
//{
//	public:
//		node* head;
//		node* tail;
//		linkedlist()
//		{
//			head = NULL;
//			tail = NULL;
//		}
//		void insertAtend(int x)
//		{
//			if(head == NULL)
//			{
//				head = new node(x);
//				tail = head;
//			}
//			else{
//				node* temp = new node(x);
//				tail->next = temp;
//				tail = temp;
//			}
//		}
//		void print()
//		{
//			node* temp = head;
//			while(temp!=NULL)
//			{
//				cout<<temp->data<<" ";
//				temp = temp->next;
//			}
//		}
//};
//
//node* reversell(node* head)
//{
//	node* prev = NULL;
//	node* current = head;
//	node* next1;
//	while(current!=NULL)
//	{
//		next1 = current->next;
//		current->next = prev;
//		prev = current;
//		current = next1;
//	}
//	// head = prev;
//	return prev;
//}
//
int main()
{

	linkedlist l;
	l.insertAtend(1);
	l.insertAtend(2);
	l.insertAtend(3);
	l.insertAtend(4);
	l.insertAtend(5);
	
	l.print();
	cout<<endl;
	l.head = reversell(l.head);
	l.print();
	return 0;
}

