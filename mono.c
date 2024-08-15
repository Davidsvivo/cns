#include <stdio.h>
#include <string.h>

void encrypt(char plaintext[], char key[]) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (plaintext[i] != ' ') {  // Skip spaces
            plaintext[i] = key[plaintext[i] - 'A'];
        }
    }
}

void decrypt(char ciphertext[], char key[]) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        if (ciphertext[i] != ' ') {  // Skip spaces
            ciphertext[i] = 'A' + (strchr(key, ciphertext[i]) - key);
        }
    }
}

int main() {
    char plaintext[256];
    char key[27];
    char ciphertext[256];

    printf("Enter the plaintext (uppercase letters and spaces only): ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key (26 uppercase letters): ");
    fgets(key, sizeof(key), stdin);
  

    // Encrypt the plaintext
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key);
    printf("Decrypted Plaintext: %s\n", ciphertext);

    return 0;
}
