#include <iostream>
using namespace std;
template <class T>
class node{
	public:
		T info;
		node<T>* next;
		node<T>* prev;
		node(){
			next=prev=0;
		}
		node(T data,node<T> *n,node<T> *p){
			info=data;
			next=n;
			prev=p;
		}		
};
template <class T>
class DLL{
	public:
		node<T>* head;
		node<T>* tail;
		DLL(){
			head=tail=0;
		}
		bool isempty(){
			return head==0;
		}
			void clear(){
			node<T>* tmp;
			
			while(!isempty()){
			tmp=head;
			head=head->next;
			delete tmp;
			if(head==0)
			tail=0;
			else
			head->prev=0;	
			}
			cout<<"The node clreared seccessfully."<<endl;
			//tail=0;
			
			
		}
		~DLL(){
			clear();
			
		}
	
		T First(){
			T first=0;
			if(!isempty()){
				first=head->info;
				cout<<"The first data is :  "<<first<<endl;
				return first;			}
			return first;
		}
		T Last()
		{
				T last=0;
			if(!isempty()){
				last=tail->info;
				cout<<"The last data is :  "<<last<<endl;
				return last;
			}
			return last;
		}
		void addtohead(T data){
			if(! isempty()){
			head=new node<T>(data,head,0);
			head->next->prev=head;
			cout<<"The item add seccessfully."<<endl;
		}
		else {
			head=tail=new node<T>(data,0,0);
			cout<<"The item add seccessfully."<<endl;
		}
	}
		void addtotail(T data){
			if(!isempty()){
			tail->next=new node<T>(data,0,tail);
			tail=tail->next;
			cout<<"The item add seccessfully."<<endl;
		}
		else {
		head=tail=new node<T>(data,0,0);
		cout<<"The item add seccessfully."<<endl;
		}
		}
		void addinorder( T item){
			if(!isempty()){
				if(head->info>item)
				addtohead(item);
				else if(tail->info<item)
				addtotail(item);
				else{
					node<T>* tmp=head;
					while(tmp->next->info<item){
					tmp->next;
					
					}
					//check this function.
					tmp->next=new node<T>(item,tmp->next,tmp);
					tmp->next->prev=tmp->next;
					cout<<"Add seccessfully."<<endl;
					
				}
				
				
				
				
			}
			else
			cout<<"Error"<<endl;
			
			
			
		}
		void deletefromhead(){
			
			if(!isempty()){
			node<T>* tmp=head;
			head=head->next;
			head->prev=0;
			delete tmp;
			cout<<"The item deleted seccessfully."<<endl;
			if(head==0){
				tail=0;
			}
			else 
			head->prev=0;	
			}
			else 
			cout<<"The item didn't deleted seccessfully.\n\t\t\t\tBecause the node its empty."<<endl;
		}
		void deletefromtail(){
			
			if(!isempty()){
			node<T>* tmp=tail;
			tail=tail->prev;
			delete tmp;
			cout<<"The item deleted seccessfully."<<endl;
			if(tail==0){
				head=0;
			}
			else 
			tail->next=0;	
			}
			else 
			cout<<"The item didn't deleted seccessfully.\n\t\t\tBecause the node its empty."<<endl;
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
					//tmp2->next=tmp->next=>
					//tmp->prev=tmp=>tmp->next->prev
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
			node<T>* tmp2;
			node<T>* tmp=num;	
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			delete tmp2;
			cout<<"The item deleted seccessfully."<<endl;
		}
		}	
		}
		
		else 
		cout<<"The item didn't deleted seccessfully.\n\t\t\t\tBecause the node its empty."<<endl;

	}
	void display(){
		if(!isempty())
	{
		T tmp;
		node<T>* num=head;
		cout<<"The item in the list is :  "<<endl;
		while(num!=0){
			tmp=num->info;
			cout<<tmp<<endl;
			num=num->next;
		}
	}
		else{
			
			char name;
			int data;
			cout<<"The double linked list is empty.\n Did you want to add to it (Y/N) :"<<endl;
			cin>>name;
			if(name=='y' || name =='Y'){
				cout<<"Please enter the data :"<<endl;
				cin>>data;
			addtohead(data);
			}
	}

	}	
	float sum(){
		T num=0;
		node<T>* tmp=head;
		if(!isempty())
	{
		if(tmp==tail){
			num=head->info;
		}
		else{
		while(tmp!=0){
			num+=tmp->info;
			tmp=tmp->next;
		}
	}
	
		return num;

	}
	else 
	return num;
}
	float counter(){
		T count=0;
		node<T>* num=head;
		if(!isempty()){
			while(num!=0){
			++count;
			num=num->next;	
			}
			
			return count; 
		}
		return count;
	}	
	void average(){
		float res=sum();
		float avrg;
		float count=counter();
		if(res==0){
			cout<<"The node is empty."<<endl;
		}
		else{
		avrg=res/count;
		cout<<"The average of element is :  "<<avrg<<endl;	
		}
	}
	void maxnumber(){
	if(!isempty()){
		node<T>* tmp=head;
		node<T>* tmp2=head->next;
		node<T>* max;
		while(tmp!=0){
			if(tmp->info>tmp2->info){
				max=tmp;
			}
			tmp=tmp->next;			
		}
		cout<<"The maximum number in this node is :  "<<max->info<<endl;
		}
		else
		cout<<"The node is empty."<<endl;
	}
	void minnumber(){
		if(!isempty()){
		node<T>* tmp=head;
		node<T>* tmp2=head->next;
		node<T>* min;
		while(tmp!=0){
			if(tmp->info<tmp2->info){
				min=tmp;
			}
			tmp=tmp->next;			
		}
			cout<<"The minimum number in this node is :  "<<min->info<<endl;

		}
		else
		cout<<"The node is empty."<<endl;
	}
	void converttoarray(){
		int size=counter();
		int num=0;
		int *arry=new int[size];
		if(!isempty()){
			node<T>* tmp=head;
			while(tmp!=0){
				arry[num]=tmp->info;
				tmp=tmp->next;
				
				 
				num++;
			}
		}	
			cout<<"The items in array is :  "<<endl;
			for(int i=0;i<size;i++){
				cout<<arry[i]<<endl;
			}
		}
	
		void deleteevennumber(){
			if(!isempty()){
				
				node<T>* tmp=head;
				node<T>* tmp2;
				while(tmp!=0){
					if(tmp->info%2==0){
						tmp2=tmp;
						tmp=tmp->next;
						deletenode(tmp2->info);
					}
					else
					tmp=tmp->next;
				}
			
			}
			
		}
		void addoddnumber(){
			if(!isempty()){
				node<T>* tmp=head;
				node<T>* tmp2;
				T data;
				while(tmp!=0){
					if(tmp->info%2!=0){
						data=(tmp->info)*2;
						tmp2=new node<T>(data,tmp->next,tmp);
						tmp->next=tmp2;
						tmp->next->prev=tmp2;
					}
					tmp=tmp->next;
				}
				cout<<"Add seccesfully."<<endl;
			}
			else 
			cout<<"The node is empty."<<endl;
		}
	
};
