#include <stdlib.h>
#include <stdio.h>

int main(){
    int m = 256;
    int arr[256] = {};
    int total = 0;

    for(int j = 0; j < m; j++){
        int k;
        int i = 0;
        scanf("%d",&k);
        
        int h1 = k % m;
        int h2 = (((1731 * k + 520123)  % 524287) % m ) | 1;

        while(1){
            int hk = (h1+(i*h2)) % m;
            if(arr[hk] == 0){
               arr[hk] = k; 
               break;
            }

            else{
                i++;
            }
        }
        
        total = total + i;
    }

    for(int l = 0; l < m; l++){
        printf("%d: %d\n", l, arr[l]);
    }

    printf("%d", total);


    return 0;
}