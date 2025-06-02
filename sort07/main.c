#include <stdio.h>

void countingSort(int array[], int len) {
  int max = array[0];
  int i, j, count;

  for(i = 1; i < len; i++) {
    if(max < array[i]) {
      max = array[i];
    }
  }

  int countArray[max];

  for(i = 0; i <= max; i++) {
    count = 0;

    for(j = 0; j < len; j++) {
      if(i == array[j]) {
        count++;
      }
    }

    countArray[i] = count;
  }

  i = 0, j = 0;
  while(i <= max) {
    if(countArray[i] < 1) {
      i++;
    } else {
      array[j] = i;
      countArray[i]--;
      j++;
    }
  }
}

int main(void) {
  int nums[] = { 8, 5, 6, 9, 10, 1, 4, 3, 7, 2, 12, 11 };
  int len = sizeof(nums) / sizeof(nums[0]);

  countingSort(nums, len);

  for(int i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  return 0;
}