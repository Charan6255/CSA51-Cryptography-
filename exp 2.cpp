#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char keySquare[SIZE][SIZE];

void generateKeySquare(char key[]) {
    int used[26] = {0};
    int i, j = 0, k = 0;

    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I'; // Treat 'J' as 'I'
        if (!used[ch - 'A']) {
            keySquare[j / SIZE][j % SIZE] = ch;
            used[ch - 'A'] = 1;
            j++;
        }
    }

    // Fill remaining letters
    for (i = 0; i < 26; i++) {
        if (i != ('J' - 'A') && !used[i]) {
            keySquare[j / SIZE][j % SIZE] = 'A' + i;
            j++;
        }
    }
}


void printMatrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", keySquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char key[] = "MUSTSEEYOUOVERCADOGANWEST";
    generateKeySquare(key);
    printf("Playfair Key Square:\n");
    printMatrix();
    return 0;
}
