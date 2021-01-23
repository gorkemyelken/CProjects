#include <stdio.h>


double cubeRoot(double n) {
	double i, precision = 0.000001;
	
	// integer part
	
	for(i = 1; (i*i*i) <= n; ++i);         

	// fractional part
	
	for(--i; (i*i*i) < n; i += precision);  
   
	return i;
}

	// main function
	
int main() {
	
	printf("***** Cube Root Finder Program *****\n");
	int n;
	printf("Enter the number : ");
	scanf("%d",&n);
	
	if(n >= 0)
		printf("Cube root of %d = %lf", n, cubeRoot(n));
	else{
		n = -n;
		printf("Cube root of -%d = -%lf", n, cubeRoot(n));
	}
	

	return 0;
}


