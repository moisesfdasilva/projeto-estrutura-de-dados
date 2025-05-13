#include <stdio.h>

int main(void) {
  int a = 10; //Data Variable
  int *p; //Pointer or Address Variable
  p = &a; //Initializing Pointer Variable
  printf("%d \n", *p); //*means deferencing
  printf("%p \n", p); //*address variable

  return 0;
}