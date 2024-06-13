#include<gmp.h>
#include<stdio.h>
int main()
{
    mpz_t m , n ; 
    mpz_init(m) ; 
    mpz_init(n) ;
    printf("Enter the first unmber");
    gmp_scanf("%Zd" , m );
    printf("Enter the second number ");
    gmp_scanf("%Zd" ,n) ; 
    mpz_mul(m ,m ,n) ;
    gmp_printf("The value of m is %Zd and value n is %Zd" , m , n); 
    return 0 ;
}