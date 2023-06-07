#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
    /* Write your code for update() here */
    int temp;
    temp = *a + *b;
    *b = abs(*a - *b);
    *a = temp;

}

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    /* Supply code to call update() here */  
    int* a1;
    int* b1;

    a1 = &a;
    b1 = &b;

    update(a1, b1);
    
    printf("%d\n%d", *a1, *b1);

    return 0;
}