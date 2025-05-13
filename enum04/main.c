#include <stdio.h>

typedef enum { ADD, SUBTRACT, MULTIPLY, DIVIDE } Operation;

int main(void) {
  Operation operation = ADD;

  printf("Operation: %d\n", operation);

  return 0;
}