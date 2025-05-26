#include <stdio.h>

void selectionSort(int array[], int len) {
  int i, j, minValue, minIndex, sub;

  for(i = 0; i < len; i++) {
    minValue = array[i];

    for(j = (1 + i); j < len; j++) {
      if(minValue > array[j]) {
        minValue = array[j];
        minIndex = j;
      }
    }

    if(minValue != array[i]) {
      sub = array[i];
      array[i] = array[minIndex];
      array[minIndex] = sub;
    }
  }
}

int main(void) {
  int nums[] = { 8, 5, 6, 9, 10, 1, 4, 3, 7, 2 };
  int len = sizeof(nums)/sizeof(nums[0]);

  selectionSort(nums, len);

  for(int i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  return 0;
}