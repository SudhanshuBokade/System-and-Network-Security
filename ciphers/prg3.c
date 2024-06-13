#include<stdio.h>
#include<string.h>
#include<gmp.h>
//autokey cipher
char arr[37] = {'0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,' ', 'A' ,'B', 'C','D','E','F','G','H' ,'I','J' ,'K' ,'L' ,'M' ,'N' ,'O','P','Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z'};
void autokey_encrypt(char* plaintext  , int len , int key)
{
    char encryptText[1000];
    mpz_t key_dynamic,code , index ,temp ;   // initialise 1st key as key
    mpz_inits(key_dynamic ,code , index , temp ,NULL);
     mpz_set_ui(key_dynamic , key);
    for(int i = 0 ; i < len; i ++)
    { 
        
        if(plaintext[i] - '0' >= 0 && plaintext[i] - '0' < 10)     // If it is a digit
        {
            mpz_set_ui(code , plaintext[i] - '0');
            mpz_add(key_dynamic ,code , key_dynamic);
            mpz_set_ui(temp,37);
            mpz_mod(index , key_dynamic ,temp);
        } 
        else if(plaintext[i] - 'a' >= 0 && plaintext[i] - 'a' < 26)  //if it is an alphabet
        {
            mpz_set_ui(code , plaintext[i] - 'a' + 11);
            mpz_add(key_dynamic ,code , key_dynamic);
            mpz_set_ui(temp,37);
            mpz_mod(index , key_dynamic ,temp);
        } 
        else if (plaintext[i] == ' ')    //if it is a space
        {
            mpz_set_ui(code , 10);
            mpz_add(key_dynamic ,code , key_dynamic);
            mpz_set_ui(temp,37);
            mpz_mod(index , key_dynamic ,temp);
        }
        int ind = mpz_get_si(index);
        encryptText[i] = arr[ind];
        mpz_set(key_dynamic ,code);
    }
    mpz_clears(key_dynamic, code , index  ,temp, NULL);
    encryptText[strlen(plaintext)] = '\0';
    printf(" ciphertext is %s" , encryptText);

}
void autokey_decrypt(char cipherText[] , int len , int key)
{
    char plainText[1000];
    mpz_t key_dynamic , code , index  ,temp;   // initialise 1st key as key
    mpz_inits(key_dynamic, code , index  ,temp, NULL);
     mpz_set_ui(key_dynamic , key);
    for(int i = 0 ; i < len; i ++)
    { 
        if(cipherText[i] - '0' >= 0 && cipherText[i] - '0' < 10)     // If it is a digit
        {
            mpz_set_ui(code , cipherText[i] - '0');
            mpz_sub(key_dynamic ,code , key_dynamic);
            mpz_set_ui(temp,37);
            mpz_mod(index , key_dynamic ,temp);
        } 
        else if(cipherText[i] - 'A' >= 0 && cipherText[i] - 'A' < 26)  //if it is an alphabet
        {
            mpz_set_ui(code , cipherText[i] - 'A' + 11);
            mpz_sub(key_dynamic ,code , key_dynamic);
            mpz_set_ui(temp,37);
            mpz_mod(index , key_dynamic ,temp);
        } 
        else if (cipherText[i] == ' ')    //if it is a space
        {
            mpz_set_ui(code , 10);
            mpz_sub(key_dynamic ,code , key_dynamic);
            mpz_set_ui(temp,37);
            mpz_mod(index , key_dynamic ,temp);
        }
        int ind = mpz_get_si(index);
        plainText[i] = arr[ind];
        mpz_set(key_dynamic ,index);
    }
    mpz_clears(key_dynamic, code , index  ,temp, NULL);
    plainText[len] = '\0';
    printf(" plaintext is %s" , plainText);
}
int main(int argc , char* argv[])
{
    int n = argc;
    char plaintext[1000];
    
    plaintext[0] = '\0';
    int i;
    int key1 = 4;
   
    for (i = 2; i < n - 1; i++)
    {
        strcat(plaintext, argv[i]);
        strcat(plaintext, " ");
    }
    strcat(plaintext, argv[i]);
    if(argv[1][0] == '-' && argv[1][1] == 'e')
        autokey_encrypt(plaintext , strlen(plaintext) , key1);

    else if(argv[1][0] == '-' && argv[1][1] =='d')
        autokey_decrypt(plaintext ,strlen(plaintext) , key1);
    else
    {
        printf("Usage ./a.out -e or -d text ...");
    }    
    
}
