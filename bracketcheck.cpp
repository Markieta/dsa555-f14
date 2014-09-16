
#include "stackarray.h"
//returns true if the brackets in s match, false otherwise
boolean checkBrackets(const char* s){
	StackArray<char> theStack;
	int i;
	boolean rc=true;
	for(i=0;rc && s[i]!='\0';i++){
		switch(s[i]){
			case '{': theStack.push(s[i]); break;
			case '(': theStack.push(s[i]); break;
			case '[': theStack.push(s[i]); break;
			case '}':
				if(!theStack.isEmpty()){
					if(theStack.top() != '{'){
						rc=false;
					}
					else{
						theStack.pop();
					}
				}
				else{
					rc=false;
				}
			case ']':
				if(!theStack.isEmpty()){
					if(theStack.top() != '['){
						rc=false;
					}
					else{
						theStack.pop();
					}
				}
				else{
					rc=false;
				}
			case ')':
				if(!theStack.isEmpty()){
					if(theStack.top() != '('){
						rc=false;
					}
					else{
						theStack.pop();
					}
				}
				else{
					rc=false;
				}
		};	
	}
	if(rc){
		rc=theStack.isEmpty();
	}
	return rc;
}
