#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//Play Fair Cipher
char bogus_letter = 'x'; 
void playfairEncrypt(char *plainText , char matrix[5][5] , char* encryptText )
{
    int len = strlen(plainText);
    printf("Before s = %s\n" , plainText);
    for(int i = 0 ; plainText[i+1]!='\0'; i ++)
    {
        if(plainText[i] == plainText[i+1])
        {
            char temp = plainText[i+1] ;
            plainText[i+1] = 'x';
            int j ;
            for(j = strlen(plainText) ; j > i + 1 ;  j -- )
            {
                plainText[j+1] = plainText[j] ;  
            }
            plainText[j+1] = temp;
        }
    }
    if(strlen(plainText)%2 != 0 )
    {
        int len = strlen(plainText);
        plainText[len+1] = plainText[len];
        plainText[len] = bogus_letter;

    }
    for(int i = 0 ; i < strlen(plainText) ; i ++)
    {
        if(plainText[i] == 'j')
        {
            plainText[i] = 'i';
        }
    }
    for(int i = 0 ; i < strlen(plainText) ; i = i + 2)
    {
        int char1_row , char2_row , char1_col , char2_col  ,flag1 = 0 , flag2 = 0;
        for(int m = 0 ; m < 5 ; m ++ )
        {
            for(int n  = 0 ; n < 5 ; n ++)
            {
                if(matrix[m][n] == plainText[i])
                {
                    char1_row = m ;
                    char1_col = n ;
                    flag1 = 1 ; 
                }
                else if (matrix[m][n] == plainText[i+1])
                {
                    char2_row = m ;
                    char2_col = n ;
                    flag2 = 1 ;
                }
                if(flag1 == 1 && flag2 == 1 )
                {
                    break;
                }
            }
            if(flag1 == 1 && flag2 == 1)
            {
                flag1 = 0 ;
                flag2 = 0 ;
                break;
            }
        }
        if(char1_row == char2_row)
        {
            encryptText[i] = matrix[char1_row][(char1_col + 1)%5];
            encryptText[i+1] = matrix[char2_row][(char2_col + 1)%5];
        }
        else if (char1_col == char2_col)
        {
            encryptText[i] = matrix[(char1_row + 1)%5][char1_col];
            encryptText[i+1] = matrix[(char2_row + 1)%5][char2_col];
        }
        else
        {
            encryptText[i] = matrix[char1_row][char2_col];
            encryptText[i+1] = matrix[char2_row][char1_col];
        }
    }
    encryptText[strlen(plainText)] = '\0';
    printf("After plainText = %s\n" , plainText);
    printf("After encryptedText = %s" , encryptText);
}
void playfairDecrypt(char* plainText , char matrix[5][5] , char* decryptText)
{
    int len = strlen(plainText);
    printf("Before s = %s\n" , plainText);
    for(int i = 0 ; plainText[i+1]!='\0'; i ++)
    {
        if(plainText[i] == plainText[i+1])
        {
            char temp = plainText[i+1] ;
            plainText[i+1] = 'x';
            int j ;
            for(j = strlen(plainText) ; j > i + 1 ;  j -- )
            {
                plainText[j+1] = plainText[j] ;  
            }
            plainText[j+1] = temp;
        }
    }
    if(strlen(plainText)%2 != 0 )
    {
        int len = strlen(plainText);
        plainText[len+1] = plainText[len];
        plainText[len] = bogus_letter;

    }
    for(int i = 0 ; i < strlen(plainText) ; i ++)
    {
        if(plainText[i] == 'j')
        {
            plainText[i] = 'i';
        }
    }
    for(int i = 0 ; i < strlen(plainText) ; i = i + 2)
    {
        int char1_row , char2_row , char1_col , char2_col  ,flag1 = 0 , flag2 = 0;
        for(int m = 0 ; m < 5 ; m ++ )
        {
            for(int n  = 0 ; n < 5 ; n ++)
            {
                if(matrix[m][n] == plainText[i])
                {
                    char1_row = m ;
                    char1_col = n ;
                    flag1 = 1 ; 
                }
                else if (matrix[m][n] == plainText[i+1])
                {
                    char2_row = m ;
                    char2_col = n ;
                    flag2 = 1 ;
                }
                if(flag1 == 1 && flag2 == 1 )
                {
                    break;
                }
            }
            if(flag1 == 1 && flag2 == 1)
            {
                flag1 = 0 ;
                flag2 = 0 ;
                break;
            }
        }
        if(char1_row == char2_row)
        {
            decryptText[i] = matrix[char1_row][(char1_col - 1)<0?4:(char1_col-1)%5];
            decryptText[i+1] = matrix[char2_row][(char2_col - 1)<0?4:(char2_col-1)%5];
        }
        else if (char1_col == char2_col)
        {
            decryptText[i] = matrix[(char1_row -1 )<0?4 : (char1_row-1)%5][char1_col];
            decryptText[i+1] = matrix[(char2_row -1) <0?4:(char2_row-1)%5][char2_col];
        }
        else
        {
            decryptText[i] = matrix[char1_row][char2_col];
            decryptText[i+1] = matrix[char2_row][char1_col];
        }
    }
    decryptText[strlen(plainText)] = '\0';
    printf("After decryptedText = %s" , decryptText);
}
int main(int argc, char* argv[])
{
    bool arr[26] ;    //figure out ki knosa character abhi available hai
    char result[27] ; 
    int k = 0 ;
    //to get the required matrix
    char matrix[5][5] ; 
    memset(arr , true , 26*sizeof(arr[0])); 
    arr[9] = false;    //we are settting 'j' as not available since i and j are sharing same cell
    for(int i = 2 ; i < argc  ; i = i  + 1)
    {
        char* temp = argv[i];
        int len = strlen(argv[i]);
        for(int j = 0; j < len; j ++)
        {
            if(arr[argv[i][j]-'a'] == false)
            {
                for(;  j < len && arr[argv[i][j]- 'a'] == false  ;j ++ )
                {
                }
                if(j!= len )
                {
                    result[k] = argv[i][j];
                    arr[argv[i][j]- 'a'] = false; 
                    k ++;
                }
            }
            else
            {
                result[k] = argv[i][j];
                arr[argv[i][j] -'a'] = false;
                k ++;
            }
        }
    }
    for(int i = 2 ; i < argc && k < 26 ; i = (i)%(argc-2) + 2)
    {
        char* temp = argv[i];
        int len = strlen(argv[i]);
        for(int j = 0; j < len && k <26 ; j ++)
        {
            if(arr[argv[i][j]-'a'] == false)
            {
                int p  , s = 0;
                for(p = (argv[i][j] - 'a' + 1)%26 ; s< 26 && arr[p%26] != true ; p ++ )
                {
                    s ++ ;
                }
                result[k] = p%26 + 'a';
                arr[p%26] = false;

            }
            else
            {
                result[k] = argv[i][j];
                arr[argv[i][j] -'a'] = false;
            }
            k++;
        }
    }
    result[k] = '\0';
    printf("result is %s\n" , result);
    k = 0 ;
    for(int i = 0 ; i < 5 ; i ++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            matrix[i][j] = result[k] ;
            k ++;
        }
    }  
    for(int i = 0 ; i <5 ; i ++)
    {
        for(int j = 0 ; j < 5 ; j ++)
        {
            printf("%c " , matrix[i][j]);
        }
        printf("\n");
    }
    char plainText[1000]; 
    char encryptText[1000];
    char decryptText[1000];
    encryptText[0] = '\0';
    
    if(argv[1][0] == '-' && argv[1][1] =='e')
    {
        printf("Enter the plainText you want to encrypt : ");
        scanf("%s" , plainText);
        playfairEncrypt(plainText , matrix , encryptText);
    }  
    else if(argv[1][0] == '-' && argv[1][1] =='d')
    {
        printf("Enter the ciphertext you want to decrypt : ");
        scanf("%s" , plainText);
        playfairDecrypt(plainText , matrix , encryptText);
    }   
    else
        printf("Usage ./a.out -d or -e text ...");
    
}