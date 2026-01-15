#include <cs50.h>
#include <stdio.h>

void print_row(int blanks, int bricks);

int main(void) {
    int h;

    do {
        h = get_int("Pyramid's height: ");
    } while (h <= 0);

    for (int i = 1; i <= h; i++) {
        int blanks = h - i;
        print_row(blanks, i);
    }
}

void print_row(int blanks, int bricks) {
    for (int i = 0; i < blanks; i++) {
        printf(" ");
    }
    
    for (int i = 0; i < bricks; i++) {
        printf("#");
    }

    printf("\n");
}
