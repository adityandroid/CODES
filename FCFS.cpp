#include<iostream>
#include<dos.h>
using namespace std;
void fcfs(int par[20],int n, int cs)
{
	int i,trtime[20];
	float avg=0.00;
	int sum=0;
	for(i=0;i<n;++i)
	{
		sum=sum+par[i];
		trtime[i]=sum+(i*cs);
		
	}
	system("cls");
	cout<<"\n\nFCFS\n\n";
	cout<<"\nTotal execution time "<<(sum+(n-1)*cs)<<"\n\n";
	for(i=0;i<n;++i)
	{
		cout<<"Turnaround time for Process "<<i+1<<"= "<<trtime[i]<<endl;	
	}
	cout<<"\n\nWaiting time for Process "<<"1"<<"= "<<"0"<<endl;
	for(i=0;i<n-1;++i)
	{
		cout<<"Waiting time for Process "<<i+2<<"= "<<trtime[i]<<endl;
		avg=trtime[i]+avg;
	}
	cout<<"\n\nAverage waiting time "<<avg/(n*1.00)<<"\n\n";
	
}
int main()
{
	int i,n,cs;
	char choice;
	int par[20]; //array to store CPU burst time of each process
	cout<<"Enter no of processes\n";
	cin>>n;
	for(i=0;i<n;++i)
	{
		cout<<"Enter process "<< i+1 <<" Burst time\n";
		cin>>par[i];
	}
	cout<<"Do you wish to enter Context swithing time?(y/n) or (1/0) \n";
	cin>>choice;
	if(choice=='y'||choice=='Y'||choice==49)
	{
		cout<<"Enter CS time\n";
		cin>>cs;
	}
	else 
	cs=0;
	
	fcfs(par,n,cs);
	
	return 0;
}
