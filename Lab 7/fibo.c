#include <string.h>
#include<stdlib.h>
#include <stdio.h>

int makeFibo(int fib[], int n){
    fib[1] = 0;
    fib[2] = 1;

    int fib_counter = 3;
    while(fib[fib_counter - 1] <= n){
        fib[fib_counter] = fib[fib_counter-1] + fib[fib_counter-2];
        fib_counter++;
    }

    return fib_counter;
}

void checkArr(int arr[], int fib[], int K, int index, int n){
    int i = fib[index];
    int m = fib[index + 1] - 1 - n;
    if (K > arr[i]){
        i = i - m;
    }
        // printf("%d", i);
    int p = fib[index - 1];
    int q = fib[index - 2];

    while(1){
        // printf("%d %d %d\n", i, p, q);
        int num = arr[i];
        printf("Current key: %d\n", num);
        if (K == num){
            printf("key found at position: %d\n", i);
            break;
        }

        else if (K < num){
            if (q == 0){
                printf("key not found\n");
                break;
            }
            else{
                i = i - q;
                int t;
                t = p;
                p = q;
                q = t - q;
            }
        }

        else{
            if(p == 1){
                printf("key not found\n");
                break;
            }
            else{
                i = i + q;
                p = p - q;
                q = q - p;
            }
        }
    }
}


int main(){

    int n, K;
    char arr[100000];
    int arrInt[100000];

    scanf("%d\n", &n);
    fgets(arr, 100000, stdin);
    scanf("%d", &K);

    // String to int array
    char *individual_inputs = strtok(arr, " ");
    int counter = 1;
	while(individual_inputs != NULL){
		int converted_num = atoi(individual_inputs);

		arrInt[counter] = converted_num;
		individual_inputs = strtok(NULL, " ");
		counter++;
    }
    
    // Create Fibo Array 
    int fib[100000];
    int fib_counter = makeFibo(fib, n);

    int index;

    for (int i = fib_counter - 1; i > 0; i--){
        if (fib[i] <= n){
            index = i;
            break;
        } 
    }  

    // printf("%d\n", index);
    checkArr(arrInt, fib, K, index, n);

    return 0;
}