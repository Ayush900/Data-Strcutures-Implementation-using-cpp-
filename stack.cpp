#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class node
{
	public:
		T data;
		node* next;
		
		node(T x)
		{
			data = x;
			next = NULL;
		}
		
};

template<typename T>
class stack
{
	public:
		node<T>* top;
		
		stack()
		{
			top = NULL;
		}
		
		void push(T x)
		{
			node<T>* temp = new node<T>(x);
			if(top == NULL)
			{
				top = temp;
			}
			else{
				temp->next = top;
				top = temp;
			}
		}
		
		void pop()
		{
			if(top == NULL)
			{
				return;
			}
			else
			{
				node<T> * t = top;
				top = top->next;
				delete t;		
			}
		}
		
		void print()
		{
			node<T>* temp=top;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;				
			}
		}
		
		bool isempty()
		{
			if(top==NULL)
			{
				return true;
			}
			else{
				return false;
			}
		}
		
		
		
};

int main()
{
	stack<char> st;
//	for(int i=0;i<5;i++)
//	{
//		s.push(i+1);
//	}
//	s.push('A');
//	s.push('B');
//	s.push('C');
//	s.push('D');
//	s.push('E');
//	s.push('F');
//	while(!s.isempty())
//	{
//		cout<<s.top->data<<endl;
//		s.pop();
//	}


	char s[100];
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		st.push(s[i]);
	}
//	cout<<s;
	string s1="";
//	cout<<endl<<s;
	for(int i=0;i<strlen(s);i++)
	{
//		cout<<st.top->data;
		s1 = s1+st.top->data;
		st.pop();
	}
	cout<<s1;
	
	
	
	
	
	
	
	
	return 0;
}
