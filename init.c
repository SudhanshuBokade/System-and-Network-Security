#include<gmp.h>
#include<stdio.h>
int main()
{
    mpq_t x;
    mpq_init(x); 
    gmp_printf("HEllo world , the default value of x is : %Zd\n" , x); 
    return 0 ;
}