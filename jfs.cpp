#include<iostream>
#include<dos.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int findmin(int ar[20],int n,int max)
{
	int index;
	int min=900;
	if (n==0)
	return 0;
	else if(n!=max)
	{
		for(int i=0;i<=n;++i)
		{
			if(ar[i]<=0)
			i++;
			else
			{
				if(ar[i]<min)
				{	
					min=ar[i];
					index=i;
				}
			
			}
		}	
	}
	else
	{
	
		for(int i=0;i<max;++i)
		{
			if(ar[i]<=0)
			i++;
			else
			{
				if(ar[i]<min)
				{	
					min=ar[i];
					index=i;
				}
				
			}
		}
	}
	return index;
}
void displayburst(int ar[20],int n,int max)
{
	char m=65;
	/*if(n==0)
	printf("%c %d\t",m+0,ar[0]);*/
	if(n!=max)
	{
		for(int i=0;i<=n;++i)
		printf("%c %d \t",m+i,ar[i]);
		cout<<endl;
	}
	else
	{
		for(int i=0;i<max;++i)
		printf("%c %d \t",m+i,ar[i]);
		cout<<endl;
	}
}
void jfsP(int pburst[20],int n, int cs ,int artime[20])
{
	int j,i,trtime[20],k;
	float avg=0.00;
	int sum=0;
	int min=900;
	int minIndex;
	int m;
	int burstSum=0;
	
	
	for(i=0;i<n;++i)
	burstSum=burstSum+pburst[i];
	
	system("cls");
	cout<<"\n\nJFS Preemptive\n\n";
	displayburst(pburst,n,n);
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<(artime[i+1]-artime[i]);++j)
		{
			if(i==0) //for first time run
			{
				pburst[i]--;
				burstSum--;
				cout<<"Runnin process PID A "<<pburst[i];
				//cout<<"i= "<<i<<"\n";
				sum++;
				cout<<"sum= "<<sum<<"\n";
				
				displayburst(pburst,i,n);	
					
			}
			else
			{
				//select shortest burst time wala process
				//fir usme se -1
				int y=i;
				minIndex=findmin(pburst,i,n);
				pburst[minIndex]--;
				burstSum--;
				m=65+minIndex;
				sum++;
				//cout<<"Runnin process PID "<<" "<<pburst[k]<<"\n";
				printf("Runnin process PID %c %d ",m,pburst[minIndex]);
				cout<<"sum= "<<sum<<"\n";
				//cout<<"i= "<<i<<"\n";
				
				displayburst(pburst,i,n);
				
			}
			
		}
	}
	m=65;
	minIndex=0;
	//when all processes have arrived
	for(i=0;i<burstSum;++i)
	{
		minIndex=findmin(pburst,n,n);
		pburst[minIndex]--;
		m=65+minIndex;
		sum++;
		//cout<<"Runnin process PID "<<" "<<pburst[k]<<"\n";
		printf("Runnin process PID %c %d",m,pburst[minIndex]);	
		cout<<"sum= "<<sum<<"\n";
		
		displayburst(pburst,n,n);
		
	}
		cout<<"\nt t "<<sum;
}
int main()
{
	int i,n,cs;
	char choice;
	int par[20]; //array to store CPU burst time of each process
	int artime[20];
	cout<<"Enter no of processes\n";
	cin>>n;
	for(i=0;i<n;++i)
	{
		cout<<"Enter process "<< i+1 <<" Burst time\n";
		cin>>par[i];
	}
	
	
	for(i=0;i<n;++i)
	{
		cout<<"Enter arrival time of processes in ascending order "<< i+1 <<"\n";
		cin>>artime[i];
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
	
	jfsP(par,n,cs,artime);
	
	return 0;
}
