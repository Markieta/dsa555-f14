#include "dlink.h"
#include <iostream>
using namespace std;
int main(void){
	DoublyLinked<int> list;
	for(int i=0;i<5;i++){
		list.insertAtFront(i);
	}
	for(int i=0;i<5;i++){
		list.insertAtBack(i+1);
	}
	list.print();
	for(int i=0;i<10;i++){
		cout << "**************************" << endl;
		if(i%2==0){
			list.removeAtFront();
		}
		else{
			list.removeAtBack();
		}
		list.print();
	}

	return 0;
}