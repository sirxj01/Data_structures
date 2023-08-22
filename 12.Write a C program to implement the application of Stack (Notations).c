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

int main() {
  char notation[MAXSIZE];
  printf("Enter the notation: ");
  scanf("%s", notation);

  for (int i = 0; notation[i] != '\0'; i++) {
    if (notation[i] >= '0' && notation[i] <= '9') {
      push(notation[i] - '0');
    } else {
      int operand1 = pop();
      int operand2 = pop();

      switch (notation[i]) {
        case '+':
          push(operand2 + operand1);
          break;
        case '-':
          push(operand2 - operand1);
          break;
        case '*':
          push(operand2 * operand1);
          break;
        case '/':
          push(operand2 / operand1);
          break;
      }
    }
  }

  printf("Result: %d\n", pop());

  return 0;
}