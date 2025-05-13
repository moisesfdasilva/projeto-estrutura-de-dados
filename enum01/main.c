#include <stdio.h>

enum Color { RED, GREEN, BLUE };
enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
enum StatusCode { SUCCESS = 0, FAILURE = -1, RUNNING = 1 };

int main(void) {
  enum Color myColor;
  enum Day today;
  enum StatusCode code;

  myColor = RED;
  today = TUESDAY;
  code = SUCCESS;

  printf("My color is %d\n", myColor);
  printf("Today is %d\n", today);
  printf("This status code is %d\n", code);

  return 0;
}