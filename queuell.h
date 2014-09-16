#include "slink.h"
template <class TYPE>
class QueueLL{
	SinglyLinked theQueue_;
public:
	QueueLL(){
	}
	void enqueue(const TYPE& value){
		theQueue_.insertAtBack(value);
	}
	void pop(){
		theQueue_.removeAtFront();
	}
	const TYPE& top() const{
		return theQueue_.front().data_;
	}
	boolean isEmpty() const{
		return theQueue_.front() == NULL;
	}
};