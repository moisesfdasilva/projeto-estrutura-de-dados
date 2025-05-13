#include <stdio.h>

enum Gender { MALE, FEMALE, OTHER };

typedef struct {
  char name[50];
  enum Gender gender;
} Person;

int main(void) {
  Person person = { "Alice", FEMALE };

  printf("Name: %s, Gender: %d\n", person.name, person.gender);

  return 0;
}