#include <stdio.h>;

typedef struct {
  int length;
  int breadth;
  int area;
} Rectangle;

int main(void) {
  Rectangle rectangle = {10, 5};

  rectangle.area = rectangle.length * rectangle.breadth;

  printf("Rectangle: lenght %dcm, breadth %dcm, area %dcm2 \n", rectangle. length,
  rectangle.breadth, rectangle.area);

  return 0;
}