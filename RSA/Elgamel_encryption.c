#include<stdio.h>
#include<gmp.h>
#include "primitive.c"
void Elgamel_encryption(mpz_t pT , mpz_t p , mpz_t e1 , mpz_t e2 , mpz_t c1 , mpz_t c2)
{
    char a[10000];
    gmp_printf("Enter the string  : ");
    gmp_scanf("%s" , a );
    mpz_set_str(pT , a , 36);
    //selecting the random number 
    mpz_t l ,  gcd_rop ,r ; 
    unsigned long seed ; 
    mpz_inits(l , gcd_rop , r , NULL);
    mpz_ui_pow_ui(l ,2, 199);
    gmp_randstate_t rstate ; 
    gmp_randinit_mt(rstate);
    gmp_randseed_ui(rstate , seed);
    do{
        mpz_urandomb(r , rstate ,310);
        mpz_add(r , r, l);
        mpz_gcd(gcd_rop , r , p );
    }while(mpz_cmp_ui(gcd_rop,1)!= 0);
    printf("got r\n");
    mpz_powm(c1 , e1 , r , p );     //c1 = e1^r mod p 
    mpz_powm(c2 , e2 , r , p );
    mpz_mul(c2 , pT , c2);
    mpz_mod(c2 , c2 , p);      // c2 = pT x (e2)^r mod p
    gmp_printf("Value of c1 = %Zd \n", c1);
    gmp_printf("Value of c2 = %Zd\n", c2);
    mpz_clears(l , gcd_rop , r , NULL);


}
void Elgamel_decryption(mpz_t d , mpz_t p , mpz_t c1 , mpz_t c2)
{
    mpz_t pT ;
    char str[10000]; 
    mpz_inits(pT ,NULL);
    mpz_powm(pT , c1 , d , p );
    mpz_invert(pT , pT ,p);
    mpz_mul(pT ,pT , c2 );
    mpz_mod(pT ,pT , p);
    gmp_printf("\nPlainText in number format : %Zd" , pT);
    mpz_get_str(str , 36 , pT);
    printf("\nOriginal plainText is %s" , str);
}
void keyGeneration(mpz_t p , mpz_t e1 , mpz_t e2 , mpz_t d )
{
    primitive_root(p , e1 );
    mpz_t l ,  gcd_rop; 
    unsigned long seed ; 
    mpz_inits(l , gcd_rop ,  NULL);
    mpz_ui_pow_ui(l ,2, 199);
    gmp_randstate_t rstate ; 
    gmp_randinit_mt(rstate);
    gmp_randseed_ui(rstate , seed);
    do{
        mpz_urandomb(d , rstate ,310);
        mpz_add(d , d, l);
        mpz_gcd(gcd_rop , d , p );
    }while(mpz_cmp_ui(gcd_rop,1)!= 0);
    printf("\n got d \n");
    mpz_powm(e2 , e1 , d , p );
    gmp_printf("\np = %Zd\n e1 = %Zd\ne2 = %Zd\n" , p , e1 ,e2);
     mpz_clears(l , gcd_rop ,  NULL);
}
int main()
{
    mpz_t pT , p , d , e1 , e2 ,c1 ,c2 ; 
    mpz_inits(pT ,p ,d , e1 , e2 ,c1 , c2, NULL);
    keyGeneration(p,e1,e2,d);
    
    Elgamel_encryption(pT , p , e1 , e2 ,c1 ,c2);
    Elgamel_decryption(d ,p , c1 , c2);
    mpz_clears(pT,p,d,e1,e2,c1,c2,NULL);
}