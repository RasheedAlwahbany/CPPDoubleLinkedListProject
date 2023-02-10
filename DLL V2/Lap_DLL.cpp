#include <iostream>
#include "Lap_DLL_Class.h"
using namespace std;
int main(){
	int choose,data,item;
	DLL<int> get;
	while(true){
	cout<<"Please choose from bellow.\n1) Add to head.\n2) Add to tail.\n3) Add to middle.\n4) dislpay.\n5) Delete from head.\n6) Delete from tail.\n7) Delete node.\n8) Display odd number."<<endl;
	cin>>choose;
	if(choose==1){
		cout<<"Enter data :"<<endl;
		cin>>data;
		get.addtohead(data);
	}
	else if(choose==2){
		cout<<"Enter the data :"<<endl;
		cin>>data;
		get.addtotail(data);
	}
	else if(choose==3){
		cout<<"Enter the data :"<<endl;
		cin>>data;
		cout<<"Enter the item to add after it :"<<endl;
		cin>>item;
		get.addtomiddle(item,data);
	}
	else if(choose==4){
		get.display();
	}
	else if(choose==5){
		get.deletefromhead();
	}
	else if(choose==6){
		get.deletefromtail();
	}
	else if(choose==7){
		cout<<"Entere the node to delete it :"<<endl;
		cin>>item;
		get.deletenode(item);
	}
	else if(choose==8){
		get.oddnumber();
	}
}
	system("pause");
	return 0;
}


