# Algebraic Decomposition Method

This project is the implementation of algebraic decomposition method. Algebraic decomposition provides an efficient implementation of polynomial methods for s-boxes based on CPRR scheme. 

## Workflow (Input - Output)

The input to compute the sbox would an integer value x and another integer d which denotes the number of shares the x value should be split into. Then, 'share' function from share.c is called to split the x value into shares. The shares and the value d is given as input to the 'sbox' function and this function is called. The output of 'sbox' function would be the value of sbox in shared format. 

To test if the above 'sbox' function is giving the correct value, decode the shared values into a single integer and let it be sbox1. Now, access the value at xth index of 's' array in evaluate.c and let it be sbox2. Both the values sbox1 and sbox2 should be the same. This process is being done in test.c

Internally, p_i, q_i, g_i polynomials are being evaluated using CPRR and l_0, l_ij, l_i0 are linearised polynomials whose values are pre-computed and are stored as arrays. 

This method is efficient in computing the sbox as it is pre-computing the values of linearised polynomials. To get their value, the program has to just make a table look-up (which takes very less time). This implementation is also supposed to use CPRR scheme for secure multiplications and quadractic evaluations. 

## To Run

The test.c file calls the sbox function, computes the sbox value and also compares it to the actual s-box values. 
1. gcc -o test test.c -lm
2. ./test


## Limitations

1. This code uses a naive implmentation of CPRR and is not integrated with the actual CPRR method. 
2. It is assumed that the equations of polynomials p_i, q_i, l_0, l_i0, l_ij, f_i are given. 
3. After every composition of functions, we have to divide the obtained equation by the irreducible polynomial of the field over which the polynomials are defined. Currently, that division by irreducible polynomial is not being done.

## References

[How Fast Can Higher-Order Masking Be in Software?](https://eprint.iacr.org/2016/264.pdf)

