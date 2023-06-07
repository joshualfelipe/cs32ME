#include <string.h>
#include<stdlib.h>
#include <stdio.h>


int main(){
    int n;
    char input[10000];
    char arr[10000];

    scanf("%d\n", &n);    
    
    int list[10000];
    fgets(input, 10000, stdin);
    char *individual_inputs = strtok(input, " ");

    int counter = 0;
	while(individual_inputs != NULL){
		int converted_num = atoi(individual_inputs);

		list[counter] = converted_num;
		individual_inputs = strtok(NULL, " ");
		counter++;
    }

    int arrange[10000];
    fgets(arr, 10000, stdin);
    char *individual_arrangement = strtok(arr, " ");

    int counter2 = 0;
	while(individual_arrangement != NULL){
        int converted_arrange = atoi(individual_arrangement);

		arrange[counter2] = converted_arrange;
		individual_arrangement = strtok(NULL, " ");
		counter2++;
	}


    for(int i = 0; i < n; i++){
        int temp;

        if (i != arrange[i]){
            temp = list[arrange[i]];
            list[arrange[i]] = list[i];
            list[i] = temp;
        }

        for(int j = 0; j < n; j++){
            printf("%d_", list[j]);
        }
        printf("\n");
    }


    return 0;
}