#include<stdio.h>
#include<ctype.h>
#include<string.h>
//railfence cipher 
//transpositon keyless cipher
char arr[37] = {'0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,' ', 'A' ,'B', 'C','D','E','F','G','H' ,'I','J' ,'K' ,'L' ,'M' ,'N' ,'O','P','Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z'};

void railFence_encrypt(char* plainText , int len )
{
    char cipherText[1000];
    int k = 0 ;
    for(int i = 0 ;i <len; i +=2)
    {
       if(plainText[i] -'a' >= 0 && plainText[i] - 'a' < 26 )
            cipherText[k] = plainText[i]-'a' +'A' ; 
        else
            cipherText[k] = plainText[i] ;    
        k++;    
    }
    for(int i = 1 ; i  < len ; i +=2)
    {
        if(plainText[i] -'a' >= 0 && plainText[i] - 'a' < 26 )
            cipherText[k] = plainText[i] -'a' + 'A';
        else
            cipherText[k] = plainText[i] ;
        k ++;        
    }
    cipherText[k] ='\0';
    printf("Encrypted Text is %s" , cipherText);
}
void railFence_decrypt(char* plainText , int len  )
{
    char cipherText[1000];
    int k = 0 ;
    int l1 ;
    if(l1%2 == 0)
     l1= len/2;
    else
    {
        l1 = len/2 +1;
    }
    for(int i  = 0 ; i <l1 ; i ++)
    {
        cipherText[k] = plainText[i];
        k ++;
        cipherText[k] = plainText[len/2+i];
        k ++;
    }
    if(len%2 ==1)
    {
        cipherText[k] = plainText[len/2];
        k ++;
    }
    cipherText[k] ='\0';
    printf("Decrypted Text is %s" , cipherText);
}
int main(int argc , char* argv[])
{
    int n = argc;
    char plaintext[1000];
    plaintext[0] = '\0';
    int i;
    int key = 4;
    for (i = 2; i < n - 1; i++)
    {
        strcat(plaintext, argv[i]);
    }
    strcat(plaintext, argv[i]);
    if(argv[1][0] == '-' && argv[1][1] =='e')
        railFence_encrypt(plaintext, strlen(plaintext));
    else if(argv[1][0] =='-' && argv[1][1] =='d')
        railFence_decrypt(plaintext,strlen(plaintext));
    
    return 0 ;

}