#include<gmp.h>
#include<stdio.h>
void product_of_primes(mpz num)
{
    int i  = 2 ; 
    while(num != 1)
    {
        if()
        num = num/i ;
    }
}
int main()
{
    
    mpz_t num ; 
    gmp_printf("Enter the number ");
    mpz_init(num);
    gmp_scanf("%Zd" , &num);
    product_of_primes(num);
}