#include <stdio.h>

int main() {
  int n, i, num;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    if (num % 2 == 0) {
      printf("%d is even\n", num);
    } else {
      printf("%d is odd\n", num);
    }
  }
  return 0;
}