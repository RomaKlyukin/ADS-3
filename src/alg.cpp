// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  int left = 0;
  int right = size - 1;
  int sc = 1;
  int k = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      k = 1;
      while (true) {
        if (arr[mid] == arr[mid + sc]) {
          k++;
          sc++;
        } else {
          break;
        }
      }
      sc = 1;
      while (true) {
        if (arr[mid] == arr[mid - sc]) {
          k++;
          sc++;
        } else {
          break;
        }
      }
      return k;

    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return k;
}
