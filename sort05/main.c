#include <stdio.h>

void heapfy(int array[], int i, int len) {
  int max = i;
  int childA = 2 * i + 1;
  int childB = 2 * i + 2;

  if((childA < len) && (array[childA] > array[i])) {
    max = childA;
  }

  if((childB < len) && (array[childB] > array[max])) {
    max = childB;
  }

  if(max != i) {
    int temp = array[i];
    array[i] = array[max];
    array[max] = temp;

    heapfy(array, max, len);
  }
}

void buildMaxHeap(int array[], int len) {
  for(int i = ((len - 2) / 2); i >= 0; i--) {
    heapfy(array, i, len);
  }
}

void heapSort(int array[], int len) {
  buildMaxHeap(array, len);

  for(int i = (len - 1); i > 0; i--) {
    int temp = array[i];
    array[i] = array[0];
    array[0] = temp;

    heapfy(array, 0, i);
  }
}

int main(void) {
  int nums[] = { 8, 5, 6, 9, 10, 1, 4, 3, 7, 2, 12, 11 };
  int len = sizeof(nums) / sizeof(nums[0]);

  heapSort(nums, len);

  for(int i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  return 0;
}