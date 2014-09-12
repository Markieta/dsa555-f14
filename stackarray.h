template <class TYPE>
class StackArray{
	TYPE* array_;
	int capacity_;
	int top_;
public:
	StackArray(int cap=100){
		top_=0;
		capacity_=cap;
		array_=new TYPE[cap];
	}
	void grow(){
		TYPE* newArray=new TYPE[capacity_+100];
		for(int i=0;i<capacity_;i++){
			newArray[i]=array_[i];
		}
		capacity_=capacity_+100;
		delete [] array_;
		array_=newArray;
	}
	void push(const TYPE& value){
		if(top_ == capacity_){
			grow();
		}
		array_[top_]=value;
		top_++;
	}
	void pop(){
		if(top_!=0){
			top_--;
		}
	}
	const TYPE& top() const{
		if(top_!=0){
			return array_[top_-1];
		}
	}
	boolean isEmpty() const{
		return top_==0;
	}
};