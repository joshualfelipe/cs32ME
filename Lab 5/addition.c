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
void insert_at_head(BigInt** head, int data);
void delete_lead_zeros(BigInt** head, int n);
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

// CREATES THE DOUBLY LINKED LIST
BigInt* insert_at_end(BigInt** head, int term){
    BigInt* input = NULL;

    input = (BigInt*) malloc(sizeof(BigInt));

    input->data = term;

    BigInt* temp = *head;

    input->rlink = temp->llink;

    while(temp->rlink != NULL){
        temp = temp->rlink;
    }

    temp->rlink = input;
    input->llink = temp;

}

// HEAD OF CIRCULAR DOUBLE LINKED LIST
BigInt* zero_longinteger(int len){
    BigInt* head = NULL;

    head = (BigInt*) malloc(sizeof(BigInt));

    head->data = len;
    head->llink = NULL;
    head->rlink = NULL;

    return head;
}

// TO SUBMIT FUNCTIONS 
BigInt* char_to_bigint(char *digits, int len) {

    BigInt* head = zero_longinteger(-1);

    for(int i=0; i<len; i++){
        char x = *(digits+i);
       
        // INSERT AT TAIL
        // CONVERTS EACH ELEMENT TO INT USING ASCII MANIPULATION
        insert_at_end(&head, (int)x-48);
    }

    // CONNECTS THE ENDS OF THE DOUBLY LINKED LIST (CIRCULAR)
    BigInt* temp = head;

    while(temp->rlink != NULL){
        temp = temp->rlink;
    }

    head->llink = temp;
    temp->rlink = head;

    return head;
}

void insert_at_head(BigInt** head, int data){
     // allocate memory for newNode
    struct BigInt* newNode = NULL;
    newNode = (BigInt*) malloc(sizeof(BigInt));

    // assign data to newNode
    newNode->data = data;

    // point next of newNode to the first node of the doubly linked list
    newNode->rlink = (*head);

    // point prev to NULL
    newNode->llink = NULL;

    // point previous of the first node (now first node is the second node) to newNode
    if ((*head) != NULL)
        (*head)->llink = newNode;

    // head points to newNode
    (*head) = newNode;
}

void delete_lead_zeros(BigInt** head, int n){
    BigInt* curr = (*head)->rlink;
    BigInt* s_head = (*head);

    while(curr != s_head){
        if ((*head)->data == 0){
            (*head)->rlink = curr->rlink;
            (*head)->llink = s_head;
            free(curr);
            n = n-1;
            curr = (*head)->rlink;
        }

        else{
            break;
        }
    }
}


BigInt* add(BigInt **a_ptr, BigInt **b_ptr) {
    int k = 0;
    int c = 0;
    int t;

    // ALPHA AND BETA (PSEUDOCODE)
    BigInt* a_curr = *a_ptr;
    BigInt* b_curr = *b_ptr;

    BigInt* a_head = *a_ptr;
    BigInt* b_head = *b_ptr;

    while(a_curr->rlink != a_head){
        a_curr = a_curr->rlink;
    }

    while(b_curr->rlink != b_head){
        b_curr = b_curr->rlink;
    }    

    BigInt* S_head = zero_longinteger(0);

    while(1){
        if (a_curr != a_head && b_curr != b_head){
            t = a_curr->data + b_curr->data + c;
            a_curr = a_curr->llink;
            b_curr = b_curr->llink;
        }

        else if (a_curr != a_head && b_curr == b_head){
            t = a_curr->data + c;
            a_curr = a_curr->llink;
        }

        else if (a_curr == a_head && b_curr != b_head){
            t = b_curr->data + c;
            b_curr = b_curr->llink;
        }

        else if (a_curr == a_head && b_curr == b_head){
            if (c != 0){
                insert_at_head(&S_head, c);
                k = k + 1;
            }

            else{
                printf("a");
                // REVERSING SUM DOUBLY-LINKED LIST
                BigInt *temp = NULL;  
                BigInt *current = S_head;
                while (current !=  NULL)
                {
                    temp = current->llink;
                    current->llink = current->rlink;
                    current->rlink = temp;              
                    current = current->llink;
                }      
                
                if(temp != NULL){
                    S_head = temp->llink; 
                }   

                
                delete_lead_zeros(&S_head, k);
                return S_head;
            }
            break;
        }

        int term = t % 10;
        insert_at_head(&S_head, term);
        c = floor(t/10);
        k = k + 1;
    }
    // REVERSING SUM DOUBLY-LINKED LIST
    BigInt *temp = NULL;  
    BigInt *current = S_head;
    while (current !=  NULL)
    {
        temp = current->llink;
        current->llink = current->rlink;
        current->rlink = temp;              
        current = current->llink;
    }      
    
    if(temp != NULL){
        S_head = temp->llink; 
    }   

    return S_head;
}


int main() {
    int Alen, Blen;

    char a[] = "92498988047678334552";
    Alen = strlen(a);
    char b[] = "96817198892297134829";
    Blen = strlen(b);

    char* a1;
    char* b1;

    a1 = a;
    b1 = b;

    // CONVERT STRING INPUT TO CIRCULAR DOUBLY LINKED LIST
    BigInt* aptr = char_to_bigint(a1, Alen);
    BigInt* bptr = char_to_bigint(b1, Blen);

    // DISPLAY OF OUTPUT
    display(aptr);
    printf("\n");
    display(bptr);
    printf("\n");

    
    BigInt* afinal = add(&aptr, &bptr);
    display(afinal);
    return 0;
}

