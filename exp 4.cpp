#include <stdio.h>

#define MOD 26

// Function to compute modular inverse of 'a' under modulo 26
int modInverse(int a) {
    for (int i = 1; i < MOD; i++) {
        if ((a * i) % MOD == 1)
            return i;
    }
    return -1;
}

// Encrypt using Affine Cipher
char affineEncrypt(char ch, int a, int b) {
    if (ch >= 'a' && ch <= 'z')
        return ((a * (ch - 'a') + b) % MOD) + 'a';
    if (ch >= 'A' && ch <= 'Z')
        return ((a * (ch - 'A') + b) % MOD) + 'A';
    return ch;
}

// Decrypt using Affine Cipher
char affineDecrypt(char ch, int a, int b) {
    int a_inv = modInverse(a);
    if (a_inv == -1) {
        printf("Invalid key 'a'. No modular inverse exists.\n");
        return ch;
    }

    if (ch >= 'a' && ch <= 'z')
        return ((a_inv * (ch - 'a' - b + MOD)) % MOD) + 'a';
    if (ch >= 'A' && ch <= 'Z')
        return ((a_inv * (ch - 'A' - b + MOD)) % MOD) + 'A';
    return ch;
}

void affineCipher(char *text, int a, int b, int decrypt) {
    while (*text) {
        if (decrypt)
            *text = affineDecrypt(*text, a, b);
        else
            *text = affineEncrypt(*text, a, b);
        text++;
    }
}

int main() {
    char text[1000];
    int a, b, choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter values for a and b: ");
    scanf("%d %d", &a, &b);

    printf("1. Encrypt\n2. Decrypt\nChoose: ");
    scanf("%d", &choice);

    affineCipher(text, a, b, choice - 1);
    printf("%s\n", text);

    return 0;
}
