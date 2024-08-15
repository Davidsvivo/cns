#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char plaintext[], char key[], char ciphertext[]) {
    int keyLen = strlen(key);
    int plaintextLen = strlen(plaintext);

    for (int i = 0, j = 0; i < plaintextLen; i++, j++) {
        if (j >= keyLen) {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        ciphertext[i] = ((toupper(plaintext[i]) - 'A' + shift) % 26) + 'A';
    }
    ciphertext[plaintextLen] = '\0';  // Null-terminate the ciphertext
}

void decrypt(char ciphertext[], char key[], char plaintext[]) {
    int keyLen = strlen(key);
    int ciphertextLen = strlen(ciphertext);

    for (int i = 0, j = 0; i < ciphertextLen; i++, j++) {
        if (j >= keyLen) {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        plaintext[i] = ((toupper(ciphertext[i]) - 'A' - shift + 26) % 26) + 'A';
    }
    plaintext[ciphertextLen] = '\0';  // Null-terminate the plaintext
}

int main() {
    char plaintext[128], key[16], ciphertext[128];

    // Encryption Process
    printf("Enter the plaintext (up to 128 characters): ");
    scanf(" %s", plaintext); 
    
    printf("Enter the key (up to 16 characters): ");
    scanf("%s", key);
    // scanf(" %[^\n]", key);

    encrypt(plaintext, key, ciphertext);
    printf("Cipher Text: %s\n", ciphertext);

    // Decryption Process
    decrypt(ciphertext, key, plaintext);
    printf("Deciphered Text: %s\n", plaintext);

    return 0;
}
