#include <iostream>
using namespace std;

template <class TYPE>
struct Node{
	TYPE data_;
	Node<TYPE>* next_;
	Node<TYPE>* prev_;	
	Node(const TYPE& data,Node<TYPE>* n = NULL, Node<TYPE>* p=NULL){
		data_=data;
		next_=n;
		prev_=p;
	}
};
template <class TYPE>
class DoublyLinked{
	Node<TYPE>* first_;
	Node<TYPE>* last_;
public:
	Node<TYPE>* first() const {return first_;}
	DoublyLinked(){
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
	~DoublyLinked(){

	}
};
/*this function has a constant run time.  Does not matter how
many nodes are in the linked list, this function has number
of operations regardless of size of list*/
template <class TYPE>
Node<TYPE>* DoublyLinked<TYPE>::insertAtFront(const TYPE& data){
	Node<TYPE>* nn=new Node<TYPE>(data,first_);
	if(first_){
		first_->prev_=nn;
	}
	else{
		last_=nn;
	}
	first_=nn;

	return nn;
}

/*this function has a runtime of O(1) ...constant*/
template <class TYPE>
Node<TYPE>* DoublyLinked<TYPE>::insertAtBack(const TYPE& data){
	Node<TYPE>* nn=new Node<TYPE>(data,NULL,last_);
	//at least one node in list
	if(last_){
		last_->next_=nn;
		last_=nn;
	}
	else{
		first_=nn;
		last_=nn;
	}

	return nn;

}
//remove a node at start of linked list
template <class TYPE>
void DoublyLinked<TYPE>::removeAtFront(){
	if(first_){
		Node<TYPE>* tmp=first_;
		if(first_ != last_){
			//this if is true only if there are at least two nodes
			first_=first_->next_;  //makes first_ point to second node
			first_->prev_=NULL;
		}
		else{
			//this else is true only if there is just one node
			first_=last_=NULL;
		}
		delete tmp;

	}
}
//remove a node at start of linked list
template <class TYPE>
void DoublyLinked<TYPE>::removeAtBack(){
	if(first_){
		Node<TYPE>* curr=last_;
		Node<TYPE>* prev=last_->prev_;

		//if prev is NULL, then there is only one node in list
		if(prev!=NULL){
			prev->next_=NULL;
			last_=prev;
		}
		else{
			last_=NULL;
			first_=NULL;
		}
		delete curr;
	}
}


template <class TYPE>
void DoublyLinked<TYPE>::print() const{
		Node<TYPE>* curr=first_;
		while(curr){
			cout << curr->data_ << endl;
			curr=curr->next_;
		}
}

template<class TYPE>
Node<TYPE>* DoublyLinked::search(const TYPE& key){
	Node<TYPE>* curr=first_;
	Node<TYPE>* rc=NULL;
	while(rc == NULL && curr){
		if(curr->data_==key){
			rc=curr;
		}
		curr=curr->next_;
	}
	return rc;
}




