#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

unsigned int N = 8;

//choose d-1 shares randomly and compute dth share by taking xor of (d-1) shares with 
//original value x
unsigned int * share(unsigned int x, unsigned int d){
	unsigned int max = (unsigned int) pow(2,N);
	unsigned int* shares = malloc(sizeof(unsigned int) * d);
	unsigned int sum = 0;
//	unsigned int seed = time(NULL);
//	srand(seed);	
	for(unsigned int i=0;i<d-1;i++){
		unsigned int num = rand()%max;
		shares[i] = num;
		sum = sum ^ shares[i];
	}
	shares[d-1] = ((x ^ sum) % max);
	/*if(shares[d-1] < 0){
		shares[d-1] = shares[d-1] + max;
	}*/
	return shares;
}

//do xor of all shares to get back original value x
unsigned int decode(unsigned int shares[],unsigned int d){
	unsigned int original = shares[0];
	for(unsigned int i=1;i<d;i++){
		original = original ^ shares[i];
	}
	unsigned int max = (unsigned int) pow(2,N);
	return original % max;	
}

//main function to individually test 'share' and 'decode' functions
/*
int main(){
	unsigned int x = 7;
	unsigned int d = 4;
	unsigned int seed = time(NULL);
	srand(seed);
	unsigned int *a;
	a = share(x,d);
	printf("printing shares\n");
	for(unsigned int k=0;k<d;k++){
		printf("%d  ", a[k]);
	}
	printf("\n");
	unsigned int original = decode(a,d);
	printf("original value %d\n", original);
	return 0;
}
*/
