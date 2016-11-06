#include <stdio.h>
#include<iostream>
using namespace std;
char third(char a, char b)
{
    if((a=='R' && b=='G')||(a=='G' && b=='R')  )
    return 'B';
    else if((a=='R' && b=='B')||(a=='B' && b=='R')  )
    return 'G';
    else if((a=='B' && b=='G')||(a=='G' && b=='B')  )
    return 'R';
    
}
int noofs(char ar[1000],int n)
{
    int i;
    int count=0;
    char br[1000];
    int k=0;
    for(i=0;i<n;++i)
	{
		if(ar[i]!=ar[i+1])
		{
			br[k]=third(ar[i],ar[i+1]);
			k++;
			i++;
		}
		else
		{
		    br[k]=ar[i];
		    br[k+1]=ar[i+1];
		    k++;
		    i++;
		}
	}
	 for(i=0;i<n;++i)
	{
		if(br[i]=='G' || br[i]=='B' || br[i]=='R' )
		count++;
	}
	return count;
	
    
}
int main() 
{
	char ar[1000];
	int ans[1000];
	int n;
	int i,j,k,noof;
	k=0;
	cin>>n;
	
	for(i=0;i<n;++i)
	{
	    cin>>noof;
	    for(j=0;j<noof;++j)
	    {
	        cin>>ar[j];
	    }
	    ans[k]=noofs(ar,noof);
	    k++;
	    
	}
	for(i=0;i<n;++i)
	{
		if(ans[i]==0)
		i++;
		else
		cout<<ans[i];	
	}
	return 0;
}
