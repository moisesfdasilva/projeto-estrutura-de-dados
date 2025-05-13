#include <stdio.h>
#include <string.h>

enum Color { RED, GREEN, BLUE };

void printColor(enum Color color) {
  char colorName[20];

  switch (color) {
    case RED:
      strcpy(colorName, "Red\n");
      break;
    case GREEN:
      strcpy(colorName, "Green\n");
      break;
    case BLUE:
      strcpy(colorName, "Blue\n");
      break;
    default:
      strcpy(colorName, "Unknow color\n");
  }

  printf("%s", colorName);
}

int main(void) {
  enum Color color = BLUE;
  printColor(color);
  return 0;
}
