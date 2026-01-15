#include <cs50.h>
#include <stdio.h>

int sum_digits(int n);
int n_digits(long n);
bool checksum(long n);
string card_type(long n);
 
int main(void) {
  long number;

  do {
    number = get_long("Number: ");
  } while (number < 0);
  
  if (checksum(number)) {
    printf("%s\n", card_type(number));
  } else {
    printf("INVALID\n");
  }

}

int sum_digits(int n) {
  int sum = 0;
  
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}

int n_digits(long n) {
  int count = 0;

  do {
    count++;
    n /= 10;
  } while (n > 0);
  
  return count;
}

bool checksum(long n) {
  int step = 1;
  int sum = 0;

  while (n > 0) {
    if (step % 2 == 1) {
      sum += n % 10;
    } else {
      sum += sum_digits((n % 10) * 2);
    }

    n /= 10;
    step++;
  }
  
  return (sum % 10 == 0);
}


string card_type(long n) {
  int digits = n_digits(n);

  do {
    n /= 10;
  } while (n >= 100);

  if ((n == 34 || n == 37) && digits == 15) {
    return "AMEX";
  } else if ((n >= 51 && n <= 55) && digits == 16) {
    return "MASTERCARD";
  } else {
    n /= 10;
    if (n == 4 && (digits == 13 || digits == 16)) {
      return "VISA";
    }
  }
  return "INVALID";
}
