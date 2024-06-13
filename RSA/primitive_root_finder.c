#include<stdio.h>
#include<gmp.h>
mpz_t primitive_root_finder(mpz_t n)
{
    mpz_t count , i , temp ,j , rop ; 
    mpz_inits(count , i , temp  ,j , rop , NULL);
    mpz_set(i , n );
    mpz_set_ui(j , 0);
    mpz_t divisors_list[1000];

    while(mpz_cmp(i , n))
    {
        if(mpz_div_mod_m(rop , n , i ))
        mpz_init(divisors_list[j]);

        mpz_add_ui(j,j,1);
        mpz_add_ui(i , i , 1);
    }
}
