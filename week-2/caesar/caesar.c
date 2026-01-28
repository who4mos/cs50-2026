#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool only_digits(string text);
int str_to_int(string text);
char rotate(char c, int k);

int main(int argc, string argv[]) {
    if (argc != 2 || !only_digits(argv[1])) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int k = str_to_int(argv[1]);

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        printf("%c", rotate(plaintext[i], k));
    }
    printf("\n");
    
    return 0;
}

bool only_digits(string text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }

    return true;
}

int str_to_int(string text) {
    if (!only_digits(text))
        return 0;

    int n = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        n = (n * 10) + (text[i] - '0');
    }

    return n;
}

char rotate(char c, int k) {
    if (!isalpha(c)) {
        return c;
    } else if (islower(c)) {
        return (c - 'a' + k) % 26 + 'a';
    } else {
        return (c - 'A' + k) % 26 + 'A';
    }
}
