#include <stdio.h>

// Function to find gcd
int gcd(int a, int b) {
    int gcd = 1; // Initialize gcd to 1 (since 1 is a common divisor for any pair of integers)

    // Iterate from 1 to the minimum of a and b
    for (int i = 1; i <= (a < b ? a : b); i++) {
        // If i divides both a and b without leaving a remainder, update gcd
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    
    return gcd;
}

// Function to find the modular inverse of e mod phi
int modInverse(int e, int phi) {
    e = e % phi;
    for (int x = 1; x < phi; x++) {
        if ((e * x) % phi == 1)
            return x;
    }
    return -1;
}

// Function to perform modular exponentiation
// It returns (base^exponent) % mod
long long modExp(long long base, long long exponent, long long mod) {
    long long result = 1;
    for (long long i = 0; i < exponent; i++) {
        result = (result * base) % mod;
    }
    return result;
}

int main() {
    int p, q, e, msg;

    printf("Enter the value of p: ");
    scanf("%d", &p);

    printf("Enter the value of q: ");
    scanf("%d", &q);

    printf("Enter the value of e: ");
    scanf("%d", &e);
    
    printf("Enter the value of msg: ");
    scanf("%d", &msg);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    
    int d = modInverse(e, phi);
    if (d == -1) {
        printf("No modular inverse found for the given e.\n");
        return -1;
    }

    printf("Message data = %d\n", msg);

    // Encryption c = (msg ^ e) % n
    long long c = modExp(msg, e, n);
    printf("Encrypted data = %lld\n", c);

    // Decryption m = (c ^ d) % n
    long long m = modExp(c, d, n);
    printf("Original Message Sent = %lld\n", m);

    return 0;
}
