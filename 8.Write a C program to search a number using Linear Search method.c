#include <stdio.h>

int main() {
  int arr[100], n, i, search;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter the elements of the array:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the element to be searched: ");
  scanf("%d", &search);

  for (i = 0; i < n; i++) {
    if (arr[i] == search) {
      printf("%d is present at location %d.\n", search, i + 1);
      break;
    }
  }

  if (i == n) {
    printf("%d is not present in the array.\n", search);
  }

  return 0;
}