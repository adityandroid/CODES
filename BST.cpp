#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
node* insert(node *root,int ip)
{
	
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->data=ip;
		root->right=NULL;
		root->left=NULL;
	}
	
	else if(ip>root->data)
	{
		cout<<"gone right\n";
		root->right=insert(root->right,ip);
	}
	else if(ip<root->data)
	{
		cout<<"gone left\n";
		root->left=insert(root->left,ip);
	}
	return root;
}
void inorder(node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}
int main()
{
	int n;
	node *root=NULL;
	cout<<"n?";
	cin>>n;
	int i,a;
	for(i=0;i<n;++i)
	{
		cin>>a;
		root=insert(root,a);
	}
	inorder(root);
	return 0;
}
