#include "fraction.h"
#include "polynomial.h"
#include <iostream>
using namespace std;
int main(void){
	int data[4][3]={{3,4,5},
					{7,3,4},
					{3,8,2},
					{9,1,0}};
	Polynomial p1;
	Polynomial p2(data,4);
	Polynomial p3 = p2;
	cout << p1 << endl;
	cout << p2 << endl;

	p1=p3;
	cout << p1 << endl;
	cout << p3 << endl;
	int data1[5][3]{
		//init using data from addition in
		//appendix for +
	}
	int data2[5][3]{
		//init using data from addition in
		//appendix for +
	}

	Polynomial p5 (data1,5);
	Polynomial p6 (data2, 5);
	Polynomial p7=p5+p6;
	cout << p7;

}