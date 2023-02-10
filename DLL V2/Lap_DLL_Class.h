#include <iostream>
using namespace std;
template <class T>
class node{
	public:
		T info;
		node<T>* next;
		node<T>* prev;
		public:
		node(){
			next=prev=0;
		}
		node(T inf,node<T>* n,node<T>* p){
			info=inf;
			next=n;
			prev=p;
		}
	
};
template <class T>
class DLL{
	private:
		node<T>* head;
		node<T>* tail;
		public:
		DLL(){
			head=tail=0;
		}
		bool isempty(){
			return head==0;
		}
		void addtohead(T data){
			node<T>* tmp=new node<T>(data,0,0);
			if(!isempty()){
			tmp->next=head;
			head->prev=tmp;
			head=tmp;
			}
			else{
				head=tail=new node<T>(data,0,0);
			}
		}
		void addtotail(T data){
			if(!isempty()){
			node<T>* tmp=new node<T>(data,0,tail);
			tail->next=tmp;
			tail=tmp;
			}
			else{
				head=tail=new node<T>(data,0,0);
			}
		}
		void deletefromhead(){
			if(!isempty()){
				node<T>* tmp=head;
				head=head->next;
				delete tmp;
				tmp=0;
				cout<<"Deleted seccessfully."<<endl;
			}
			else
			cout<<"The node is empty."<<endl;
		}
		void deletefromtail(){
			if(!isempty()){
				node<T>* tmp=tail;
				tail=tmp->prev;
				tail->next=0;
				delete tmp;
				tmp=0;
					cout<<"Deleted seccessfully."<<endl;
			}
			else
			cout<<"The node is empty."<<endl;
		}
		void display(){
			if(!isempty()){
			node<T>* tmp=head;
			cout<<"The Item in node is :"<<endl;
			while(tmp!=0){
				cout<<tmp->info<<endl;
				tmp=tmp->next;
			}
			
		}
		else
		{
			cout<<"the node is empty."<<endl;
		}
		}
	node<T>* search(T item){
		if(!isempty()){
		node<T>* tmp=head;
		while(tmp!=0){
			if(tmp->info==item){
				return tmp;
				//break;
			} 
			 tmp=tmp->next;
		}
		return 0;
	}
	else
	return 0;
	}
	void addtomiddle(int item,int data){
		node<T>* found=search(item);
		if(isempty())
		addtohead(data);
		if(tail->info==item||found==0){
			addtotail(data);
		}
		else{
			node<T>* tmp2=new node<T>(data,found->next,found);
					found->next->prev=tmp2;
					found->next=tmp2;
					cout<<"The item is add seccessfully."<<endl;
		}
	}
		void deletenode(T item){
		if(!isempty()){
		
		if(head->info==item){
			deletefromhead();
		}
		else if(tail->info==item){
			deletefromtail();
		}
		else if(head!=tail){
		node<T>* num=search(item);
		if(num!=0){
			node<T>* tmp=num;	
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			delete tmp;
			cout<<"The item deleted seccessfully."<<endl;
		}
		}	
		}
		
		else 
		cout<<"The item didn't deleted seccessfully.\n\t\t\t\tBecause the node its empty."<<endl;

	}

	void oddnumber(){
			if(!isempty()){
			node<T>* tmp=head;
			cout<<"The odd numbers which followed by even numbers are :"<<endl;
			while(tmp->next!=tail){
				
				if(tmp->info%2!=0&&tmp->next->info%2==0){
					cout<<tmp->info<<endl;
				}
				tmp=tmp->next;
			}
			
		}
		else
		{
			cout<<"the node is empty."<<endl;
		}
	}

	
};
