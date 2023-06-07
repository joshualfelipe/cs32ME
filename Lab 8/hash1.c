#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Node{
    char data[11];
    int hash;
    struct Node* rlink;
} Node;

// PROTOTYPE FUNCTIONS
int f1(int k);
int f2(int k);
int f3(int k);
int convert_to_ascii(char string[]);
Node* right_of_head(Node* head, Node* new);

void displayList(Node* head);


// MAIN FUNCTION
int main(){
    // LIST HEAD
    Node* head = (Node*) malloc(sizeof(Node));
    strcpy(head->data, "NULL");
    head->hash = -1;
    head->rlink = NULL;

    int m = 32;
    int h, n;

    scanf("%d", &h);
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        // GET INPUT FROM USER
        char string[11];
        scanf("%s", string);

        // CONVERT STRING TO ASCII SUM
        int k = convert_to_ascii(string);

        // COMPUTE HASH VALUE
        int pos;
        if(h == 1){
            pos = f1(k);
        }

        else if(h == 2){
            pos = f2(k);
        }

        else if(h == 3){
            pos = f3(k);
        }

        // GETNODE
        Node* new = (Node*) malloc(sizeof(Node));

        // ADD VALUES TO NODE
        strcpy(new->data, string);
        new->hash = pos;
        new->rlink = NULL;

        // PUSH TO RIGHT OF LISTHEAD
        right_of_head(head, new);
    }

    // OUTPUT HASH TABLE
    for(int j = 0; j < 32; j++){
        printf("%d: ", j);

        Node* temp;
        temp = head->rlink;
        
        while(1){
            if(temp == NULL){
                break;
            }

            else if (temp->hash == j){
                printf("%s ", temp->data);
            }

            temp = temp->rlink;
        }

        printf("\n");
    }

    // DISPLAY LINKED LIST
    // displayList(head);
    return 0;
}

// HASH FUNCTIONS
int f1(int k){
    return k % 32;
}

int f2(int k){
    int x = pow(2,11);
    return ((31 * k) % x) >> (11 - 5);
}

int f3(int k){
    return (((1731 * k + 520123) % 524287) % 32);
}


// AUXILLARY FUNCTIONS
int convert_to_ascii(char string[]){
    int sum = 0;

    for(int i = 0; i < 10; i++){
        int val = (int) string[i];
        sum += val;
    }

    return sum;
}

Node* right_of_head(Node* head, Node* new){
    if(head->rlink == NULL){
        head->rlink = new;
    }

    else{
        Node* temp = (Node*) malloc(sizeof(Node));
        temp = head->rlink;

        head->rlink = new;
        new->rlink = temp;
    }

    return head;
}

void displayList(Node* head){
    Node* temp;
    temp = head->rlink;
    while(1){
        if(temp == NULL){
            printf("empty\n");
            break;
        }

        else{
            printf("%s\n", temp->data);
            temp = temp->rlink;
        }
    }
} 



// https://stackoverflow.com/questions/37225244/error-assignment-to-expression-with-array-type-error-when-i-assign-a-struct-f