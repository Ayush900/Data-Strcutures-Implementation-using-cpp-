#include<bits/stdc++.h>
using namespace std;

class node
{

public:
	int data;
	node* left;
	node* right;
	node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

node* insertintoBST(node* root,int data){
	if(root==NULL){
		root=new node(data);
		return root;
	}
	if(data<root->data){
		root->left=insertintoBST(root->left,data);
	}
	else{
		root->right=insertintoBST(root->right,data);
	}
	return root;
}
node* createBST()
{

	int data;
	cin>>data;
	node* root=NULL;
	while(data!=-1){
		root=insertintoBST(root,data);
		cin>>data;
	}
	return root;
}
bool searchbst(node* root, int key)
{
//	while(root != NULL)
//	{
//		if(root->data == key)
//		{
//			return true;
//		}
//		else if(key<root->data)
//		{
//			root=root->left;
//		}
//		else
//		{
//			root=root->right;	
//		}
//		
//	}
//	return false;
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data == key)
	{
		return root;
	}
	else if(key<root->data)
	{
//		root=root->left;
		searchbst(root->left,key);
	}
	else
	{
		searchbst(root->right,key);	
	}
}

node* findminbst(node* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left ==NULL && root->right ==NULL)
	{
		return root;
	}
	root = findminbst(root->left);
	return root;
}

node * deletebst(node* root,int key)
{
	if(root == NULL)
	{
		return root;
	}
	node* root1 = searchbst(root,key);
	if(root1->left==NULL && root1->right==NULL)
	{
		delete root1;
		root1=NULL;
		return root1;
	}
	else if(root1->left==NULL)
	{
		node * temp = root1;
		root1=root1->right;
		delete temp;
		return root1;	
	}
	else if(root1->right==NULL)
	{
		node * temp = root1;
		root1=root1->left;
		delete temp;
		return root1;	
	}
	else
	{
		node* temp=fimdmin(root1->right);
		root1->data=temp->data;
		root1->right = delete(root1->right,temp->data);
		return root1;
	}
}


int main()
{
	node* root=createBST();
	int key;
	cin>>key;
	cout<<boolalpha<<is_bst(root)<<endl;
	
	
}
