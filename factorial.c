#include<gmp.h>
#include<stdio.h>
int main()
{
    mpz_t num , facto ;
    mpz_inits(num ,facto ,NULL) ;
    unsigned long int u ;
    printf("Enter the number : ") ;
    gmp_scanf("%Zd" , num) ;

    u = mpz_get_ui(num) ; 
    gmp_printf("\nThe number entered is %lu", u );
    mpz_fac_ui(facto , mpz_get_ui(num)); 
    gmp_printf("\nThe factorial is :\n %Zd\n" , facto) ;
    return 0 ;
}