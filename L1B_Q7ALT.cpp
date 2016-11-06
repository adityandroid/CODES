#include<iostream>
using namespace std;
int queue1[20];
int f1=0,r1=0;
void inqueue1(int ip)
{
	queue1[r1]=ip;
	r1++;
}
int dequeue1()
{
	return(queue1[f1++]);
}

int queue2[20];
int f2=0,r2=0;
void inqueue2(int ip)
{
	queue2[r2]=ip;
	r2++;
}
int dequeue2()
{
	return(queue2[f2++]);
}

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
magicHalves(int queue[20])
{
	cout<<"Here is the magic\n";
	int i;
	int len1=r1-f1;
	int len2=r2-f2;
	
	for(i=0;i<len1/2;++i)
	inqueue2(queue1[i]);
	
	for(i=0;i<len1/2;++i)
	push(queue2[i]);
	
	for(i=0;i<len1/2;++i)
	inqueue2(pop());
	
	
	
	for(i=(len1/2);i<len1;++i)
	inqueue2(queue1[i]);
	
	for(i=(len1/2);i<len1;++i)
	push(queue1[i]);
	
	for(i=len1/2;i<len1;++i)
	inqueue2(pop());
	
	
	
	
	
	
	
	
	for(i=f2;i<r2;++i)				//displays o/p
	cout<<" "<<queue2[i]<<" ";
	
}
int main()
{
	int n,i;
	cout<<"n?";
	cin>>n;
	for(i=1;i<n+1;++i)
	inqueue1(i);
	
	for(i=f1;i<r1;++i)
	cout<<" "<<queue1[i]<<" ";
	cout<<endl;
	magicHalves(queue1);
	
	/*for(int i=0;i<7;++i)
	{
		cout<<" "<<dequeue1()<<" ";
	}*/
	
	return 0;
}
