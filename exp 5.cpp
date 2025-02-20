#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char keyTable[SIZE][SIZE];

// Removes duplicate characters from a string
void removeDuplicates(char str[]) {
    int len = strlen(str);
    int index = 0;
    int seen[26] = {0};

    for (int i = 0; i < len; i++) {
        if (!seen[toupper(str[i]) - 'A'] && isalpha(str[i])) {
            seen[toupper(str[i]) - 'A'] = 1;
            str[index++] = toupper(str[i]);
        }
    }
    str[index] = '\0';
}

// Generates a Playfair key table
void generateKeyTable(char key[]) {
    removeDuplicates(key);
    strcat(key, "ABCDEFGHIKLMNOPQRSTUVWXYZ"); // J is omitted
    removeDuplicates(key);

    int k = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            keyTable[i][j] = key[k++];
}

// Finds the position of a character in the table
void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (keyTable[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

// Encrypts plaintext using the Playfair cipher
void playfairEncrypt(char plaintext[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        findPosition(toupper(plaintext[i]), &row1, &col1);
        findPosition(toupper(plaintext[i + 1]), &row2, &col2);

        if (row1 == row2) {
            plaintext[i] = keyTable[row1][(col1 + 1) % SIZE];
            plaintext[i + 1] = keyTable[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            plaintext[i] = keyTable[(row1 + 1) % SIZE][col1];
            plaintext[i + 1] = keyTable[(row2 + 1) % SIZE][col2];
        } else {
            plaintext[i] = keyTable[row1][col2];
            plaintext[i + 1] = keyTable[row2][col1];
        }
    }
}

int main() {
    char key[100], plaintext[100];

    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    printf("Enter the plaintext (even length): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    generateKeyTable(key);
    playfairEncrypt(plaintext);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
