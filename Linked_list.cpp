#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
	
	node (int ip){
		data = ip;
	}
	node(){
	}
	
}*start = NULL,*current;
void create(int ip){
	node *temp;
	temp = new node;
	cout<<temp<<endl;
	if(start == NULL){
		temp->data = ip;
		temp->next = NULL;
		start = temp;
		current = temp;
	}
	else{
		temp->data=ip;
		current->next = temp;
		temp->next=NULL;
		current = temp;
	}	
	
}
int main(){
	int n,ip;
	cin>>n;
	cout<<"\n";
	for(int i=0;i<n;++i){
		cout<<"data? \n";
		cin>>ip;
		create(ip);
	}
	node *temp = start;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->next;
	}
	return 0;
}
