#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct par{
	char value;
	int index;
};

int check_previous(char previous, char expected);

int main(){

    // struct par arr[100001];
    // char input[100001];

    // fgets(input, 100001, stdin);

    struct par arr[6];
    char input[6] = "[]({}";

    if (strlen(input) == 2 && (input[0] == '(' || input[0] == '{' || input[0] == '[' || input[0] == ')' || input[0] == '}' || input[0] == ']')){
        printf("1");
        return 0;
    }

    int arr_index = 0;
    for (int i=0; i<strlen(input); i++){

        // Opening Char, Push into stack 
        if (input[i] == '(' || input[i] == '{' || input[i] == '['){
            arr[arr_index].value = input[i];
            arr[arr_index].index = i+1;
            arr_index++;
        }

        // Closing Char, Check if corresponding symbol
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']'){
            int last = arr_index - 1;
            if(input[i] == ')'){
                int flag = check_previous(arr[last].value, '(');
                if (flag == 0){
                    printf("%d", i+1);
                    return 0;
                }
            }

            else if(input[i] == '}'){
                int flag = check_previous(arr[last].value, '{');
                if (flag == 0){
                    printf("%d", i+1);
                    return 0;
                }
            }

            else if(input[i] == ']'){
                int flag = check_previous(arr[last].value, '[');
                if (flag == 0){
                    printf("%d", i+1);
                    return 0;
                }
            }

            arr_index--;
        }
    }

    if(arr_index > 0){
        printf("%d", arr[0].index);
        return 0;
    }

    printf("Success");

    return 0;
}

int check_previous(char previous, char expected){
    if (previous == expected){
        return 1;
    }
    return 0;
}