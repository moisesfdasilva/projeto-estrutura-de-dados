#include <stdio.h>

void insertionSort(int array[], int len) {
  int i, j, temp;

  for(i = 1; i < len; i++) {
    for(j = i; j > 0; j--) {
      if(array[j] < array[j - 1]) {
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      } else {
        break;
      }
    }
  }
}

int main(void) {
  int nums[] = { 8, 5, 6, 9, 10, 1, 4, 3, 7, 2 };
  int len = sizeof(nums)/sizeof(nums[0]);

  insertionSort(nums, len);

  for(int i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  return 0;
}