#include <cs50.h>
#include <stdio.h>

int main(void) {
    int change, total_coins;
    int c25, c10, c5, c1;
    
    do {
        change = get_int("Change owed: ");
    } while (change <= 0);

    c25 = change / 25;
    change %= 25;

    c10 = change / 10;
    change %= 10;

    c5 = change / 5;
    change %= 5;

    c1 = change;

    total_coins = c25 + c10 + c5 + c1;
    printf("%d\n", total_coins);
}
