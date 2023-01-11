#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*pre;
};
class doubly{
	node*first;
	node*last;
	public:
		doubly(){
			first=NULL;
			last=NULL;
		}
		void add_start(int v){
			if(first==NULL){
				first=new node;
				first->data=v;
				first->next=NULL;
				first->pre=NULL;
				last=first;
				return;
			}
			node*ptr=new node;
			ptr->data=v;
			ptr->next=first;
			first->pre=ptr;
			first=ptr;
			first->pre=NULL;
		}
		void add_last(int v){
			if(first==NULL){
					first=new node;
				first->data=v;
				first->next=NULL;
				first->pre=NULL;
				last=first;
				return;
			}
			node*ptr=new node;
			last->next=ptr;
			ptr->pre=last;
			ptr->next=NULL;
			last=ptr;
			last->data=v;
			last->next=NULL;
			
		}
		void remove_start(){
			if(first->next==NULL){
				delete first;
				first=NULL;
				last=NULL;
			}
			node*ptr=first;
			first=first->next;
			first->pre=NULL;
			delete ptr;
		}
		void remove_end(){
			if(first->next==NULL){
					delete first;
				first=NULL;
				last=NULL;
			}
			node*ptr=last;
			last=last->pre;
			last->next=NULL;
			delete ptr;	
		}
		void show_forward(){
			cout<<"values in forward are:"<<endl;
			node*ptr=first;
			while(ptr->next!=NULL){
				cout<<ptr->data;
				ptr=ptr->next;
			}
			cout<<ptr->data;
		}
		void show_backward(){
			cout<<"values in backward:"<<endl;
			node*ptr=last;
			while(ptr->pre!=NULL){
				cout<<ptr->data;
				ptr=ptr->pre;
			}
			cout<<ptr->data;
		}
		void insert_loc(int v,int loc){
			node*ptr=first;
			int i=1;
			while(i<loc){
				ptr=ptr->next;
				i++;
			}
		node*ptr2=new node;
	ptr2->pre=ptr;
		ptr->next->pre=ptr2;
		ptr2->next=ptr->next;
		ptr->next=ptr2;
		ptr2->data=v;
		}
};
int main(){
	doubly obj;
	obj.add_start(5);
	obj.add_start(4);
	obj.add_start(3);
	obj.add_last(6);
	obj.add_last(7);
	obj.add_last(8);
		obj.insert_loc(10,3);
	obj.remove_start();
	obj.remove_end();
	obj.show_backward();
	cout<<"\n";
	obj.show_forward();

	return 0;
	
}