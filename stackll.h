#include "slink.h"
template <class TYPE>
class StackLL{
	SinglyLinked theStack_;
public:
	StackLL(){
	}
	void push(const TYPE& value){
		theStack_.insertAtFront(value);
	}
	void pop(){
		theStack_.removeAtFront();
	}
	const TYPE& top() const{
		return theStack_.front().data_;
	}
	boolean isEmpty() const{
		return theStack_.front() == NULL;
	}
};