#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 

#define SIZE 30

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
}

// Generate the 5x5 key table for Playfair Cipher
void generateKeyTable(char key[], char keyTable[5][5]) {
    int dict[26] = {0}, k = 0;

    // Fill the keyTable with key characters
    for (int i = 0; key[i]; i++) {
        if (key[i] != 'j' && dict[key[i] - 'a'] == 0) {
            keyTable[k / 5][k % 5] = key[i];
            dict[key[i] - 'a'] = 1;
            k++;
        }
    }

    // Fill remaining table with other alphabet characters
    for (int i = 0; i < 26; i++) {
        if (i != ('j' - 'a') && dict[i] == 0) {
            keyTable[k / 5][k % 5] = 'a' + i;
            k++;
        }
    }
}

// Encrypt the text using Playfair Cipher
void encryptText(char text[], char keyTable[5][5]) {
    for (int i = 0; text[i] && text[i + 1]; i += 2) {
        int a[2], b[2];

        // Find positions of the characters in the keyTable
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (keyTable[row][col] == text[i]) {
                    a[0] = row;
                    a[1] = col;
                }
                if (keyTable[row][col] == text[i + 1]) {
                    b[0] = row;
                    b[1] = col;
                }
            }
        }

        // Encrypt according to Playfair rules
        if (a[0] == b[0]) {  // Same row
            text[i] = keyTable[a[0]][(a[1] + 1) % 5];
            text[i + 1] = keyTable[b[0]][(b[1] + 1) % 5];
        } else if (a[1] == b[1]) {  // Same column
            text[i] = keyTable[(a[0] + 1) % 5][a[1]];
            text[i + 1] = keyTable[(b[0] + 1) % 5][b[1]];
        } else {  // Rectangle
            text[i] = keyTable[a[0]][b[1]];
            text[i + 1] = keyTable[b[0]][a[1]];
        }
    }
}

int main() {
    char key[SIZE], text[SIZE], keyTable[5][5];

    // Input the key
    printf("Enter the key: ");
    scanf("%s", key);
    toLowerCase(key);

    // Input the text to encrypt
    printf("Enter the plaintext: ");
    scanf("%s", text);
    toLowerCase(text);

    // Ensure the text length is even by adding 'x' if necessary
    if (strlen(text) % 2 != 0) {
        strcat(text, "x");
    }

    // Generate the key table and encrypt the text
    generateKeyTable(key, keyTable);
    encryptText(text, keyTable);

    // Output the encrypted text
    printf("Cipher text: %s\n", text);

    return 0;
}
