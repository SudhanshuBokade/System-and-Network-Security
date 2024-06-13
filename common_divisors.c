#include <stdio.h>
#include<stdlib.h>
#include<gmp.h>
void get_common_divisors(mpz_t inputNumbers[] , int n)
{
    mpz_t gcd_result;
    mpz_init(gcd_result);
    mpz_set(gcd_result , inputNumbers[0]);
    gmp_printf("Common divisors are : ");
    for(int i = 1 ; i < n ; i ++)
    {
      
        mpz_gcd(gcd_result , gcd_result , inputNumbers[i]) ;
    }
   
    for(int i = 1 ; i <= mpz_get_ui(gcd_result) ; i ++)
    {
        if ( mpz_divisible_ui_p(gcd_result , i))
        {

            gmp_printf("%d " ,i ) ;
        }
    }
}
int main()
{
    int n = 0 ; 
    printf("How many you want ot enter :");
    scanf("%d" ,&n) ;
    mpz_t inputNumbers [n+1];
    for(int i = 0 ; i < n ; i ++)
    {
        mpz_init(inputNumbers[i]);
        gmp_scanf("%Zd" , &inputNumbers[i]) ;
    }
    get_common_divisors(inputNumbers , n) ;
    for(int i = 0 ; i < n; i ++)
    {
        mpz_clear(inputNumbers[i]);
    }

}