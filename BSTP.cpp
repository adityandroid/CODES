#include<iostream>
#include<malloc.h>
using namespace std;
struct node {
	int data;
	node *left,*right;
};
node* insert(node *root,int ip)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->data=ip;
		root->right=root->left=NULL;
	}
	else if(ip>root->data)
	{
		cout<<"Gone Right\n";
		root->right=insert(root->right,ip);
	}
	else
	{
		cout<<"Gone left\n";
		root->left=insert(root->left,ip);
	}
}
void inorder(node *root)
{
	if(root==NULL)
	return;
	
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}
int size(node *root)
{
	if(root==NULL)
	return 0;
	
	else
	{
		int lh=size(root->left);
		int rh=size(root->right);
		
		if(lh>rh)
		return lh+1;
		else
		return rh+1;
	}
}
int minVal(node *root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;
}
int maxVal(node *root)
{
	while(root->right!=NULL)
	root=root->right;
	
	return root->data;
}
int pathsum(node *root)
{
	if(root==NULL)
	return root->data;
	
	else
	{
		int suml=pathsum(root->left);
		int sumr=pathsum(root->right);
		
		cout<<"sum l "<<suml<<endl;
		cout<<"sum r "<<sumr<<endl;
	}
}
int main()
{
	node *root=NULL;
	int n,i,a;
	cout<<"n?";
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>a;
		root=insert(root,a);
	}
	inorder(root);
	/*a=size(root);cout<<" "<<a;
	a=minVal(root);cout<<" "<<a;
	a=maxVal(root);cout<<" "<<a;*/
	pathsum(root);
	return 0;
}
