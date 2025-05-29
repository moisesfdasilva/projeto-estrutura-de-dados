#include <stdio.h>

void merge(int array[], int len, int arrayOne[], int lenOne, int arrayTwo[], int lenTwo) {
  int topOne = 0, topTwo = 0;

  for(int i = 0; i < len; i++) {
    if(topOne >= lenOne) {
      array[i] = arrayTwo[topTwo];
      topTwo++;
    } else if(topTwo >= lenTwo) {
      array[i] = arrayOne[topOne];
      topOne++;
    } else if(arrayOne[topOne] < arrayTwo[topTwo]) {
      array[i] = arrayOne[topOne];
      topOne++;
    } else {
      array[i] = arrayTwo[topTwo];
      topTwo++;
    }
  }
}

void mergeSort(int array[], int len) {
  if(len > 1) {
    int midIndex = len / 2;
    int lenTwo = len - midIndex;
    int arrayOne[midIndex], arrayTwo[lenTwo], i;

    for(i = 0; i < midIndex; i++) {
      arrayOne[i] = array[i];
    }

    for(i = 0; i < lenTwo; i++) {
      arrayTwo[i] = array[midIndex + i];
    }

    mergeSort(arrayOne, midIndex);
    mergeSort(arrayTwo, (len - midIndex));

    merge(array, len, arrayOne, midIndex, arrayTwo, lenTwo);
  }
}

int main(void) {
  int nums[] = { 8, 5, 6, 9, 10, 1, 4, 3, 7, 2, 12, 11 };
  int len = sizeof(nums)/sizeof(nums[0]);

  mergeSort(nums, len);

  for(int i = 0; i < len; i++) {
    printf("%d\n", nums[i]);
  }

  return 0;
}