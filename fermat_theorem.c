#include <stdio.h>
#include <gmp.h>

void calculate_power_mod(mpz_t a, mpz_t x, mpz_t n, mpz_t result) {
    mpz_t b, A;
    mpz_init(b);
    mpz_init(A);
    
    // Step 1
    mpz_set_ui(b, 1);
    if (mpz_cmp_ui(x, 0) == 0) {
        gmp_printf("as x is 0 so b = %Zd\n" , b);
        mpz_set(result, b);
        return;
    }
    
    // Step 2
    mpz_set(A, a);
    
    // Step 3
    if (mpz_tstbit(x, 0) == 1) {
        mpz_set(b, a);
        gmp_printf("as 0th bit of x is set so b = %Zd\n" ,b);
    }
    
    // Step 4
    for (unsigned long i = 1; i <= mpz_sizeinbase(x, 2); i++) {
        // Step 4.1
        mpz_mul(A, A, A);
        gmp_printf("A X A = %Zd \n" , A);
        mpz_mod(A, A, n);
        gmp_printf("After A mod %Zd = %Zd \n" ,n , A);
        mpz_t temp1 ,temp2 ;
        mpz_inits(temp1 ,temp2, NULL);
        // Step 4.2
        mpz_set(temp1 , b);
        if (mpz_tstbit(x, i) == 1) {
            mpz_mul(b, b, A);
            mpz_mod(b, b, n);
            gmp_printf("%Zd = (%Zd x %Zd )mod %Zd \n" , b , temp1 , A , n);
        }
        mpz_clear(temp1);
        mpz_clear(temp2);
    }
    
    // Step 5
    mpz_set(result, b);
    
    // Clean up
    mpz_clear(b);
    mpz_clear(A);
}

int main() {
    mpz_t a, x, n, result;
    mpz_inits(a, x, n, result, NULL);
    printf("Enter the a : ");
    gmp_scanf("%Zd" , &a);
    gmp_printf("Enter the x : ");
    gmp_scanf("%Zd" , &x);
     gmp_printf("Enter the n : ");
    gmp_scanf("%Zd" , &n);


    
    // Calculate a^x (mod n)
    calculate_power_mod(a, x, n, result);
    
    // Print the final result
    gmp_printf("Result: %Zd\n", result);
    
    // Clean up
    mpz_clears(a, x, n, result, NULL);
    
    return 0;
}
