#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct BigInt {
    int data;
    struct BigInt* llink;
    struct BigInt* rlink;
} BigInt;


// PROTOTYPE FUNCTIONS
BigInt* char_to_bigint(char *digits, int len);
BigInt* add(BigInt **a_ptr, BigInt **b_ptr);
BigInt* insert_at_end(BigInt** head, int term);
BigInt* zero_longinteger(int len);
BigInt* insert_at_head(BigInt** head, int term);
BigInt* delete_lead_zeros(BigInt** head, int n);
void display(BigInt* start);


// ********************************************************************* //

// IRRELEVANT FUNCTION
void display(BigInt* start)
{
    BigInt* temp = start;

    while (temp->rlink != start) {
        printf("%d", temp->data);
        temp = temp->rlink;
        
    }
    printf("%d ", temp->data);
}

// TO SUBMIT FUNCTIONS 
BigInt* insert_at_end(BigInt** head, int term){
    BigInt* input = (BigInt*) malloc(sizeof(BigInt));

    input->data = term;

    (*head)->llink->rlink = input;
    input->rlink = (*head);

    input->llink = (*head)->llink;
    (*head)->llink = input;
}

BigInt* zero_longinteger(int len){
    BigInt* head = (BigInt*) malloc(sizeof(BigInt));

    head->data = len;
    head->llink = head;
    head->rlink = head;

    return head;
}

BigInt* char_to_bigint(char *digits, int len) {

    BigInt* head = zero_longinteger(-1);

    while(*digits != '\0'){
        insert_at_end(&head, (int)(*digits-48));
        *digits++;
    }

    return head;
}

BigInt* insert_at_head(BigInt** head, int term){
    BigInt* newNode = (BigInt*) malloc(sizeof(BigInt));

    newNode->data = term;

    newNode->rlink = ((*head)->rlink);
    newNode->llink = (*head);
    ((*head)->rlink)->llink = newNode;
    (*head)->rlink = newNode;
}

BigInt* delete_lead_zeros(BigInt** head, int n){
    BigInt* curr = (BigInt*) malloc(sizeof(BigInt));

    curr = (*head)->rlink;

    while (curr != (*head)){
        if (curr->data == 0){
            BigInt* temp = (BigInt*) malloc(sizeof(BigInt));
            temp = curr->rlink;
            (*head)->rlink = temp;
            temp->llink = (*head);
            free(curr);
            n = n - 1;
            curr = (*head)->rlink;
        }

        else{
            return *head;
        }
    }
}

BigInt* add(BigInt **a_ptr, BigInt **b_ptr) {
    BigInt* S = zero_longinteger(0);
    int k = 0;
    int c = 0;
    int r = 10;
    int t, term;

    BigInt* a_curr = (*a_ptr)->llink;
    BigInt* b_curr = (*b_ptr)->llink;

    while(1){
        if (a_curr != *a_ptr && b_curr != *b_ptr){
            t = a_curr->data + b_curr->data + c;
            a_curr = a_curr->llink;
            b_curr = b_curr->llink;
        }

        else if (a_curr != *a_ptr && b_curr == *b_ptr){
            t = a_curr->data + c;
            a_curr = a_curr->llink;
        }

        else if (a_curr == *a_ptr && b_curr != *b_ptr){
            t = b_curr->data + c;
            b_curr = b_curr->llink;
        }

        else if (a_curr == *a_ptr && b_curr == *b_ptr){
            if (c != 0){
                insert_at_head(&S, c);
                k = k + 1;
            }

            else{
                delete_lead_zeros(&S, k);                
            }
            return S;
        }

        term = t % r;
        insert_at_head(&S, term);
        c = floor(t/r);
        k = k + 1;
    }
}

int main() {
    int Alen, Blen;
    char* a1;
    char* b1;

    char a[1001];
    char b[1001];

    scanf("%s", &a);
    scanf("%s", &b);
    
    a1 = a;
    b1 = b;

    Alen = strlen(a);
    Blen = strlen(b);

    // CONVERT STRING INPUT TO CIRCULAR DOUBLY LINKED LIST
    BigInt* aptr = char_to_bigint(a1, Alen);
    BigInt* bptr = char_to_bigint(b1, Blen);

    // DISPLAY OF OUTPUT FOR DOUBLY LINKED LIST
    // display(aptr);
    // printf("\n");
    // display(bptr);
    // printf("\n");

    // DISPLAY OF OUTPUT FOR SUM
    BigInt* afinal = add(&aptr, &bptr);
    display(afinal);

    return 0;
}