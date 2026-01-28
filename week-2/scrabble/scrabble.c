#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(int argc, string argv[]) {
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int p1 = compute_score(word1);
    int p2 = compute_score(word2);

    if (p1 > p2) {
        printf("Player 1 wins!\n");
    } else if (p2 > p1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(string word) {
    int sum = 0;
  
    for (int i = 0, n = strlen(word); i < n; i++) {
        if (islower(word[i])) {
            sum += POINTS[word[i] - 'a'];
        } else if (isupper(word[i])) {
            sum += POINTS[word[i] - 'A'];
        }
    }

    return sum;
}
