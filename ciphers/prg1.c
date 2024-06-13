#include <stdio.h>
#include <string.h>
#include<gmp.h>
//Caesar cipher
char arr[37] = {'0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,' ', 'A' ,'B', 'C','D','E','F','G','H' ,'I','J' ,'K' ,'L' ,'M' ,'N' ,'O','P','Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z'};
void caesarCipher_encrypt(char *plaintext, int len, int key)
{
    char cipherText[len + 1];
    cipherText[0] ='\0';
    mpz_t code ; 
    mpz_init(code);
    int temp ;
    for (int i = 0; i < len; i++)
    {

        if (plaintext[i] - '0' <= 9 && plaintext[i] - '0' >= 0)
        {
            mpz_set_ui(code , plaintext[i] - '0' + key);
            mpz_mod_ui(code , code ,37);
            temp = mpz_get_si(code );
            cipherText[i] = arr[temp];
            
        }
        else if (plaintext[i] == ' ')
        {
            cipherText[i] = arr[key + 10]; 
        }
        else if(plaintext[i] - 'a' >= 0 && plaintext[i] - 'a' <= 25)
        {
            mpz_set_ui(code , (plaintext[i] -'a' + 11 + key)) ;
            mpz_mod_ui(code , code , 37);
            temp = mpz_get_ui(code);
            cipherText[i] = arr[temp];
        }
    }
    cipherText[len] = '\0';
    printf("Cipher_text is %s" , cipherText);
}
void caesarCipher_decrpyt(char* cipherText , int len , int key)
{
    char plainText[len + 1];
    plainText[0] ='\0';
    mpz_t code ; 
    mpz_init(code);
    int temp ;
    for (int i = 0; i < len; i++)
    {

        if (cipherText[i] - '0' <= 9 && cipherText[i] - '0' >= 0)
        {
            mpz_set_si(code , cipherText[i] - '0' - key);
            mpz_mod_ui(code , code ,37);
            temp = mpz_get_si(code);
            plainText[i] = arr[temp];
        }
        else if (cipherText[i] == ' ')
        {
            mpz_set_si(code , (-key + 10));
            mpz_mod_ui(code ,code , 37);
            temp = mpz_get_ui(code);
            plainText[i] = arr[temp] ; 
        }
        else if(cipherText[i] - 'A' >= 0 && cipherText[i] - 'A' <= 25)
        {
            mpz_set_si(code , (cipherText[i] -'A' + 11 - key)) ;
            mpz_mod_ui(code , code , 37);
            temp = mpz_get_ui(code);
            plainText[i] = arr[temp];
        }
    }
    plainText[len] = '\0';
    printf("Plain_text is %s" , plainText);
}
int main(int argc, char *argv[])
{
    int n = argc;
    char plaintext[1000];
    plaintext[0] = '\0';
    int i;
    int key = 4;
    for (i = 2; i < n - 1; i++)
    {
        strcat(plaintext, argv[i]);
        strcat(plaintext, " ");
    }
    strcat(plaintext, argv[i]);
    if(argv[1][0] == '-' && argv[1][1] =='e')
        caesarCipher_encrypt(plaintext, strlen(plaintext), key);
    else if(argv[1][0] =='-' && argv[1][1] =='d')
        caesarCipher_decrpyt(plaintext,strlen(plaintext) , key);    
}