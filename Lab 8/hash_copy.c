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

// MAIN FUNCTION
int main(){
    // LIST HEAD
    Node* head = (Node*) malloc(sizeof(Node));
    strcpy(head->data, "NULL");
    head->hash = -1;
    head->rlink = NULL;

    int h, n, m = 32;

    scanf("%d", &h);
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        // GET INPUT FROM USER
        char string[11];
        scanf("%s", string);

        // CONVERT STRING TO ASCII SUM
        int k = convert_to_ascii(string);
        printf("%d\n", k);

        // COMPUTE HASH VALUE
        int pos;
        if(h == 1) pos = k % 32;

        else if(h == 2){
            int x = pow(2,11);
            pos = ((31 * k) % x) >> (11 - 5);
        }
        else if(h == 3) pos = (((1731 * k + 520123) % 524287) % 32);

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
    return 0;
}