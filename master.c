////////////////////////////////////////////////////////////////////////////////
//
//  File           : master.c
//  Description    : For Factorization and Primality testing programs
//
//   Author        : Joshua Zapusek
//   Last Modified : 9/13/2021

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

////////////////////////////////////////////////////////////////////////////////
//
// Function     : myGCD
// Description  : Calculate the gcd of two integers  
//
// Inputs       : a: intger 1
//                b: interger 2
//                step: number of recurse calls 
// Outputs      : gcd if success, -1 if failure
int myGCD(int a, int b, int *step) {
    // No negative numbers here
    if (a < 0 || b < 0) {
        return -1;
    }
    // Base case
    if (b == 0) {
        return a;
    }
    // Increase counter variable
    *step = *step + 1;
    return myGCD(b, a % b, step);
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : myGCD
// Description  : Calculate the gcd of two long long integers  
//
// Inputs       : a: intger 1
//                b: interger 2
//                step: number of recurse calls 
// Outputs      : gcd if success, -1 if failure
long long int myBigGCD(long long int a, long long int b, int *step) {
    // No negative numbers here
    if (a < 0 || b < 0) {
        return -1;
    }
    // Base case
    if (b == 0) {
        return a;
    }
    // Increase counter variable
    *step = *step + 1;
    return myBigGCD(b, a % b, step);
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : extendEuclid
// Description  : Calculate the gcd of two integers and their m & n 
//
// Inputs       : a: intger 1
//                b: interger 2
// Outputs      : array with gcd, m, n 
int * extendEuclid(int a, int b) {
    // Vars 
    // The return array with {gcd, m, n}
    static int arr[3];
    // These (s,t) are for iteratively calculating the coefficients on a, b (final result is m, n)
    // Check here: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
    int s_prev = 1;
    int s = 0;
    int t_prev = 0;
    int t = 1;
    // Quotient of a % b
    int q = 0;
    int temp, temp_t, temp_s;
    // Main iterative
    while (b != 0) {
        q = a / b;
        temp = b;
        b = a % b;
        a = temp;
        // m & n
        temp_s = s;
        temp_t = t; 
        t = t_prev - q * t;
        s = s_prev - q * s;
        s_prev = temp_s;
        t_prev = temp_t;
    }
    arr[0] = a;
    arr[1] = s_prev;
    arr[2] = t_prev;
    return arr;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for calling all homework assignments 
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure
int main(int argc, char *argv[]) {
    // Assign 1: Compute GCD
    int step = 0;
    int a = 5287;
    int b = 3927;
    //long long int long_a = 6277405925706921604898713904836;
    //long long int long_b = 33905302297439148131685112836424;
    int euclid = myGCD(a, b, &step);
    printf("The GCD of %d and %d is %d with %d number of recurse calls\n", a, b, euclid, step);
    step = 0;
    //long long big_euclid = myBigGCD(long_a, long_b, &step);
    //printf("The GCD of %lli and %lli is %lli with %d number of recurse calls\n", long_a, long_b, big_euclid, step);

    // Assign 2: Compute the Extended Euclidean Algorithm 
    a = 5287;
    b = 3927;
    int *p;
    p = extendEuclid(a, b);
    printf("GCD = %d, m = %d, n = %d\n", *(p + 0), *(p + 1), *(p + 2));
}