/* 
References

Display: 
- https://www.geeksforgeeks.org/insertion-in-doubly-circular-linked-list/

Doubly Linked List:
- https://www.geeksforgeeks.org/insertion-in-doubly-circular-linked-list/
- https://www.programiz.com/dsa/doubly-linked-list

Arithmetic: 
- geeksforgeeks.org/large-number-arithmetic-using-doubly-linked-list/

Notion pages: 
- https://rbjuayong.notion.site/Applications-of-Linear-Lists-4354c686bf194d3090efe2fea15aac0b

Reversing Doubly Linked List: 
- https://www.geeksforgeeks.org/c-program-for-reversing-a-doubly-linked-list/#:~:text=Here%20is%20a%20simple%20method,head%20pointer%20in%20the%20end."


if ((*head)->llink == NULL){
        BigInt* input = NULL;
        input = (BigInt*) malloc(sizeof(BigInt));
        input->data = data;

        input->rlink = *head;
        input->llink = *head;

        (*head)->llink = input;
        (*head)->rlink = input;


        *head = input;
    }

    else{     
        BigInt* last = (BigInt*) malloc(sizeof(BigInt));
        last = ((*head)->rlink)->llink; 

        BigInt* new_node = NULL;
        new_node = (BigInt*) malloc(sizeof(BigInt));
        new_node->data = data;
        
        new_node->rlink = *head;
        new_node->llink = last;
        
        ((*head)->rlink)->llink= new_node;
        
        last->rlink = new_node; 

        *head = new_node;
    }

*/


/*----------------------------------------------------------------

// CREATES THE DOUBLY LINKED LIST (WORKING)
BigInt* insert_at_end(BigInt** head, int term){
    BigInt* input = NULL;

    input = (BigInt*) malloc(sizeof(BigInt));

    input->data = term;

    BigInt* temp = *head;

    input->rlink = temp->llink;

    while(temp->rlink != NULL){
        temp = temp->rlink;
    }

    temp->rlink = input;
    input->llink = temp;

}

// HEAD OF CIRCULAR DOUBLE LINKED LIST (WORKING)
BigInt* zero_longinteger(int len){
    BigInt* head = NULL;

    head = (BigInt*) malloc(sizeof(BigInt));

    head->data = len;
    head->llink = NULL;
    head->rlink = NULL;

    return head;
}

// TO SUBMIT FUNCTIONS (WORKING)
BigInt* char_to_bigint(char *digits, int len) {

    BigInt* head = zero_longinteger(-1);

    for(int i=0; i<len; i++){
        char x = *(digits+i);
       
        // INSERT AT TAIL
        // CONVERTS EACH ELEMENT TO INT USING ASCII MANIPULATION
        insert_at_end(&head, (int)x-48);
    }

    // CONNECTS THE ENDS OF THE DOUBLY LINKED LIST (CIRCULAR)
    BigInt* temp = head;

    while(temp->rlink != NULL){
        temp = temp->rlink;
    }

    head->llink = temp;
    temp->rlink = head;

    return head;
}

void insert_at_head(BigInt** head, int data){
    if ((*head)->llink == NULL){
        BigInt* input = NULL;
        input = (BigInt*) malloc(sizeof(BigInt));
        input->data = data;

        input->rlink = *head;
        input->llink = *head;

        (*head)->llink = input;
        (*head)->rlink = input;


        *head = input;
    }

    else{     
        BigInt* last = (BigInt*) malloc(sizeof(BigInt));
        last = ((*head)->rlink)->llink; 

        BigInt* new_node = NULL;
        new_node = (BigInt*) malloc(sizeof(BigInt));
        new_node->data = data;
        
        new_node->rlink = *head;
        new_node->llink = last;
        
        ((*head)->rlink)->llink= new_node;
        
        last->rlink = new_node; 

        *head = new_node;
    }
}

void delete_lead_zeros(BigInt** head, int n){
    BigInt* curr = (*head)->rlink;
    BigInt* s_head = (*head);

    while(curr != s_head){
        if ((*head)->data == 0){
            (*head)->rlink = curr->rlink;
            (*head)->llink = s_head;
            free(curr);
            n = n-1;
            curr = (*head)->rlink;
        }

        else{
            break;
        }
    }
}


BigInt* add(BigInt **a_ptr, BigInt **b_ptr) {
    int k = 0;
    int c = 0;
    int t;

    // ALPHA AND BETA (PSEUDOCODE)
    BigInt* a_curr = *a_ptr;
    BigInt* b_curr = *b_ptr;

    BigInt* a_head = *a_ptr;
    BigInt* b_head = *b_ptr;

    while(a_curr->rlink != a_head){
        a_curr = a_curr->rlink;
    }

    while(b_curr->rlink != b_head){
        b_curr = b_curr->rlink;
    }    

    BigInt* S_head = zero_longinteger(0);

    while(1){
        if (a_curr != a_head && b_curr != b_head){
            t = a_curr->data + b_curr->data + c;
            a_curr = a_curr->llink;
            b_curr = b_curr->llink;
        }

        else if (a_curr != a_head && b_curr == b_head){
            t = a_curr->data + c;
            a_curr = a_curr->llink;
        }

        else if (a_curr == a_head && b_curr != b_head){
            t = b_curr->data + c;
            b_curr = b_curr->llink;
        }

        else if (a_curr == a_head && b_curr == b_head){\
            if (c != 0){
                insert_at_head(&S_head, c);
                k = k + 1;
            }

            else{
                delete_lead_zeros(&S_head, k);
                return S_head;
            }
        }
        
        int term = t % 10;
        insert_at_head(&S_head, term);
        c = floor(t/10);
        k = k + 1;
    }
}
*/