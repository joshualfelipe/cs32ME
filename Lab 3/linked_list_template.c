#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define newline printf("\n")

typedef struct node Node;
struct node{
	int data;
	Node* next;
};

//declare your functions here
void print_linked_list(Node *head);
void build_linked_list(Node **head_ptr);
int count(Node *head, int to_search);
int get_nth(Node *head, int index);
void free_node(Node *a_node);

int main(){

	Node *head = NULL;
	int index, nth;
	
	// build a linked list
	build_linked_list(&head);
	
	// optionally, you may want to print the list to make sure data is stored as desired
	// print_linked_list(head);
	
	// read index, find value at nth index, determine number of copies in the list
	while((scanf("%d",&index)>0) && (index != -1)){
		nth = get_nth(head, index);
		printf("%d %d %d\n", index, nth, count(head,nth));
	}

	// free the nodes
	free_node(head);
	return 0;
}


void print_linked_list(Node *head){
	Node *current;
	for(current=head; current != NULL; current = current->next){
		printf("%d ", current->data);
	}
	newline;
}

// TODO: Get user input for an array. Build linked list from end to start. 
void build_linked_list(Node **head_ptr){
	// Write your code here

	// Grabbing user input and storing individual inputs to an array 
	char input[10000];
	int list[10000];
	
	fgets(input, 10000, stdin);

	char *individual_inputs = strtok(input, " ");

	int num_elements = 0;
	int counter = 0;
	while(individual_inputs != NULL){
		int converted_num = atoi(individual_inputs);
		if (converted_num < 0){
			break;
		}
		list[counter] = converted_num;
		individual_inputs = strtok(NULL, " ");
		counter++;
		num_elements++;
	}

	// Creating new linked list

	Node *head, *new, *temp;
	new = (Node*) malloc(sizeof(Node));
	head = (Node*) malloc(sizeof(Node));

	int i = num_elements - 1;
	new->data = list[i];
	new->next = NULL;

	i--;

	head = new;
	temp = head;

	while(i >= 0){
		new = (Node*) malloc(sizeof(Node));
		new->data = list[i];
		new->next = NULL;

		temp->next = new;
		temp = temp->next;

		i--;
	}	

	// Stores head of linked list to head_ptr  
	*head_ptr = head;

}

int count(Node *head, int to_search){
	// Write your code here
	int helperFunc(Node *node, int i, int n){
		if (node == NULL){
			return n;
		}
		
		if (node->data == i){
			helperFunc(node->next, i, n+1);
		}

		else{
			helperFunc(node->next, i, n);
		}
	}

	return helperFunc(head, to_search, 0);
}

int get_nth(Node *head, int index){
	// Write your code here
	int helperFunc(Node *node, int i, int n){
		if (n == i){
			return node->data;
		}

		else{
			helperFunc(node->next, i, n+1);
		}
	}

	return helperFunc(head, index, 1);
}

void free_node(Node *a_node){
	if(a_node!=NULL){
		free_node(a_node->next);
		free(a_node);
	}
}