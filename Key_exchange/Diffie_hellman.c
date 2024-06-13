#include<stdio.h>
#include<gmp.h>
int main()
{
    mpz_t p,g ,x ,y , r1 ,r2 ,temp1, temp2 , sym_key;
    mpz_inits(p, g ,x ,y, r1 ,r2 , temp1, temp2 , sym_key , NULL); 
    mpz_set_str(p , "FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE65381FFFFFFFFFFFFFFFF",16);
    mpz_set_ui(g , 2);
    gmp_printf("enter the Alice random number x :");
    gmp_scanf("%Zd" , x);
    gmp_printf("Enter the Bob random number y :" );
    gmp_scanf("%Zd", y);
    mpz_powm(r1 , g ,x, p);
    mpz_powm(r2 , g , y, p );
    gmp_printf("\nCalcualted R1 : %Zd " , r1);
    gmp_printf("\nCalculated R2 : %Zd", r2);
    mpz_powm(sym_key , r1 , y , p);
    mpz_powm(temp1 , r1 ,y , p );
    gmp_printf("\nr1^y = %Zd", temp1);
    mpz_powm(temp2 , r2 , x , p );
    gmp_printf("\nr2^x = %Zd" , temp2);
    gmp_printf("\nSymmtric key formed is r1^y = r2^x  = %Zd" , sym_key);
    mpz_clears(p ,g,x,y, r1, r2 ,temp1, temp2, sym_key , NULL);

}