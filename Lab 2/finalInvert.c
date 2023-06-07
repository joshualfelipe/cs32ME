#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node{
    int data;
    Node* next;
};

Node* BuildTwoThree();
void invert(Node **l_ptr);

int main(){
    Node* head = BuildTwoThree();
    printf("head->data: %d\n", head->data);
    printf("second->data: %d\n", (head->next)->data);
    printf("third->data: %d\n", ((head->next)->next)->data);
    printf("fourth->data: %d\n", (((head->next)->next)->next)->data);

    invert(&head);

    printf("head->data: %d\n", head->data);
    printf("second->data: %d\n", (head->next)->data);
    printf("third->data: %d\n", ((head->next)->next)->data);
    printf("fourth->data: %d\n", (((head->next)->next)->next)->data);

  
    return 0;
}

void invert(Node **l_ptr) {
    Node* new = NULL;
    new = (Node*) malloc(sizeof(Node));
    new->data = NULL;
    new->next = NULL;

    void helperFunc(Node *curr, Node *prev){
        if (curr == NULL){
            new = prev;
        }

        else{
            Node* temp = NULL;
            temp = (Node*) malloc(sizeof(Node));
            temp = prev;

            if (temp->data == NULL){
                prev->data = curr->data;
                prev->next = temp->next;
                helperFunc(curr->next, prev);
            }

            else{
                Node* new_prev = NULL;
                new_prev = (Node*) malloc(sizeof(Node));
                new_prev->data = curr->data;
                new_prev->next = temp;
                helperFunc(curr->next, new_prev);
            }
        }
    }

    helperFunc(*l_ptr, new);
    **l_ptr = *new;
}

Node* BuildTwoThree() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    head = (Node*) malloc(sizeof(Node));          // allocate 3 nodes in the heap
    second = (Node*) malloc(sizeof(Node));
    third = (Node*) malloc(sizeof(Node));
    fourth = (Node*) malloc(sizeof(Node));

    head->data = 1;          // setup first node
    head->next = second;     // note: pointer assignment rule

    second->data = 2;        // setup second node
    second->next = third;

    third->data = 3;         // setup third link
    third->next = fourth;

    fourth->data = 4;         // setup fourth link
    fourth->next = NULL;

    return head;
}
