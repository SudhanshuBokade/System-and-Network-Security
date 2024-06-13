#include <stdio.h>
#include <gmp.h>
void primitive(mpz_t n)
{
    mpz_t temp;
    mpz_init(temp);
    int count = 0 ;
    printf("List is as follows : \n");
    for(mpz_set_ui(temp , 1) ; mpz_cmp(temp , n) < 0 ;mpz_add_ui(temp , temp ,1))
    {
        mpz_t rop ; 
        mpz_init(rop);
        mpz_gcd(rop , temp , n) ; 
        if(mpz_cmp_ui(rop , 1 ) == 0)
        {
            gmp_printf("%Zd " , temp);
            count ++ ;
        }

    }
    printf("Total count of  RRSM  is %d ", count);
}
int main()
{
    mpz_t n ; 
    mpz_init(n);
    gmp_printf("Enter the number :");
    gmp_scanf("%Zd" , n) ;
    primitive(n) ;
}