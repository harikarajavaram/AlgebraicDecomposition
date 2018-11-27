#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "additive_share.c"

//naive way of implementing cprr
int* cprr(int shares[], int d){
	int x = decode(shares,d);
	int polyans =  (3 * x * x * x * x * x) - (2 * x * x) + (7 * x) - 6;
	int max = pow(2,N);
	polyans = polyans % max;
	printf("%d\n", polyans);
	int *a = share(polyans,d);
	return a;
}

int main(){
	int shares[3] = {1,7,5};
	int d = 3;
	int *ans = cprr(shares,d);
	printf("printing cprr result\n");
	for(int k=0;k<d;k++){
		printf("%d\n", ans[k]);
	}
}
