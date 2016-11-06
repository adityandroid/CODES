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
void deleteN(int ip){
	node *temp,*prev;
	temp = start;
	while(temp !=NULL){
		if(temp->data == ip){
			if (temp == start){			//deleting starting node
				start = temp->next;
				delete temp;
				return;
			}
			else{
				prev = start;				//other cases (middle+last)
				while(prev->next != temp)
					prev = prev->next;		//reached previous node
				 prev->next = temp->next;
				 delete temp;
				 return;
			}
		}
		else
			temp = temp->next;
	}
}
void display(){
	node *temp = start;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->next;
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
	display();
	cout<<"deleted 4\n";
	deleteN(4);
	display();
	return 0;
}
