#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "additive_share.c"

//function that evalutes polynomial 
unsigned int function(unsigned int x)
{
    unsigned int polynomial = 5*pow(x,2);
    return polynomial; 
}

//naive implementation of cprr
unsigned int* cprr(unsigned int shares[], unsigned int d, unsigned int (* f)(unsigned int)){
	unsigned int x = decode(shares,d);
	unsigned int polyans =  (*f)(x);
	unsigned int max = pow(2,N);
	polyans = polyans % max;
	//prunsigned intf("%d\n", polyans);
	unsigned int *a = share(polyans,d);
	return a;
}

//main function to individually test 'cprr' function

unsigned int main(){
	unsigned int shares[3] = {1,7,5};
	unsigned int d = 3;
	unsigned int *ans = cprr(shares,d,function);
	printf("printing cprr result\n");
	for(unsigned int k=0;k<d;k++){
		printf("%d\n", shares[k]);
	}
}



