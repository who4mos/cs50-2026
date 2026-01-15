#include <cs50.h>
#include <stdio.h>

void print_bricks(int bricks);
void print_blanks(int blanks);
void print_row(int blanks, int bricks);

int main(void) {
    int h;

    do {
        h = get_int("Pyramid's height: ");
    } while (h <= 0 || h > 8);

    for (int i = 1; i <= h; i++) {
        int blanks = h - i;
        print_row(blanks, i);
    }
}

void print_bricks(int bricks) {
    for (int i = 0; i < bricks; i++) {
        printf("#");
    }
}

void print_blanks(int blanks) {
    for (int i = 0; i < blanks; i++) {
        printf(" ");
    }
}

void print_row(int blanks, int bricks) {
    print_blanks(blanks);
    print_bricks(bricks);
    printf("  ");
    print_bricks(bricks);
    printf("\n");
}
