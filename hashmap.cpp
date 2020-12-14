#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	string key;
	int value;
	node* next;
	
		node(string k, int val)
		{
			value = val;
			key = k;
			next=NULL;
		}
};

class HashMap
{
	node **table;
	int table_size;
	int current_size;
	public:
		HashMap(int n=7)
		{
			table_size=n;
			current_size=0;
			table=new node*[table_size];
			for(int i=0;i<table_size;i++)
			{
				table[i]=NULL;
			}
		}
		
		int hashfunction(string key)
		{
			int index=0;
			int myval=1;
			for(int i=0;i<key.length();i++)
			{
				index=index+(key[i]*myval)%table_size;
				myval=myval*27%table_size;
			}
			return index%table_size;
		}
		
		void insert(string key,int value)
		{
			int index = hashfunction(key);
			node* n = new node(key,value);
			n->next=table[index];
			table[index] = n;
			current_size++;
			
		}
		
		int search(string key1)
		{
			int index=hashfunction(key1);
			node* t=table[index];
			while(t!=NULL)
			{
				if(t->key == key1)
				{
					return t->value;
				}
				t=t->next;
			}
			return -1;
			
		}
		
		int currensizeoftable()
		{
			return current_size;
		}
		
		int total_table_size()
		{
			return table_size;
		}
		
		void print()
		{
			for(int i=0;i<table_size;i++)
			{
				node* temp = table[i];
				cout<<"index:"<<i;
				while(temp!=NULL)
				{
					cout<<"( "<<temp->key<<","<<temp->value<<" )"<<"-->";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
		
};

int main()
{
	HashMap h;
	h.insert("ayush",50);
	h.insert("mehrotra",10);
	h.print();
	cout<<endl<<h.search("ayush")<<endl;
	return 0;
}
