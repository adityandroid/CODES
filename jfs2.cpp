#include<iostream>
#include<dos.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
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
	while(burstSum!=0)
	{
		for(j=0;j<(artime[i+1]-artime[i]);++j)
		{
			if(i==0) //for first time run
			{
				pburst[i]--;
				burstSum--;
				cout<<"Runnin process PID A "<<pburst[i]<<"\n";
			}
			else
			{
				//select shortest burst time wala process
				//fir usme se -1
				for(k=0;k<n;++k)
				{
					if(pburst[k] < min && pburst[k]!=0 ) //so that it dose not pick up completed processes
					{
						min=pburst[k];
						minIndex=k;
					}
				}
				pburst[minIndex]--;
				burstSum--;
				m=65+minIndex;
				//cout<<"Runnin process PID "<<" "<<pburst[k]<<"\n";
				printf("Runnin process PID %c %d \n",m,pburst[minIndex]);
			}
			
		}
	}
	/*cout<<"On to the next one\n";
	minIndex=0;
	for(i=0;i<n;++i)
	{
		for(k=0;k<n;++k)
			{
				if( (pburst[k] < min) /*&& (pburst[k]!=0)*//* ) //so that it dose not pick up completed processes
					{
						min=pburst[k];
						minIndex=k;
					}
				
			}
		pburst[minIndex]--;
		m=65+minIndex;
		//cout<<"Runnin process PID "<<" "<<pburst[k]<<"\n";
		printf("Runnin process PID %c %d \n",m,pburst[minIndex]);	
	}*/
		
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
