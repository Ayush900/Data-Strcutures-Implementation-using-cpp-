#include<bits/stdc++.h>
using namespace std;


class tnode
{
	public:
		int data;
		tnode* left;
		tnode* right;
		
		tnode(int x)
		{
			data = x;
			left = NULL;
			right = NULL;
		}
};

tnode* createtree()   // create a tree such that the next element gets added to the furthest left until -1 appears ..
{
	int x;
	cin>>x;
	if(x == -1)
	{
		return NULL;	
	}
	tnode* root = new tnode(x);
	root->left = createtree();
	root->right = createtree();
	return root;
}

void preordertraversal(tnode* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preordertraversal(root->left);
	preordertraversal(root->right);
}

void postordertraversal(tnode* root)
{
	if(root == NULL)
	{
		return;
	}
	postordertraversal(root->left);
	postordertraversal(root->right);
	cout<<root->data<<" ";
}

void inordertraversal(tnode* root)
{
	if(root == NULL)
	{
		return;
	}
	inordertraversal(root->left);
	cout<<root->data<<" ";
	inordertraversal(root->right);
}

void levelordertraversal(tnode* root)
{
	queue<tnode*> q;
	q.push(root);
	while(q.empty() == false)
	{
		tnode* current = q.front();
		q.pop();
		cout<<current->data<<" ";
		if(current->left)
		{
			q.push(current->left);	
		}
		if(current->right)
		{
			q.push(current->right);	
		}
	}
	return;
}

void levelordertraversal1(tnode* root) // The different levels are printed at different lines ..
{
	queue<tnode*> q;
	q.push(root);
	while(q.empty() == false)
	{
		int no_at_level = q.size();
		while(no_at_level>0)
		{
			tnode* current = q.front();
			q.pop();
			cout<<current->data<<" ";
			if(current->left)
			{
				q.push(current->left);	
			}
			if(current->right)
			{
				q.push(current->right);	
			}
			no_at_level--;
		}
		cout<<endl;

	}
	return;
}

static int c = 0;

int totalnodes(tnode* root)
{
	if(root != NULL)
    {
        totalnodes(root->left);
        c++;
        totalnodes(root->right);
    }
    return c;

}

int height(tnode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else{
		int l_height = height(root->left);
		int r_height = height(root->right);
		int ans = max(l_height,r_height) + 1;
		return ans;
	}
}

int diameter(tnode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else{
		int op1 = height(root->left) + height(root->right) + 1;
		int op2 = diameter(root->left);
		int op3 = diameter(root->right);
		int ans = max(op1,max(op2,op3));
		return ans;
	}
}

bool isbalanced(tnode* root)
{
	if(root == NULL)
	{
		return true;
	}
	int ans = abs(height(root->left)-height(root->right));
	if(ans<=1 && isbalanced(root->left) && isbalanced(root->right))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void mirrorinverse(tnode* root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		tnode *temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp;
		mirrorinverse(root->left);
		mirrorinverse(root->right);
	}
	
}

void leftmostnode(tnode* root)
{
	while(root!=NULL && root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

void rightmostnode(tnode* root)
{
	while(root!=NULL && root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}



int main()
{
	tnode* root = createtree();
	cout<<"PreOrderTreeTraversal:"<<endl;
	preordertraversal(root);
	cout<<endl;
	cout<<"PostOrderTreeTraversal:"<<endl;
	postordertraversal(root);
	cout<<endl;
	cout<<"InOrderTreeTraversal:"<<endl;
	inordertraversal(root);
	cout<<endl<<"LevelOrderTreeTraversal:"<<endl;
	levelordertraversal(root);
	cout<<endl<<"LevelOrderTreeTraversal Line by Line :"<<endl;
	levelordertraversal1(root);	
	int cnt = totalnodes(root);
	
	
	cout<<endl<<"Total number of nodes in the tree:"<<cnt;
	
	int h = height(root);
	
	cout<<endl<<"Height of the tree:"<<h;
	
	int d = diameter(root);
	
	cout<<endl<<"diameter of the tree:"<<d;
	
	cout<<endl<<"Is the tree balanced? "<<endl;
	
	cout<<boolalpha<<isbalanced(root)<<endl;
	
	mirrorinverse(root);
	
	cout<<"InOrderTreeTraversal of mirror inverse:"<<endl;
	inordertraversal(root);
	
	mirrorinverse(root);
	

	
	return 0;
}


// 3 2 5 8 -1 -1 -1 6 -1 -1 1 7 -1 -1 -1

// 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1








  
















