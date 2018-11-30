/*
Author : Rajavaram Harika
Email ID : harika.rajavaram@gmail.com
Contents : Code to evaluate the sbox and also test it with sbox from sage code3
*/

#include "sbox.c"

//prints both sboxes got from code and from the actual sbox array
int test(int x, int d){
	unsigned int *shares = share(x,d);
	//calling sbox on shares of x
	unsigned int *ans = sbox(shares,d);
	max = (int) pow(2,N);
	printf("printing sbox shares\n");
	for(unsigned int f=0;f<d;f++){
		printf("%d ", ans[f]);
	}
	printf("\n");
	// decoding the shares got from sbox evaluation
	unsigned int sbox_code = decode(ans,d);
	printf("sbox evaluation by program is %d\n",sbox_code);
	printf("sbox from sage code is %d\n", s[x]);
}

int main(){
	int x = 100;
	int d = 4;
	test(x,d);
}