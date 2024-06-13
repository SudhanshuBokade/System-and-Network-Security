#include<stdio.h>
#include<gmp.h>
void main()
{
    mpz_t a , b , m , gcd , invt;
    mpz_inits(a ,b ,m ,gcd ,invt ,NULL);
    gmp_printf("Enter a : ");
    gmp_scanf("%Zd" , a);
    gmp_printf("Enter b : ");
    gmp_scanf("%Zd" , b);
    gmp_printf("Enter m :");
    gmp_scanf("%Zd" , m);
    mpz_gcd(gcd , a ,m );
    if(mpz_cmp_ui(gcd , 1) == 0)
    {
        mpz_invert(invt , a ,m );
    }
    else if (mpz_divisible_p(b , a) != 0)
    {
        mpz_cdiv_q(a , a ,gcd);
        mpz_cdiv_q(b ,b ,gcd);
        mpz_cdiv_q(m , m , gcd);
        mpz_invert(invt , a , m);
        
    }
    else
    {
        printf("Since a and m are not coprime and a does not divide b  , no solution exists \n");
        return ;
    }
    mpz_mul(b , b , invt);
    gmp_printf("smallest positive solution is %Zd  then %Zd + t x %Zd ..." , b ,b , m);


}