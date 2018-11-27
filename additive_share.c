#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int N = 3;
//choose d-1 shares randomly and compute dth share by subracting the sum of d-1 
//shares from orignal x and take mod
int * share(int x, int d){
	int max = (int) pow(2,N);
	int* shares = malloc(sizeof(int) * d);
	int sum = 0;
	for(int i=0;i<d-1;i++){
		int num = rand()%max;
		shares[i] = num;
		sum = sum + shares[i];
	}
	shares[d-1] = ((x - (sum)) % max);
	if(shares[d-1] < 0){
		shares[d-1] = shares[d-1] + max;
	}
	return shares;
}

//add all shares and take mod to get original x
int decode(int shares[],int d){
	int original = shares[0];
	for(int i=1;i<d;i++){
		original = original + shares[i];
	}
	int max = (int) pow(2,N);
	return original % max;	
}
/*
int main(){
	int x = 7;
	int d = 4;
	int seed = time(NULL);
	srand(seed);
	int *a;
	a = share(x,d);
	printf("printing shares\n");
	for(int k=0;k<d;k++){
		printf("%d  ", a[k]);
	}
	printf("\n");
	int original = decode(a,d);
	printf("original value %d\n", original);
	return 0;
}

*/