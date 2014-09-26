#include <cstdlib>
#include <iostream>
using namespace std;
int GCDR(int a,int b);

int GCD(int a, int b){
	a=(a < 0)?-a:a;  //absolute value
	b=(b< 0)?-b:b;
	if(a < b){
		return GCDR(a,b);
	}
	else{
		return GCDR(b,a);
	}
}
int GCDR(int a,int b){
	if(a==0){
		return b;
	}
	else if(b==0){
		return a;
	}
	else{
		return GCDR(b,a%b);
	}

}

int main(int argc,char* argv[]){
	int x=atoi(argv[1]);
	int y=atoi (argv[2]);
	int z=GCD(x,y);
	cout << "gcd( " << x << "," << y << ") = " << z << endl;
	return 0;
}