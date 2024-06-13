#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

// Function to hash a message using SHA-256
void hash_message(const char* message, mpz_t result) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit(mdctx, EVP_sha256());
    EVP_DigestUpdate(mdctx, message, strlen(message));
    EVP_DigestFinal(mdctx, hash, NULL);
    EVP_MD_CTX_free(mdctx);

    mpz_import(result, SHA256_DIGEST_LENGTH, 1, 1, 0, 0, hash);
}

void signing(mpz_t pT , mpz_t c , mpz_t n , mpz_t signature)
{
    mpz_powm(signature , pT , c , n);
    gmp_printf("Reuired signature S =  %Zd \n", signature);

}
void verifying(mpz_t signature , mpz_t pT , mpz_t d ,mpz_t n)
{
    mpz_t m1 ; 
    mpz_init(m1);
    mpz_powm(m1 , signature , d , n);
    gmp_printf("Signature^d = %Zd \n pT = %Zd" , m1 , pT );
    if(mpz_cmp(m1 ,pT ) == 0)
    { 
        gmp_printf("\nSince Signature^d and plainText are equal , Signature verfied .");
    }
    else
    {
        gmp_printf("Signature not verified . ");
    }
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
    mpz_t p , q , n , phi_n , c , d , pT , signature  ;
    mpz_inits(p ,q ,n , phi_n , c ,d ,pT , signature , NULL) ; 
    char str[1000];
    gmp_printf("Enter the string : ");
    hash_message(str ,pT );
    scanf("%s", str);
    mpz_set_str(pT ,str ,36 );
    key_generation(p , q , n , phi_n , c , d);
    signing(pT , c , n , signature);
    verifying(signature , pT ,  d , n);
    mpz_clears(p,q,n,phi_n ,c,d, pT, signature, NULL);
    return 0 ;

}