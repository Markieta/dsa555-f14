#include "timer.h"
#include <iostream>
using namespace std;
int fibonacci(int n){

}
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