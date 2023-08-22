 	#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

// Insertion at the beginning of the list
void insertAtBeginning(int data) {
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

// Insertion at the end of the list
void insertAtEnd(int data) {
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  struct node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
}

// Insertion after a given node
void insertAfterNode(struct node *prevNode, int data) {
  if (prevNode == NULL) {
    printf("Previous node cannot be NULL.\n");
    return;
  }

  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

// Deletion at the beginning of the list
void deleteAtBeginning() {
  if (head == NULL) {
    printf("List is already empty.\n");
    return;
  }

  struct node *temp = head;
  head = head->next;
  free(temp);
}

// Deletion at the end of the list
void deleteAtEnd() {
  if (head == NULL) {
    printf("List is already empty.\n");
    return;
  }

  if (head->next == NULL) {
    free(head);
    head = NULL;
    return;
  }

  struct node *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }

  free(current->next);
  current->next = NULL;
}

// Deletion of a given node
void deleteNode(struct node *prevNode) {
  if (prevNode == NULL || prevNode->next == NULL) {
    printf("Previous node cannot be NULL or last node.\n");
    return;
  }

  struct node *temp = prevNode->next;
  prevNode->next = temp->next;
  free(temp);
}

// Displaying the list
void displayList() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct node *current = head;

  printf("List: ");
  
   while(current != NULL){
      printf("%d ", current -> data);
      current=current -> next; 
   }
   printf("\n");
}

int main() {

   insertAtBeginning(5);
   insertAtBeginning(10);
   insertAtEnd(15);
   insertAfterNode(head,20);
   displayList();
   deleteAtBeginning();
   deleteAtEnd();
   deleteNode(head);
   displayList();

   return 0;

}