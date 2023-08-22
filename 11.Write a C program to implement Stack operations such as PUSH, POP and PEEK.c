#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int stack[MAXSIZE];
int top = -1;

void push(int data) {
  if (top >= MAXSIZE - 1) {
    printf("Stack overflow.\n");
    return;
  }

  stack[++top] = data;
}

int pop() {
  if (top < 0) {
    printf("Stack underflow.\n");
    return -1;
  }

  return stack[top--];
}

int peek() {
  if (top < 0) {
    printf("Stack is empty.\n");
    return -1;
  }

  return stack[top];
}

int main() {
  push(5);
  push(10);
  push(15);

  printf("Top element: %d\n", peek());

  printf("Elements: ");
  while (top >= 0) {
    printf("%d ", pop());
  }
  
  return 0;
}