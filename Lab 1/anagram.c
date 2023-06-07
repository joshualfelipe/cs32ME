#include <stdio.h>
#include <ctype.h>
#include <string.h>

void linearSorting(char arr[100], char* result){
    char temp;

    for (int i = 0; i < 100-1; i++){
        if(arr[i] == '\0'){
            break;
        }

        for (int j = i + 1; j < 100; j++){
            if(arr[j] == '\0'){
                break;
            }

            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 100; i++){
        if(arr[i] == '\0'){
            break;
        }
        result[i] = arr[i];
    }
}

void onlyAlphabets(char arr[100], char* result){
    int i = 0;
    int j = 0;

    while (i < 100){
        if (isalpha(arr[j])){
            result[i] = tolower(arr[j]);
            i++;
            j++;
        } 

        else if(arr[j] == '\0'){
            break;
        }

        else{
            j++;
            result[i] = tolower(arr[j]);
            i++;
            j++;
        }
    }
}


void sortedArray(char arr[100], char* result){
    int i = 0;
    int j = 0;

    char tempArray[100];

    while (i < 100){
        if (isalpha(arr[j])){
            tempArray[i] = tolower(arr[j]);
            i++;
            j++;
        } 

        else if(arr[j] == '\0'){
            break;
        }

        else{
            j++;
            tempArray[i] = tolower(arr[j]);
            i++;
            j++;
        }
    }
    
    for (int i = 0; i < 100; i++){
        result[i] = tempArray[i];
    }

    char tempCharacter;

    for (int i = 0; i < 100-1; i++){
        if(tempArray[i] == '\0'){
            break;
        }
        for (int j = i + 1; j < 100; j++){

            if(tempArray[j] == '\0'){
                break;
            }
            
            if (tempArray[i] > tempArray[j]){
                tempCharacter = tempArray[i];
                tempArray[i] = tempArray[j];
                tempArray[j] = tempCharacter;
            }
        }
    }

    for (int i = 0; i < 100; i++){
        result[i] = tempArray[i];
    }
}



void display(char arr[100]){
    for (int i = 0; i < 100; i++){
        if(arr[i] == '\0'){
            break;
        }
        printf("%c", arr[i]);
    }
}

int main(){
    char arr1[100] = "anagram";
    char r1[100];
    char arr2[100] = "nag a ram";
    char r2[100];
    
    fgets(arr1, 100, stdin);
    fgets(arr2, 100, stdin);

    // Remove all unnecessary characters
    // onlyAlphabets(arr1, r1);
    // onlyAlphabets(arr2, r2);

    // display(r1);
    // printf("\n");
    // display(r2);
    // printf("\n");


    // linearSorting(r1, rf1);
    // linearSorting(r2, rf2);

    // display(rf1);
    // printf("\n");
    // display(rf2);

    sortedArray(arr1, r1);
    // display(r1);
    // printf("\n");
    sortedArray(arr2, r2);
    // display(r2);

    int flag = 1;
    for (int i = 0; i < 100; i++){
        if(r1[i] != r2[i]){
            printf("No");
            flag = 0;
            break;
        }
    }

    if (flag == 1){
        printf("Yes");
    }
    // linearSorting(r2, rf2);
    // display(rf2);
    return 0;
}