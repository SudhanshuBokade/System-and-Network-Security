#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>
// This function receives text and shift and
// returns the encrypted text
char* encrypt(char* text, int s) {
    int i;
    char* result = malloc(strlen(text) + 1);  // Allocate memory for the result

    // Traverse text
    for (i = 0; i < strlen(text); i++) {
        // Apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result[i] = (char)(((int)text[i] + s - 65) % 26 + 65);

        // Encrypt Lowercase letters
        else
            result[i] = (char)(((int)text[i] + s - 97) % 26 + 97);
    }

    // Null-terminate the resulting string
    result[i] = '\0';

    // Return the resulting string
    return result;
}

int main() {
    char text[100] ;
    printf("Enter the string : ");
    fgets(text , 100 ,stdin);
    int s;
    printf("Enter the key : ");
    scanf("%d" , &s);
    printf("Text : %s\n", text);
    printf("Shift: %d\n", s);
    
    char* cipher = encrypt(text, s);
    printf("Cipher: %s\n", cipher);
    
    free(cipher);  // Free allocated memory
    
    return 0;
}
