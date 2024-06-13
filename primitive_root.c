#include<stdio.h>
#include<gmp.h>
#include<stdlib.h>
void primitive(mpz_t n)
{
    int i = 2 ; 
    mpz_t ncopy ; 
    mpz_init(ncopy);
    mpz_t arr[100] ;
    mpz_t supp[100];
    for(int i = 0 ; i < 100 ; i ++)
    {
        mpz_init(arr[i]);
        mpz_init(supp[i]);
        mpz_set_ui(arr[i] , 0 ) ;
    }
    mpz_set(ncopy , n) ;
    int k = 0 ;
    for(int i = 2 ;mpz_cmp_ui(ncopy , 1) != 0 ; i ++)
    {
        int flag = 0 ;
        while(mpz_divisible_ui_p(ncopy, i) != 0)
        {
            flag = 1 ;
            mpz_cdiv_q_ui(ncopy ,ncopy , i );
        }
        if(flag)
        {
            mpz_set_ui(arr[k] , i);
            k ++;
        }

    }
    int size = 0 ;
    for(int i = 0 ; mpz_cmp_ui(arr[i] , 0) > 0 ; i ++)
    {
         size ++ ;
        mpz_cdiv_q(supp[i] , n , arr[i] );
    }
    mpz_t orig_n ;
    mpz_init(orig_n);
    mpz_add_ui(orig_n , n , 1);
    int primitive_size = 0 ;
    for(int i = 2 ; mpz_cmp_ui(n, i) > 0 ; i ++)
    {
        int flag = 0 ;
        for(int j = 0 ; j < size ; j ++)
        {
            mpz_t rop ; 
            mpz_t te ; 
            mpz_inits(rop ,te , NULL);
            mpz_set_ui(te , i );
            mpz_powm(rop , te , supp[j] , orig_n);
            if(mpz_cmp_ui(rop , 1) == 0)
            {
                flag =1 ;
                break;
            }
        }
        if(flag == 0)
        {
            gmp_printf("%d " ,i );
            primitive_size ++ ;
        }
    }
    printf("\ntotal number of primitive numbers are %d", primitive_size);
    
}
int main()
{
    mpz_t n ;
    mpz_init(n) ; 
    gmp_printf("Enter thr number : ");
    gmp_scanf("%Zd" , &n) ;
    if(mpz_probab_prime_p(n ,24) == 2)
    {
        mpz_sub_ui(n ,n, 1);
        primitive(n) ;
    }
}