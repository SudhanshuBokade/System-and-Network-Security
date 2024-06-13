#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Caesar Cipher encryption
void caesarEncrypt(char *plaintext, char *key, char *ciphertext) {
    int keyLength = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if (j == keyLength)
            j = 0;

        char currentChar = plaintext[i];
        char keyChar = key[j];

        int shift = (tolower(keyChar) - 'a') + 1; // Convert key char to shift value
        
        if (islower(currentChar))
            ciphertext[i] = ((currentChar - 'a' + shift) % 26) + 'A';
        else if (isupper(currentChar))
            ciphertext[i] = ((currentChar - 'A' + shift) % 26) + 'A';
        else
            ciphertext[i] = currentChar;
    }

    ciphertext[i] = '\0'; // Null-terminate the result
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <plaintext>\n", argv[0]);
        return 1;
    }

    char *key = "K_roll1";
    char plaintext[1000];
    plaintext[0] = '\0';
    char ciphertext[1000];
    ciphertext[0] = '\0';
    for (int i = 1; i < argc; i++) {
        strcat(plaintext, argv[i]);
        if (i < argc - 1) strcat(plaintext, " ");
    }

    caesarEncrypt(plaintext, key, ciphertext);



    return 0;
}
