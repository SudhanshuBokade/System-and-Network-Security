#include <stdio.h>
#include <gmp.h>

void extended_gcd( mpz_t a,  mpz_t b, mpz_t d, mpz_t x, mpz_t y) {
    mpz_t x2, x1, y2, y1, q, r, temp_a, temp_b;
    mpz_inits(x2, x1, y2, y1, q, r, temp_a, temp_b, NULL);
    mpz_set_ui(x2, 1);  // x2 = 1
    mpz_set_ui(x1, 0);           // x1 = 0
    mpz_set_ui(y2, 0);           // y2 = 0
    mpz_set_ui(y1, 1);  // y1 = 1

    mpz_set(temp_a, a);
    mpz_set(temp_b, b);

    while (mpz_cmp_ui(temp_b, 0) > 0) {
        mpz_fdiv_q(q, temp_a, temp_b);  // q = floor(a/b)
        mpz_mod(r, temp_a, temp_b);     // r = a - qb

        mpz_set(temp_a, temp_b);     // a = b
        mpz_set(temp_b, r);             // b = r ;
        mpz_mul(q, q, x1);
        mpz_sub(x, x2, q);  // x = x2 - qx1
        mpz_mul(q, q, y1);
        mpz_sub(y, y2, q);  // y = y2 - qy1
        mpz_set(x2, x1);
        mpz_set(x1, x);
        mpz_set(y2, y1);
        mpz_set(y1, y);

    }

    mpz_set(d, temp_a);
    mpz_set(x, x2);
    mpz_set(y, y2);

    mpz_clears(x2, x1, y2, y1, q, r, temp_a, temp_b, NULL);
}

int main() {
    mpz_t a, b, d, x, y;
    mpz_inits(a, b, d, x, y, NULL);

    // Set values for a and b
    gmp_printf("Enter the value of a : ");
    gmp_scanf("%Zd" ,&a);
    gmp_printf("Enter the value of b : ");
    gmp_scanf("%Zd" , &b);
    // Calculate extended GCD
    extended_gcd(a, b, d, x, y);

    // Print the results
    gmp_printf("gcd(%Zd, %Zd) = %Zd\n", a, b, d);
    gmp_printf("x = %Zd, y = %Zd\n", x, y);

    // Clean up
    mpz_clears(a, b, d, x, y, NULL);

    return 0;
}
