template <class TYPE>
class QueueArray{
	TYPE* array_;
	int capacity_;
	int front_;
	int back_;
	int numInQueue_;
public:
	QueueArray(int cap=100){
		front_=back_=numInQueue_=0;
		capacity_=cap;
		array_=new TYPE[cap];
	}
	void grow(){
		TYPE* newArray=new TYPE[capacity_+100];
		int f=front_;
		for(int i=0;i<numInQueue_;i++){
			newArray[i]=array_[f];
			f=(f+1)%capacity_;
		}
		capacity_=capacity_+100;
		front_=0;
		back_=numInQueue_;
		delete [] array_;
		array_=newArray;
	}
	void enqueue(const TYPE& value){
		if(numInQueue_ == capacity_){
			grow();
		}
		array_[back_]=value;
		back_=(back_==capacity_-1)?0:back_+1;
		//back_=(back_+1)%capacity_;
	}
	void dequeue(){
		if(numInQueue_!=0){
			front_=(front_+1)%capacity_;
		}
	}
	const TYPE& front() const{
		if(numInQueue_!=0){
			return array_[front_];
		}
	}
	boolean isEmpty() const{
		return numInQueue_==0;
	}
};