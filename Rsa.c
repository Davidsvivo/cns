#include <stdio.h> 
// Function to calculate (base^exp) % modulus 
 int power( int base,  int exp,  int modulus) { 
  int result = 1; 
 while (exp > 0) { 
 if (exp % 2 == 1) { 
 result = (result * base) % modulus; 
 } 
 base = (base * base) % modulus; 
 exp /= 2; 
 } 
 return result; 
} 
// Function to perform RSA encryption 
 int encrypt( int plaintext,  int e,  int n) { 
 return power(plaintext, e, n); 
} 
// Function to perform RSA decryption 
 int decrypt( int ciphertext,  int d,  int n) { 
 return power(ciphertext, d, n); 
} 
int main() { 
 // Public and private keys 
  int p = 61; 
  int q = 53; 
  int n = p * q; 
  int phi = (p - 1) * (q - 1); 
  int e = 17; // Public exponent 
  int d = 413; // Private exponent 
 // Message to be encrypted 
  int plaintext = 123; 

 // Encryption 
  int ciphertext = encrypt(plaintext, e, n); 
 printf("Encrypted message: %d\n", ciphertext); 
 // Decryption 
  int decryptedtext = decrypt(ciphertext, d, n); 
 printf("Decrypted message: %d\n", decryptedtext); 
 return 0; 
}
