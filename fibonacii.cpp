#include "timer.h"
#include <iostream>
using namespace std;

int fibonacci(int n){
  int rc;
  if(n==0){
    rc=0;
  }
  else if(n==1){
    rc=1;
  }
  else{
    rc=fibonacci(n-1)+fibonacci(n-2);
  }
  return rc;
}
/*
void fibPrevious(int n, int& prev,int& prevprev);
int fibonacci(int n){
  int rc;
  if(n==0){
    rc=0;
  }
  else if(n==1){
    rc=1;
  }
  else{
    int prevprev;     //holds fib(n-2);
    int prev;         //holds fib(n-1)
    fibPrevious(n,prev,prevprev);
    rc=prev+prevprev;
  }
  return rc;
}
//this function calculates the fib(n-1) and fib(n-2)
//and passes that back through the parameters
//fibn_1 and fibn_2 
void fibPrevious(int n, int& fibn_1,int& fibn_2){
   if(n == 2){
      fibn_1=1;
      fibn_2=0;
   }
   else{
      int p;
      int pp;
      //p will have fib(n-2) and pp will have fib(n-3);
      fibPrevious(n-1,p,pp);
      fibn_1=p+pp;
      fibn_2=p;
   }
}
*/
//iterative
int fib(int n){
  int rc;
  if(n==0)
    rc=0;
  else if(n == 1)
    rc=1;
  else{
    int prev=1;
    int prevprev=0;
    for(int  i=2;i<=n;i++){
      rc=prev + prevprev;
      prevprev=prev;
      prev=rc;
    }
  }
  return rc;
}


int main(int argc, char* argv[]){
  int v=atoi(argv[1]);
  Timer T1, T2;
  int a, b;
  T1.start();
  a=fib(v);
  T1.stop();
  cout << "iterative fib(" << v << ") = " << a << endl;
  cout << "result took "<< T1.currtime() << " seconds to find" << endl;

  T2.start();
  b=fibonacci(v);
  T2.stop();
  cout << "recursive fibonacci(" << v << ") = " << b << endl;
  cout << "result took "<< T2.currtime() << " seconds to find" << endl;
}