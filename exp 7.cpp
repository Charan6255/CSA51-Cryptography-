#include <stdio.h>
#include <string.h>

char substitutionTable[26] = {
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 
    'X', 'C', 'V', 'B', 'N', 'M'
};

void monoalphabeticEncrypt(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = substitutionTable[text[i] - 'A'];
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = substitutionTable[text[i] - 'a'] + 32;
    }
}

int main() {
    char text[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    monoalphabeticEncrypt(text);
    printf("Encrypted text: %s\n", text);

    return 0;
}
