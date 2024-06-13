#include<stdio.h>
#include<gmp.h>
void decryption(mpz_t d , mpz_t n , mpz_t encrypted , mpz_t pT)
{
    gmp_printf("While decrypting ...\n ");
    mpz_powm(pT , encrypted , d , n);
}
void encryption(mpz_t c, mpz_t n , mpz_t encrypted)
{
    gmp_printf("While encrypting ... \n");
    char str[1000];
    mpz_t pT ; 
    mpz_init(pT);
    gmp_printf("\nEnter the plaintText : ");
    gmp_scanf("%s" ,str );
    mpz_set_str(pT , str , 36);
    gmp_printf("\nin digit format plainText : %Zd" , pT);
    mpz_powm(encrypted , pT  , c , n);
}
void key_generation(mpz_t p , mpz_t q, mpz_t n , mpz_t phi_n , mpz_t c , mpz_t d )
{
    gmp_printf("Key generation  phase ...\n ");
    mpz_t l , p_sub , q_sub , gcd_rop; 
    unsigned long seed ; 
    mpz_inits(l , p_sub , q_sub , gcd_rop ,  NULL);
    mpz_ui_pow_ui(l ,2, 199);
    gmp_randstate_t rstate ; 
    gmp_randinit_mt(rstate);
    gmp_randseed_ui(rstate , seed);
    do{
        mpz_urandomb(p , rstate ,310);
        mpz_add(p , p, l);
    }while(!(mpz_probab_prime_p(p,24)));
    do{
        mpz_urandomb(q , rstate , 310);
        mpz_add(q , q  , l);
    }while(!(mpz_probab_prime_p(q ,24)));
    gmp_printf("\nthe random values are as follows p =  %Zd and  q = %Zd\n" , p , q);
    mpz_mul(n , p, q);
    mpz_sub_ui(p_sub, p , 1);
    mpz_sub_ui(q_sub , q , 1);
    mpz_mul(phi_n , p_sub , q_sub);
    gmp_printf("\nThe value of n = %Zd\n", n);
    gmp_printf("\nThe value of phi_n = %Zd\n", phi_n);
     do{
        mpz_urandomb(c , rstate ,105);
        mpz_add(c , c, l);
        mpz_gcd(gcd_rop , c , phi_n) ;
    }while(mpz_cmp_ui(gcd_rop ,1));
    mpz_invert(d , c , phi_n);
    gmp_randclear(rstate);
    gmp_printf("\nthe value of c = %Zd \n and value of d = %Zd " ,c , d);
    mpz_clears(l , p_sub , q_sub , gcd_rop, NULL);
}
int main()
{
    mpz_t p , q , n , phi_n , c , d , pT , encrypted_text  ;
    mpz_inits(p ,q ,n , phi_n , c ,d ,pT , encrypted_text , NULL) ; 
    key_generation(p , q , n , phi_n , c , d);
    encryption(c , n ,encrypted_text);
    gmp_printf("\nEncrpyted text is : %Zd \n" , encrypted_text);
    decryption(d ,n, encrypted_text , pT);
    gmp_printf("\nDecrypted Text is : %Zd \n", pT);
    char str[10000];
    mpz_get_str(str ,36 , pT );
    gmp_printf("\nWord format : %s",str );
    mpz_clears(p,q,n,phi_n ,c,d, pT, encrypted_text, NULL);
    return 0 ;

}