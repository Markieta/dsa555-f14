#include "polynomial.h"
#include "fraction.h"
#include <iostream>
using namespace std;
PolyNode::PolyNode(const Fraction& coefficient, int degree, PolyNode* next){
	coefficient_=coefficient;
	degree_=degree;
	next_=next;
}
Polynomial::Polynomial(){

}
Polynomial::Polynomial(int data[][3],int numTerms){

}
Polynomial::Polynomial(const Polynomial& poly){

}
const Polynomial& Polynomial::operator=(const Polynomial& poly){

}
Polynomial::~Polynomial(){

}
void Polynomial::addTerm(const Fraction& coefficient, int degree){

}
Fraction Polynomial::solve(const Fraction& x){

}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2){

}
Polynomial operator-(const Polynomial& p1, const Polynomial& p2){

}
Polynomial operator*(const Polynomial& p1, const Polynomial& p2){

}
Polynomial operator/(const Polynomial& p1, const Polynomial& p2){

}
Polynomial operator%(const Polynomial& p1, const Polynomial& p2){

}
ostream& operator<<(ostream& os, const Polynomial& dat){
	
}