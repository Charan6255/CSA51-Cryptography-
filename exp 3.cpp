#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j = 0, len = strlen(plaintext), keyLen = strlen(key);

    for (i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            char shift = tolower(key[j % keyLen]) - 'a';
            ciphertext[i] = ((tolower(plaintext[i]) - 'a' + shift) % 26) + 'a';
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j = 0, len = strlen(ciphertext), keyLen = strlen(key);

    for (i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            char shift = tolower(key[j % keyLen]) - 'a';
            plaintext[i] = ((tolower(ciphertext[i]) - 'a' - shift + 26) % 26) + 'a';
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}

int main() {
    char plaintext[MAX], key[MAX], ciphertext[MAX], decrypted[MAX];

    printf("Enter plaintext: ");
    fgets(plaintext, MAX, stdin);
    printf("Enter key: ");
    fgets(key, MAX, stdin);

    // Remove newline characters if present
    plaintext[strcspn(plaintext, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
