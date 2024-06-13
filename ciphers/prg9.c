#include<stdio.h>
#include<string.h>
//rowx row  keyless transposition cipher
void cipher(char matrix[100][100] , int num_row ,int num_col)
{
    char cipherText[1000] ;
    int k = 0 ;
    for(int i = 0 ; i < num_col  ; i ++)
    {
        for(int j = 0 ; j < num_row ; j ++)
        {
            cipherText[k] = matrix[j][i];
            k++;
        }
    }
    cipherText[k] = '\0';
    printf("Ciphertext is %s" ,cipherText);
}
int main(int argc , char* argv[])
{
    int n = argc;
    char plaintext[1000];
    char matrix[100][100];
    plaintext[0] = '\0';
    int i , j , k =0 ;
    int key = 4;
    for (i = 1; i < n; i++)
    {
        strcat(plaintext, argv[i]); 
    }
    int len = strlen(plaintext);
    int l ;
    printf("What should be length of row ?");
    scanf("%d" , &l); 
    for(i = 0 ; i < len && k!=len ; i ++)
    {
        for(j = 0 ; j < l && k!=len; j ++)
        {
            matrix[i][j] = plaintext[k];
            k ++;
        }
    }
    if(j!=0)
    {
        while(j!=l)
        {
            matrix[i-1][j] = 'z';
            
            j ++;
        }
    }
    for(int p =0 ; p <= i ; p++)
    {
        for(int q = 0; q <= j ; q ++)
        {
            printf("%c " ,matrix[p][q] );
        }
        printf("\n");
    }
    cipher(matrix , i , j );
    
}