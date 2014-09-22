#include "fraction.h"
#include <iostream>
using namespace std;

int GCD(int a,int b){
	int rc;
	a=(a>0)?a:-a;
	b=(b>0)?b:-b;
	if(a < b){
		int tmp=a;
		a=b;
		b=tmp;
	}
	if(b == 0){
		rc=a;
	}
	else{
		rc=GCD(b,a%b);
	}
	return rc;
}
Fraction::Fraction(){
	numerator_=0;
	denominator_=1;
}
Fraction::Fraction(int num,int denom){
	set(num,denom);
}
void Fraction::set(int num,int denom){
	numerator_=num;
	denominator_=denom;
	reduce();
}
void Fraction::reduce(){
	int divisor=GCD(numerator_,denominator_);
	numerator_=numerator_/divisor;
	denominator_=denominator_/divisor;
	if((numerator_ < 0 && denominator_ < 0) || 
		(numerator_ > 0 && denominator_ < 0)){
		numerator_=numerator_*-1;
		denominator_=denominator_*-1;
	}
}

Fraction operator+(const Fraction& f1, const Fraction& f2){
	return Fraction(f1.numerator_*f2.denominator_+f2.numerator_*f1.denominator_, f1.denominator_*f2.denominator_);
	
}
Fraction operator-(const Fraction& f1, const Fraction& f2){
	return Fraction(f1.numerator_*f2.denominator_-f2.numerator_*f1.denominator_, f1.denominator_*f2.denominator_);

}
Fraction operator*(const Fraction& f1, const Fraction& f2){
	return Fraction(f1.numerator_*f2.numerator_, f1.denominator_*f2.denominator_);
}
Fraction operator/(const Fraction& f1, const Fraction& f2){
	return Fraction(f1.numerator_*f2.denominator_, f1.denominator_*f2.numerator_);
}
ostream& operator << (ostream& os, const Fraction& data){
	if(data.numerator_ < data.denominator_){
		if(data.numerator_!=0){
			os << data.numerator_ << "/"  << data.denominator_;
		}
		else{
			os << "0";
		}
	}
	else{
		os << data.numerator_/data.denominator_;
		if(data.numerator_ % data.denominator_){
			os << " " << data.numerator_%data.denominator_ << "/";
			os << data.denominator_;
		}
	}
	return os;
}

const Fraction& Fraction::operator+=(const Fraction& rhs){
	*this=*this+rhs;
	return *this;
}
const Fraction& Fraction::operator-=(const Fraction& rhs){
	*this=*this-rhs;
	return *this;
}
const Fraction& Fraction::operator*=(const Fraction& rhs){
	*this = *this * rhs;
	return *this;
}
const Fraction& Fraction::operator/=(const Fraction& rhs){
	*this = *this / rhs;
	return *this;
}
