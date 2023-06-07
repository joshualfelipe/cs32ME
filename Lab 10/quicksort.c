#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void shuffle_array(int shuffle[], int P, int M);
void convert_to_int(char charArr[], int intArr[]);
void shuffle_inputs(int shuffle[], int input[], int finalArr[], int M);
void quicksort(int A[], int p, int r, int M);
int partition(int A[], int p, int r, int M);
void print(int p, int r, int arr[]);

int main(){
    // int l = 10000001;
    // int M = 1000;
    // int P = 524287; 
    int l = 1001;
    int M = 8;
    int P = 13; 
    int T;

    scanf("%d\n", &T);    
    
    int storage[T][M + 1];

    // Pseudorandom shuffling array 
    int shuffle[M];
    shuffle_array(shuffle, P, M);

    for(int k = 0; k < T; k++){
        // Grabs testcase lines from user input
        char inputArray[l];
        int testcaseArray[M];
        fgets(inputArray, l, stdin);
        convert_to_int(inputArray, testcaseArray);

        // Shuffle inputs using pseudorandom
        int finalArray[M + 1];
        shuffle_inputs(shuffle, testcaseArray, finalArray, M);

        for(int m = 1; m <= M; m++){
            storage[k][m] = finalArray[m];
        }
    }

    for(int len = 0; len < T; len++){
        // Line 1 of output
        print(1, M + 1, storage[len]);

        // QuickSort Algorithm
        quicksort(storage[len], 1, M, M);

        // Last line of output
        print(1, M + 1, storage[len]);
    }
    return 0;
}

void shuffle_array(int shuffle[], int P, int M){
    for(int i = 0; i < M; i++){
        shuffle[i] = ((i + 1) * P) % M;
    }
}

void convert_to_int(char charArr[], int intArr[]){
    char *individual_inputs = strtok(charArr, " ");
    int counter = 0;
	while(individual_inputs != NULL){
		int converted_num = atoi(individual_inputs);
		intArr[counter] = converted_num;
		individual_inputs = strtok(NULL, " ");
		counter++;
    }
}

void shuffle_inputs(int shuffle[], int input[], int finalArr[], int M){
    for(int i = 0; i < M; i++){
        finalArr[i + 1] = input[shuffle[i]];
    }
}

void quicksort(int A[], int p, int r, int M){
    if (p < r){
        int q = partition(A, p, r, M);
        quicksort(A, p, q - 1, M);
        quicksort(A, q + 1, r, M);
    }
}

int partition(int A[], int p, int r, int M){
    int x = A[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; j++){
        if (A[j] <= x){
            i = i + 1;
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }

    int temp2 = A[r];
    A[r] = A[i + 1];
    A[i + 1] = temp2;

    // Line by line output
    print(p, r + 1, A);

    return i + 1;
}

void print(int p, int r, int arr[]){
    for(int i = p; i < r; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}