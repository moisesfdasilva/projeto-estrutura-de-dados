#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct something {
  int number;
  char text[20];
} Something;

void runtInt(void) {
  int *p = malloc(sizeof(int));;
  *p = 10;

  printf("\n   Integer:\n");
  printf("%d \n", *p);
  printf("%p \n", p);
}

void runtStructA(void) {
  struct something *someA = malloc(sizeof(struct something));

  (*someA).number = 1;
  strcpy((*someA).text, "Some text A.");

  printf("\n   Struct A:\n");
  printf("%d \n", (*someA).number);
  printf("%s \n", (*someA).text);
  printf("%p \n", someA);
}

void runtStructB(void) {
  Something *someB = malloc(sizeof(struct something));

  (*someB).number = 1;
  strcpy((*someB).text, "Some text B.");

  printf("\n   Struct B(typedef):\n");
  printf("%d \n", (*someB).number);
  printf("%s \n", (*someB).text);
  printf("%p \n", someB);
}

void runtStructC(void) {
  Something *someC = malloc(sizeof(struct something));

  someC->number = 1;
  strcpy(someC->text, "Some text C.");

  printf("\n   Struct C(typedef):\n");
  printf("%d \n", someC->number);
  printf("%s \n", someC->text);
  printf("%p \n", someC);
}

int main(void) {
  runtInt();

  runtStructA();
  runtStructB();

  return 0;
}