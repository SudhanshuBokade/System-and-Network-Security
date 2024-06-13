#include<stdio.h>
#include<gmp.h>
int main()
{
    mpz_t a , m  , gcd ,s ,t; 
    mpz_inits(a , m , gcd ,s ,t , NULL);
    printf("Enter the value of a : ");
    gmp_scanf("%Zd", a);
    printf("enter the value of m : ");
    gmp_scanf("%Zd" , m) ;
    mpz_gcd(gcd , a ,m);
    if(mpz_cmp_ui(gcd , 1 ) != 0)
    {
        gmp_printf("No inverse exists for %Zd mod %Zd" , a , m );
    }
    else
    {
        mpz_gcdext(gcd , s ,t , a ,m);
        gmp_printf("the multiplicative inverse of %Zd mod %Zd is %Zd " , a , m ,t );
    }
}