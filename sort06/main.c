#include <stdio.h>

int partition(int array[], int low, int high) {
  int pivotValue = array[low]; // median-of-three method (first, or mid, or last)
  int leftIndex = high;
  int temp;

  for(int i = high; i > low; i--) {
    if(pivotValue < array[i]) {
      temp = array[i];
      array[i] = array[leftIndex];
      array[leftIndex] = temp;

      leftIndex--;
    }
  }

  temp = array[low];
  array[low] = array[leftIndex];
  array[leftIndex] = temp;

  return leftIndex;
}

void quickSort(int array[], int low, int high) {
  if(low < high) {
    int pivotIndex = partition(array, low, high);

    quickSort(array, low, pivotIndex);
    quickSort(array, (pivotIndex + 1), high);
  }
}

int main(void) {
  int nums[] = { 8, 5, 6, 9, 10, 1, 4, 3, 7, 2, 12, 11 };
  int len = sizeof(nums) / sizeof(nums[0]);

  quickSort(nums, 0, (len - 1));

  for(int i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  return 0;
}