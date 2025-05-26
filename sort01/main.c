#include <stdio.h>

void boobleSort(int array[], int len) {
  int i, j, sub;
  for(i = 0; i < len; i++){
    for(j = 1; j < (len - i); j++){
      if(array[j-1] > array[j]){
        sub = array[j-1];
        array[j-1] = array[j];
        array[j] = sub;
      }
    }
  }
}

int main(void) {
  int nums[] = { 8, 5, 6, 9, 10, 1, 4, 3, 7, 2 };
  int len = sizeof(nums)/sizeof(nums[0]);

  boobleSort(nums, len);

  for(int i = 0; i < 10; i++){
    printf("%d\n", nums[i]);
  }

  return 0;
}