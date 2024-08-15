#include <stdio.h>
#include <string.h>

void getKeyMatrix(char key[], int keyMatrix[3][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = key[k] % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[3][1], int keyMatrix[3][3], int plainTextVector[3][1]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            cipherMatrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                cipherMatrix[i][j] += keyMatrix[i][k] * plainTextVector[k][j];
            }
            cipherMatrix[i][j] %= 26;
        }
    }
}

void HillCipher(char plainText[], char key[]) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int plainTextVector[3][1];
    for (int i = 0; i < 3; i++)
        plainTextVector[i][0] = plainText[i] % 65;

    int cipherMatrix[3][1];
    encrypt(cipherMatrix, keyMatrix, plainTextVector);

    char CipherText[4];
    for (int i = 0; i < 3; i++)
        CipherText[i] = cipherMatrix[i][0] + 65;
    CipherText[3] = '\0';

    printf("Ciphertext: %s\n", CipherText);
}

int main() {
    char plainText[4];
    char key[10];

    printf("Enter plainText: ");
    scanf("%s", plainText);

    printf("Enter Key: ");
    scanf("%s", key);

    HillCipher(plainText, key);

    return 0;
}
