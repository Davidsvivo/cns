#include <string.h>
#include <ctype.h>
#include <stdio.h>

void encryption(char msg[] , int key[][100]);

int main() {
    int key[100][100];
    char msg[100];
    printf("Enter the 3 * 3 matrix key: ");
    
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            scanf("%d" , &key[i][j]);
        }
    }
    
    printf("Enter the msg: ");
    scanf("%s" , msg);
    
    printf("The encrypted msg is: ");
    encryption(msg , key);
    
    return 0;
}

void encryption(char msg[] , int key[][100]){
    
    int len = strlen(msg);
    int ciper[len];
    
    for(int i = 0 ; i < len ; i++){
        ciper[i] = msg[i] - 'A';
    }
    
    while(len % 3 != 0){
        msg[len] = 'X';
        ciper[len] = 23;
        len++;
    }
    
    for(int a = 0 ; a < len ; a+=3){
        for(int i = 0 ; i < 3 ; i++){
            int sum = 0;
            
            for(int j = 0 ; j < 3 ; j++){
                sum += key[i][j] * ciper[a+j];
            }
            
            msg[a+i] = (sum % 26) + 'A';
        }
    }
    
    printf("%s" , msg);
}
