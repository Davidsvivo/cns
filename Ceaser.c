#include <ctype.h>
#include <string.h>
#include <stdio.h>

void encryption(char text[], int key);
void decryption(char text[], int key);

int main() {
    int key;
    int choice;
    char text[500];
    
    printf("Enter the msg: ");
     scanf("%s" , text);
    
    
    printf("Enter the key: ");
    scanf("%d", &key);
    
   
            encryption(text, key);
      
            decryption(text, key);
   

    return 0;
}

void encryption(char text[], int key) {
    for(int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        
            ch = (ch - 'A' + key) % 26 + 'A';
       
        
        text[i] = ch;
    }
    
    printf("Encrypted msg is: %s\n", text);
}

void decryption(char text[], int key) {
    for(int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        
            ch = (ch - 'A' - key + 26) % 26 + 'A';
       
        
        text[i] = ch;
    }
    
    printf("Decrypted msg is: %s\n", text);
}
