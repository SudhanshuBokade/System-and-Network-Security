#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>


void crt(mpz_t result,mpz_t* a ,  mpz_t *b, mpz_t *m, int n) {      // b = a mod m
    mpz_t M, x, y, temp ,rop , invt_num;
    mpz_inits(M, x, y, temp, rop  , invt_num , NULL);
    mpz_set_ui(result, 0);
    mpz_set_ui(M, 1);
    mpz_t gcd ;
    mpz_init(gcd);
    for (int i = 0; i < n; i++) {
         if(mpz_divisible_p( b[i], a[i]) != 0 )
        {
            mpz_divexact(b[i] , b[i] ,a[i]);
            mpz_gcd(gcd , a[i] , m[i]);
            mpz_divexact(m[i] ,m[i] , gcd);
            mpz_set_ui(a[i] , 1);
        }
        else
        {
            mpz_gcd(gcd , a[i] ,b[i]);
            mpz_divexact(a[i] , a[i] ,gcd);
            mpz_divexact(b[i] , b[i] , gcd);
            mpz_gcd(gcd , gcd , m[i]);
            mpz_divexact(m[i] , m[i] , gcd);
            mpz_invert(invt_num, a[i] , m[i]);
            mpz_mul(b[i] , b[i] , invt_num);
            mpz_mod(b[i] , b[i] , m[i]);
            mpz_set_ui(a[i] ,1) ;
            if(invt_num == 0)
            {
                printf("No solutions possible");
                return ;
            }
        }
        mpz_mul(M , M , m[i]);
    }

    for (int i = 0; i < n; i++) {
       
        mpz_divexact(temp, M, m[i]);
        mpz_invert(rop , temp , m[i]);      // if some common multiple exists then rop will be zero
        mpz_mul(temp , temp , rop);
        mpz_mul(temp , temp , b[i]);
        mpz_add(result, result, temp);
    }
    mpz_powm_ui(result , result , 1 , M);


    mpz_clears(M, x, y, temp, NULL);
}


int main(int argc, char *argv[]) {
    if (argc < 2 || (argc - 2) % 3 != 0) {
        printf("Usage: %s n a1 b1 m1 a2 b2 m2 ...\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    mpz_t *a = malloc(n * sizeof(mpz_t));
    mpz_t *b = malloc(n * sizeof(mpz_t));
    mpz_t *m = malloc(n * sizeof(mpz_t));

    for (int i = 0; i < n; i++) {
        mpz_inits(a[i], b[i], m[i], NULL);
        mpz_set_str(a[i], argv[i * 3 + 2], 10);
        mpz_set_str(b[i], argv[i * 3 + 3], 10);
        mpz_set_str(m[i], argv[i * 3 + 4], 10);
    }

    mpz_t x;
    mpz_init(x);

    crt(x , a , b, m , n);

    gmp_printf("Common solution x: %Zd\n", x);

    for (int i = 0; i < n; i++) {
        mpz_clears(a[i], b[i], m[i], NULL);
    }

    mpz_clear(x);

    free(a);
    free(b);
    free(m);

    return 0;
}