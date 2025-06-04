#include <stdio.h>

int factorial(int num) {
  if(num < 0) {
    return 0;
  } else if(num <= 1) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

int main(void) {
  int number = 5;
  int factNumber = factorial(number);

  printf("factorial of %d is %d\n", number, factNumber);

  return 0;
}