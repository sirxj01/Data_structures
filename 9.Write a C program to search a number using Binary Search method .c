#include <stdio.h>

int main() {
  int arr[100], n, i, search, first, last, middle;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter the elements of the array in ascending order:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the element to be searched: ");
  scanf("%d", &search);

  first = 0;
  last = n - 1;
  middle = (first + last) / 2;

  while (first <= last) {
    if (arr[middle] < search) {
      first = middle + 1;
    } else if (arr[middle] == search) {
      printf("%d is present at location %d.\n", search, middle + 1);
      break;
    } else {
      last = middle - 1;
    }

    middle = (first + last) / 2;
  }

  if (first > last) {
    printf("%d is not present in the array.\n", search);
  }

  return 0;
}