#include <stdio.h>
#include <gmp.h>

void primeFactorization(const mpz_t n) {
    mpz_t num;
    mpz_init_set(num, n);

    mpz_t divisor;
    mpz_init(divisor);
    mpz_set_ui(divisor, 2);  // Start with the smallest prime

    while (mpz_cmp_ui(num, 1) > 0) {
        mpz_t quotient, remainder;
        mpz_inits(quotient, remainder, NULL);

        mpz_tdiv_qr(quotient, remainder, num, divisor);

        if (mpz_cmp_ui(remainder, 0) == 0) {
            // divisor is a prime factor of num
            gmp_printf("%Zd ", divisor);
            mpz_set(num, quotient);
        } else {
            // Move to the next potential divisor
            mpz_add_ui(divisor, divisor, 1);
        }

        mpz_clears(quotient, remainder, NULL);
    }

    gmp_printf("\n");

    mpz_clears(num, divisor, NULL);
}

int main() {
    mpz_t number;
    mpz_init(number);
    gmp_printf("Enter the number  : ");
    gmp_scanf("%Zd" , number);

    printf("Prime factorization of ");
    mpz_out_str(stdout, 10, number);
    printf(" is: ");
    primeFactorization(number);

    mpz_clear(number);

    return 0;
}