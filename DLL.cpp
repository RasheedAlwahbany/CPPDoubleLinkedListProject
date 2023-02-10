#include<iostream>
#include "DLL_Class.h"
using namespace std;
int main(){
	int choose,data,num;
	DLL<int> get;
	while(true){
	cout<<"Please choose the correct:\n1) Add to head. \n2) Add to tail.\n3) Add to middle.\n4) First item.\n5) Last item.\n6) Display.\n7) Search."<<endl;
	cout<<"8) Sum of item.\n9) Number of items.\n10) Average of items.\n11) The maxemum number.\n12) the minimum number.\n13) Convert to array.\n14) Delete from head.\n15) Delete from tail.\n16) Delete node.\n17) Clear node.\n18) Add in order.\n19) Delete even number."<<endl;
	cout<<"20) Add double odd number."<<endl;
	cin>>choose;
	if(choose==1){
		cout<<"Please enter the data :"<<endl;
		cin>>data;
	get.addtohead(data);
	}
	else if(choose==2){
		cout<<"Please enter the data :"<<endl;
		cin>>data;
		get.addtotail(data);
	}
	else if(choose==3){
		int item;
		cout<<"Please enter the data :"<<endl;
		cin>>data;
			cout<<"Enter the item you want to add after it :"<<endl;
			cin>>item;	
		get.addtomiddle(item,data);
	}
	else if(choose==4){
		get.First();
	}
	else if(choose==5){
		get.Last();
		
	}
	
	else if(choose==6){
		get.display();
	}
	else if(choose==7){
		cout<<"Please enter the search data in node :"<<endl;
		cin>>data;
		//get.search(data);
		if(get.search(data)){
			cout<<"The "<<data<<" item is not found."<<endl;	
		}	
		else
		cout<<"The Item which you are searching about it is found and is :  "<<data<<endl;

	}
	else if(choose==8){
		num=get.sum();
		if(num==0)
		{
		cout<<"The node is empty."<<endl;
		cout<<"The sum of items is :  "<<num<<endl;
		}
		else
		cout<<"The sum of items is :  "<<num<<endl;
		
	}
	else if(choose==9){
		num=get.counter();
		if(num==0)
			cout<<"The number of item in node is :  "<<num<<endl;
		else
		cout<<"The number of item in node is :  "<<num<<endl;
	}
	else if(choose==10){
		get.average();
	}
	else if(choose==11){
		get.maxnumber();
	}
	else if(choose==12){
		get.minnumber();
	}
	else if(choose==13){
		get.converttoarray();
	}
	else if(choose==14){
		get.deletefromhead();
	}
	else if(choose==15){
		get.deletefromtail();
	}
	
	else if(choose==16){
		cout<<"Please enter the node to delete it :"<<endl;
		cin>>data;
		get.deletenode(data);
	}
	else if(choose==17){
		
		get.clear();
	}
	else if(choose==18){
		cout<<"Please enter the data :"<<endl;
		cin>>data;
	get.addinorder(data); 
	}
	else if(choose==19){
		get.deleteevennumber() ;
	}
	else if(choose==20){
		get.addoddnumber();
	}
	
}
	system("pause");
	return 0;
}
