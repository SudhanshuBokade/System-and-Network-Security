#include<gmp.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    mpz_t t ; 
    mpz_init(t);
    mpz_set_str(t , "HELLOIAMBOY",36);
    gmp_printf("%Zd", t);
    char* str = (char *)malloc(sizeof(char)*1000);
    mpz_get_str(str , 36 , t);
    gmp_printf("%s", str);
    mpz_clear(t);
}