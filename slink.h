#include <iostream>
using namespace std;

template <class TYPE>
struct Node{
	TYPE data_;
	Node<TYPE>* next_;	
	Node(const TYPE& data,Node<TYPE>* n = NULL){
		data_=data;
		next_=n;
	}
};
template <class TYPE>
class SinglyLinked{
	Node<TYPE>* first_;
	Node<TYPE>* last_;
public:
	Node<TYPE>* first() const {return first_;}
	SinglyLinked(){
		first_=last_=NULL;
	}
	//insert a node with data at start of linked list
	//return address of this new node
	Node<TYPE>* insertAtFront(const TYPE& data);
	//insert a node with data at start of linked list
	//return address of this new node
	Node<TYPE>* insertAtBack(const TYPE& data);
	//remove a node at start of linked list
	void removeAtFront();

	//remove a node at start of linked list
	void removeAtBack();

	//prints the linked list assuming that the TYPE can
	//be output using standard << operator
	void print() const;
	~SinglyLinked(){

	}
};
/*this function has a constant run time.  Does not matter how
many nodes are in the linked list, this function has number
of operations regardless of size of list*/
template <class TYPE>
Node<TYPE>* SinglyLinked<TYPE>::insertAtFront(const TYPE& data){
	Node<TYPE>* nn=new Node<TYPE>(data,first_);
	if(first_==NULL){
		last_=nn;
	}
	first_=nn;
	return nn;
}

/*this function has a runtime of O(1) ...constant*/
template <class TYPE>
Node<TYPE>* SinglyLinked<TYPE>::insertAtBack(const TYPE& data){
	Node<TYPE>* nn=new Node<TYPE>(data);
	if(first_==NULL){
		first_=last_=nn;
	}
	else{
		last_->next_=nn;
		last_=nn;
	}
	return nn;

}
//remove a node at start of linked list
template <class TYPE>
void removeAtFront(){
	if(first_){
		Node<TYPE>* tmp=first_;
		first_=first_->next_;  //makes first_ point to second node
		delete tmp;
	}
}
//remove a node at start of linked list
template <class TYPE>
void removeAtBack(){
	if(first_){
		Node<TYPE>* curr=first_;
		Node<TYPE>* prev=NULL;
		while(curr->next_){
			prev=curr;
			curr=curr->next_;
		}
		if(prev!=NULL){
			prev->next_=NULL;
		}
		else{
			first_=NULL;
		}
		delete curr;
	}
}


template <class TYPE>
void SinglyLinked<TYPE>::print() const{
		Node<TYPE>* curr=first_;
		while(curr){
			cout << curr->data_ << endl;
			curr=curr->next_;
		}
}






