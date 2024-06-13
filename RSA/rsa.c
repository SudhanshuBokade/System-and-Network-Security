#include<stdio.h>
#include<gmp.h>
mpz_t getInput()
{
    char inputString[10000] ;
    scanf("%s" , inputString);
    mpz_t result;
    mpz_init(result);
    mpz_set_str(result , inputString , 36);
    gmp_printf("Concatenated number: %Zd\n", result);
    return result ;
}
int main()
{
    mpz_t p , q , n ,input , phi_n ; 
    mpz_inits(p ,q, n ,input ,phi_n , NULL);
    do{
        gmp_printf("Enter the p : ");
        gmp_scanf("%Zd" , p );
    }while(!mpz_probab_prime_p(p , 24));
    do{
        gmp_printf("Enter the q :");
        gmp_scanf("%Zd" , q);
    }while(!mpz_probab_prime_p(q, 24));
    mpz_mul(n , p , q);
    input = getInput(); 
    encrypt(input , p , q , n);

}