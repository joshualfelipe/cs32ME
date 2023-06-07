#include <stdio.h>
#include <ctype.h>
#include <string.h>

// EMPTY SPACES AFTER THE WORDS

void onlyAlphabets(char arr[100]);
void sortedArray(int length, char arr[length]);
void display(int length, char arr[length]);


int main(){
    char arr1[100];
    char arr2[100];    
    
    fgets(arr1, 100, stdin);
    onlyAlphabets(arr1);
    sortedArray(strlen(arr1), arr1);

    fgets(arr2, 100, stdin);
    onlyAlphabets(arr2);
    sortedArray(strlen(arr2), arr2);

    int flag = 1;
    for (int i = 0; i < strlen(arr1); i++){
        if(arr1[i] != arr2[i]){
            printf("No");
            flag = 0;
            break;
        }
    }

    if (flag == 1){
        printf("Yes");
    }
    
    return 0;
}

void onlyAlphabets(char arr[100]){
    // Removes non-alphabet characters and stores values to tempArray 
    int i = 0;
    int j = 0;

    while (i < 100){
        if (isalpha(arr[j])){
            arr[i] = tolower(arr[j]);
            i++;
            j++;
        } 

        else if(arr[j] == '\0' && i != j){
            arr[i] = '\0';
            i++;
        }
        
        else if(arr[i] == '\0'){
          break;
        }
        
        else{
          while (arr[j] != '\0' && !(isalpha(arr[j]))){
            j++;
          }
            arr[i] = tolower(arr[j]);
            i++;
            j++;
        }
    }
}

void sortedArray(int length, char arr[length]){
    // Sorts the tempArray alphabetically 
    char tempCharacter;

    for (int i = 0; i < 100-1; i++){

        // IMPORTANT: Ignores the garbage values in the array
        if(arr[i] == '\0'){
            break;
        }
        
        for (int j = i + 1; j < 100; j++){

            // IMPORTANT: Ignores the garbage values in the array
            if(arr[j] == '\0'){
                break;
            }
            
            // Selection Sort Algorithm
            if (arr[i] > arr[j]){
                tempCharacter = arr[i];
                arr[i] = arr[j];
                arr[j] = tempCharacter;
            }
        }
    }
}


void display(int length, char arr[length]){
    for (int i = 0; i < length; i++){
        if (arr[i] == '\0'){
            break;
        }
        printf("%c", arr[i]);
    }
    printf("\n%d\n", length);
}
























// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// // TODO: FIX BUG ON ASSIGNMENT OF GARBAGE VALUES

// void sortedArray(int length, char arr[length], char* result){

//     // Removes non-alphabet characters and stores values to tempArray 
//     int i = 0;
//     int j = 0;

//     char tempArray[length];

//     while (i < 100){
//         if (isalpha(arr[j])){
//             tempArray[i] = tolower(arr[j]);
//             i++;
//             j++;
//         } 

//         else if(arr[j] == '\0'){
//             break;
//         }

//         else{
//             j++;
//             tempArray[i] = tolower(arr[j]);
//             i++;
//             j++;
//         }
//     }

//     // Sorts the tempArray alphabetically 
//     char tempCharacter;

//     for (int i = 0; i < 100-1; i++){

//         // IMPORTANT: Ignores the garbage values in the array
//         if(tempArray[i] == '\0'){
//             break;
//         }
        
//         for (int j = i + 1; j < 100; j++){

//             // IMPORTANT: Ignores the garbage values in the array
//             if(tempArray[j] == '\0'){
//                 break;
//             }
            
//             // Selection Sort Algorithm
//             if (tempArray[i] > tempArray[j]){
//                 tempCharacter = tempArray[i];
//                 tempArray[i] = tempArray[j];
//                 tempArray[j] = tempCharacter;
//             }
//         }
//     }

//     // Stores sorted values to result pointer 
//     for (int i = 0; i < strlen(tempArray); i++){
//         printf("%c", tempArray[i]);
//         if(arr[i] == '\0'){
//             break;
//         }
//         printf("%c", tempArray[i]);
//         result[i] = tempArray[i];
//     }
// }

// void display(int length, char arr[length]){
//     for (int i = 0; i < length; i++){
//         // if(arr[i] == '\0'){
//         //     break;
//         // }
//         printf("%c", arr[i]);
//     }
//     printf("\n");
// }

// int main(){
//     char arr1[100];
//     char r1[strlen(arr1)];
//     char arr2[100];
//     char r2[strlen(arr2)];
    

//     // fgets(arr1, 100, stdin);
//     // display(arr1);
//     // sortedArray(arr1, r1);
//     // display(r1);

//     // fgets(arr2, 100, stdin);
//     // display(arr2);
//     // sortedArray(arr2, r2);
//     // display(r2);
    
    
//     fgets(arr1, 100, stdin);
//     // printf("%d\n", strlen(arr1));
//     sortedArray(strlen(arr1), arr1, r1);
//     // display(strlen(arr1), r1);
//     printf("\n%d\n", strlen(r1));

//     // fgets(arr2, 100, stdin);
//     // // printf("%d\n", strlen(arr2));
//     // sortedArray(strlen(arr2), arr2, r2);
//     // // display(strlen(arr2), r2);
//     // printf("%d\n", strlen(r2));

//     // sortedArray(arr1, r1);
//     // display(r1);
//     // sortedArray(arr2, r2);
//     // display(r2);

//     int flag = 1;
//     for (int i = 0; i < 100; i++){
//         if(r1[i] != r2[i]){
//             printf("No");
//             flag = 0;
//             break;
//         }
//     }

//     if (flag == 1){
//         printf("Yes");
//     }
    
//     return 0;
// }