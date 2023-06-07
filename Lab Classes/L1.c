#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

// A linked list node
typedef struct node {
  int data;
  struct node* next;
} node;

// Function to create a new node
struct node* new_node(int data) {
  struct node* n = malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  return n;
}

// Function to insert a new node at the head of the list
void insert_at_tail(struct node** head, int data) {
  struct node* n = new_node(data);
    struct node* temp = *head;


    if(temp == NULL) {
      temp = n;
      *head = temp;

    }

    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
            temp->next = n;
            *head = temp;
    }
}

// Function to insert a new node at the head of the list
void insert_at_head(struct node** head, int data) {
  struct node* n = new_node(data);
  n->next = *head;
  *head = n;
}

// Function to insert a new node after the given index
void insert_after(struct node* head, int data, int index) {
  int i;
  for (i = 0; i < index && head != NULL; i++) {
    head = head->next;
  }
  if (head == NULL) {
    // Index is out of range, do nothing
    return;
  }
  struct node* n = new_node(data);
  n->next = head->next;
  head->next = n;
}

// Function to delete the node at the given index
void delete_at(struct node** head, int index) {
  int i;
  struct node* prev = NULL;
  struct node* curr = *head;
  for (i = 0; i < index && curr != NULL; i++) {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL) {
    // Index is out of range, do nothing
    return;
  }
  if (prev == NULL) {
    // We are deleting the head of the list
    *head = curr->next;
  } else {
    prev->next = curr->next;
  }
  free(curr);
}

// Function to delete all nodes with the given data
void delete_all(struct node** head, int data) {
  struct node* prev = NULL;
  struct node* curr = *head;
  while (curr != NULL) {
    if (curr->data == data) {
      if (prev == NULL) {
        // We are deleting the head of the list
        *head = curr->next;
      } else {
        prev->next = curr->next;
      }
      struct node* temp = curr;
      curr = curr->next;
      free(temp);
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}

// Function to print the list
void print_list(struct node* head) {
  struct node* n = head;
  while (n != NULL) {
    printf("%d ", n->data);
    n = n->next;
  }
  printf("\n");
}


int main(){

    int N;
    scanf("%d", &N);

    node* head = (node*) malloc(sizeof(node));

    while(1){
        char str[10];
        scanf("%s", str);
        

        if (str[0] == '_'){
            break;
        }

        int val = atoi(str);
        printf("%d ", val);
        insert_at_tail(&head, val);
    }

    return 0;
}