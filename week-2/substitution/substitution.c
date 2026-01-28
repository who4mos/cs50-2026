#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char substitute(char c, string key);

int main(int argc, string argv[]) {
    // input handling
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    } else if (strlen(argv[1]) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // transform key in lower case
    string key = argv[1];
    for (int i = 0; key[i] != '\0'; i++) {
        key[i] = tolower(key[i]);
    }

    // create an array to see if each letter was already typed
    bool letter_check[26];
    for (int i = 0; i < 26; i++) {
        letter_check[i] = false;
    }
    
    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha(key[i])) {
            // if not a letter, exit
            printf("Key must contain only letters.\n");
            return 1;
        }

        if (!letter_check[key[i] - 'a']) {
            // if letter was not already checked, check it
            letter_check[key[i] - 'a'] = true;
        } else {
            // if it was already checked, it is duplicated, exit
            printf("Key must not contain duplicated letters.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext:  ");


    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        printf("%c", substitute(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

char substitute(char c, string key) {
    if (!isalpha(c)) {
        return c;
    } else if (islower(c)) {
        return tolower(key[c - 'a']);
    } else {
        return toupper(key[c - 'A']);
    }
}
