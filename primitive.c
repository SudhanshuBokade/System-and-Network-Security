#include<stdio.h>
#include<gmp.h>
void primitive_root(mpz_t p , mpz_t g)
{
    mpz_t q , r , chk1 , chk2 ,chk3 ;
    gmp_printf("Key generation  phase ...\n ");
    mpz_t l  ,m ; 
    unsigned long seed ; 
    mpz_inits(l , q ,r , m,chk1 , chk2 , chk3 ,  NULL);
    mpz_ui_pow_ui(l ,2, 199);
    mpz_ui_pow_ui(m ,2, 120);
    gmp_randstate_t rstate ; 
    gmp_randinit_mt(rstate);
    gmp_randseed_ui(rstate , seed);
    do{
        mpz_urandomb(q , rstate ,210);
        mpz_add(q , q, l);
        mpz_mul_ui(p ,q ,2);
        mpz_add_ui(p , p, 1);
    }while(!(mpz_probab_prime_p(p,24)));
    printf("q , p done \n");
    do{
        mpz_urandomb(r, rstate ,210);
        mpz_add(r , r, m);
        mpz_mod(chk1 , r , p);
        mpz_powm_ui(chk2 , r , 2 , p );
        mpz_powm(chk3 , r , q , p);
        gmp_printf("Hello\n");
    }while(!mpz_cmp_ui(chk1 , 1) && !mpz_cmp_ui(chk2 , 1) && !mpz_cmp_ui(chk3 , 1));
    mpz_set(g , r);
    gmp_printf("r = %Zd", r);
    mpz_clears(l , q , r ,chk1 , chk2 ,chk3 , m , NULL);
}
