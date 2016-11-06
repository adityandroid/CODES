#include <iostream>
#include <conio.h>
using namespace std;
void min_heapify(int *a,int i,int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
void build_minheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(a,i,n);
    }
}
int remove(int *a,int n)
{
	int i;
	cout<<"Removed "<<a[1]<<endl;
	int ret=a[1];
	for (i=1;i<=n;++i)
	{
		a[i]=a[i+1];
		/*if(i=n)
		{
			continue;	
		}*/
	}
	build_minheap(a,n);
	return ret;
}
void display(int *a,int n)
{
	for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{
    int n, i, x;
    /*cout<<"enter no of elements of array\n";
    cin>>n;*/n=5;
    int a[20]={0,9,8,7,6,5};
    /*for (i = 1; i <= n; i++)
    {
        cout<<"enter element"<<(i)<<endl;
        cin>>a[i];
    }*/
    build_minheap(a, n);
    cout<<"Min Heap\n";
    display(a,n);
    int *b;
    for(i=1;i<=n;++i)
    {
    	
		b[i]=remove(a,n-i);
    	display(a,n-i);
	}
	cout<<"Sorted \n";
	display(b,n);
}
