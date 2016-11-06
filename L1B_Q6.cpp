#include<iostream>
using namespace std;
int stack[20];
int top=-1;
void push(int ip)
{
	stack[++top]=ip;
}
int pop()
{
	return(stack[top--]);
}
int que[20];
int f=0;int r=0;
void inque(int ip)
{
	que[r]=ip;
	r++;
}
int deque()
{
	return(que[f++]);
}
void doubler()
{
	int len=r-f;
	int i;
	for(i=0;i<len;++i)
	inque(pop());
	
	for(i=0;i<len;++i)
	{
		push(que[i]);
		push(que[i]);
	}
	
	while(top!=-1)
	cout<<pop();
	
	
	
	
}
int main()
{
	int n,i;
	cout<<"n?";
	cin>>n;
	for(i=0;i<n;++i)
	{
		push(i);	
	}
	for(i=0;i<n;++i)
	cout<<stack[i];
	cout<<endl;
	doubler();
	return 0;
}
