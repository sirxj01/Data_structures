#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int queue[MAXSIZE];
int front = -1, rear = -1;

void enqueue(int data) {
  if (rear == MAXSIZE - 1) {
    printf("Queue overflow.\n");
    return;
  }

  if (front == -1) {
    front = 0;
  }

  queue[++rear] = data;
}

int dequeue() {
  if (front == -1 || front > rear) {
    printf("Queue underflow.\n");
    return -1;
  }

  return queue[front++];
}

void display() {
  if (front == -1 || front > rear) {
    printf("Queue is empty.\n");
    return;
  }

  printf("Queue elements: ");
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  int choice, data;

  while (1) {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the data to enqueue: ");
        scanf("%d", &data);
        enqueue(data);
        break;
      case 2:
        data = dequeue();
        if (data != -1) {
          printf("Element dequeued: %d\n", data);
        }
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}