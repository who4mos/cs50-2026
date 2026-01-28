#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
bool is_simple_punct(char c);

int main(int argc, string argv[]) {
    string text = get_string("Text: ");
    
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;
    float index = round(0.0588 * l - 0.296 * s - 15.8);
  
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", (int) index);
    }
  
    return 0;
}

int count_letters(string text) {
    int letters = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i]))
            letters++;
    }

    return letters;
}

int count_words(string text) {
    int words = 0;
    bool in_word = false;
    
    for (int i = 0; text[i] != '\0'; i++) {

        if (isalpha(text[i]) && !in_word) {
            words++;
            in_word = true;
        } else if ((text[i] == '-' || text[i] == '\'') && in_word) {
            continue;
        } else if (!isalpha(text[i])) {
            in_word = false;
        }
    }

    return words;
}

int count_sentences(string text) {
    int sentences = 0;
    bool in_punct = false;

    for (int i = 0; text[i] != '\0'; i++) {
        if (is_simple_punct(text[i]) && !in_punct) {
            sentences++;
            in_punct = true;
        } else if (!ispunct(text[i])) {
            in_punct = false;
        }
    }

    return sentences;
}

bool is_simple_punct(char c) {
    return (c == '.' || c == '!' || c == '?');
}
