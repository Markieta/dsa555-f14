double power(double c,int n){
	double rc=1;
	for(i=0;i<n;i++){
		rc=rc*c;
	}
	return rc;
}
/*recursive power function with O(n) runtime*/
double powerToOn(double c,int n){
	double rc=1;
	if(n!=0){
		rc=c*powerToOn(c,n-1);
	}
	return rc;
}
double powerFaster(double c,int n){
	double rc=1;
	if(n!=0){
		int tmp=powerFaster(c,n/2);
		//if n is odd
		if(n%2==1){
			rc=tmp*tmp*c;
		}
		else{
			rc=tmp*tmp;
		}
	}
	return rc;
}