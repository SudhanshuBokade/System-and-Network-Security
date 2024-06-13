#include <stdio.h>
#include <string.h>
#include<gmp.h>
//affine cipher
char arr[37] = {'0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,' ', 'A' ,'B', 'C','D','E','F','G','H' ,'I','J' ,'K' ,'L' ,'M' ,'N' ,'O','P','Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z'};
void affineCipher_encrypt(char *plaintext, int len, int key1 , int key2)
{
    char cipherText[len + 1];
    cipherText[0] ='\0';
    mpz_t code;
    int temp ;    // used for conveting mpz_t to int
    mpz_init(code);
    for (int i = 0; i < len; i++)
    {

        if (plaintext[i] - '0' <= 9 && plaintext[i] - '0' >= 0)
        {
            
            mpz_set_ui(code , (plaintext[i] - '0')); 
            mpz_mul_ui(code , code , key1);
            mpz_add_ui(code ,code, key2);
            mpz_mod_ui(code , code ,37 );
            temp = mpz_get_si(code);
            cipherText[i] = arr[temp];
            
        }
        else if (plaintext[i] == ' ')
        {
            mpz_set_ui(code , 10); 
            mpz_mul_ui(code , code , key1);
            mpz_add_ui(code ,code, key2);
            mpz_mod_ui(code , code ,37 );
            temp = mpz_get_si(code);
            cipherText[i] = arr[temp]; 
        }
        else if(plaintext[i] - 'a' >= 0 && plaintext[i] - 'a' <= 25)
        {
            mpz_set_ui(code , (plaintext[i] -'a' + 11));
            mpz_mul_ui(code , code , key1);
            mpz_add_ui(code , code , key2 );
            mpz_mod_ui(code , code ,37 );
            temp = mpz_get_si(code);
            cipherText[i] = arr[temp];
        }
    }
    cipherText[len] = '\0';
    printf("%s" , cipherText);
}
void affineCipher_decrypt(char * cipherText , int len , int key1 , int key2 )
{
    char plainText[len + 1];
    plainText[0] ='\0';
    mpz_t code , invt;
    int temp ;    // used for conveting mpz_t to int
    mpz_inits(code ,invt , NULL);
    for (int i = 0; i < len; i++)
    {
        mpz_t num , num2 ;
        mpz_inits(num ,num2 , NULL);
        if (cipherText[i] - '0' <= 9 && cipherText[i] - '0' >= 0)
        {
            
            mpz_set_ui(code , (cipherText[i] - '0')); 
            mpz_sub_ui(code , code , key2);
            mpz_set_ui(num ,37);
            mpz_set_d(num2 , key1);
            mpz_invert(invt , num2 , num ) ;
            mpz_mul(code ,code, invt);
            mpz_mod_ui(code , code ,37 );
            temp = mpz_get_si(code);
            plainText[i] = arr[temp];
            
        }
        else if (cipherText[i] == ' ')
        {
            mpz_set_ui(code , (10)); 
            mpz_sub_ui(code , code , key2);
            mpz_set_ui(num ,37);
            mpz_set_d(num2 , key1);
            mpz_invert(invt , num2 , num ) ;
            mpz_mul(code ,code, invt);
            mpz_mod_ui(code , code ,37 );
            temp = mpz_get_si(code);
            plainText[i] = arr[temp]; 
        }
        else if(cipherText[i] - 'A' >= 0 && cipherText[i] - 'A' <= 25)
        {
            mpz_set_ui(code , (cipherText[i] - 'A' +11)); 
            mpz_sub_ui(code , code , key2);
            mpz_set_ui(num ,37);
            mpz_set_d(num2 , key1);
            mpz_invert(invt , num2 , num ) ;
            mpz_mul(code ,code, invt);
            mpz_mod_ui(code , code ,37 );
            temp = mpz_get_si(code);
            plainText[i] = arr[temp];
        }
    }
    plainText[len] = '\0';
    printf("%s" , plainText);
}
int main(int argc, char *argv[])
{
    int n = argc;
    if(argc < 2)
    {
        printf("Program usage ./a.out word1 word2 word3 ...");
        return 0;
    }
    char plaintext[1000];
    plaintext[0] = '\0';
    int i;
    int key1 = 4;
    int key2 = 2 ;
    for (i = 2; i < n - 1; i++)
    {
        strcat(plaintext, argv[i]);
        strcat(plaintext, " ");
    }
    strcat(plaintext, argv[i]);
    if(argv[1][0] == '-' && argv[1][1] =='e')
        affineCipher_encrypt(plaintext, strlen(plaintext), key1 , key2);
    else if(argv[1][0] =='-' && argv[1][1] =='d')
        affineCipher_decrypt(plaintext,strlen(plaintext) , key1 ,key2);  
    else
    {
        printf("Usage ./a.out -e or -d text ...");
    }      
}
