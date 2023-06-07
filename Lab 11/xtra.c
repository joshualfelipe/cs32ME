#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int quick_select(int A[], int p, int r, int rank);

void insertion_sort(int A[], int from, int to) {
    for(int i = from; i < to; i++) {
        for(int j = i + 1; j > from && A[j] < A[j - 1]; j--) {
            int temp = A[j - 1];
            A[j - 1] = A[j];
            A[j] = temp;
        }
    }
}

int median_of_medians(int A[], int p, int r){
	// Write your code here
    // printf("here");
    int size = sizeof(A);
    
    int x = ceil(size/5);
    int M[x];

    int i = 0;
    int c = 0;
    
    while(i < size){
        int temp[5];
        int k = 0;
        if((size - i + 1) < 5){
            for(int j = i; j < size; j++){
                temp[k] = A[j];
            }
        }
        else{
            for(int j = i; j < i + 4; j++){
                temp[k] = A[j];
            }
        }

        insertion_sort(temp, 0, sizeof(temp)/sizeof(temp[0]));

        M[c] = temp[2];
        i++;
    }
    
    for(int l = 0; l < x; l++){
        printf("%d ", M[l]);
    }
    return quick_select(M, p, r, floor((size + 1) / 2));
    
}

int median_partition(int A[], int p, int r){
	// Write your code here
    int size = sizeof(A);
    printf("%d ", size);
    int median = median_of_medians(A, p, r);
    int ind;
    
    for(int i = 0; i < size; i++){
        if(A[i] == median){
            ind = i;
            break;
        }
    }

    int temp = A[ind];
    A[ind] = A[r];
    A[r] = temp;

    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++){
        if (A[j] <= x){
            i++;
            int temp1 = A[j];
            A[j] = A[i];
            A[i] = temp1;
        }
    }

    int temp2 = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp2;

    return i + 1;


}

int quick_select(int A[], int p, int r, int rank){
	// Write your code here
    if (p == r){
        return A[p];
    }

    int q = median_partition(A, p, r);
    int k = q - p + 1;
    
    if (rank == k){
        return A[q];
    }

    else if (rank < k){
        return quick_select(A, p, q - 1, rank);
    }

    else{
        return quick_select(A, q + 1, r, rank - k);
    }
}

int main(){
	int T, M;
	scanf("%d", &T);
	while(T-- > 0){
		scanf("%d", &M);
		int arr[M];

		//read the elements of the input array
		for(int i=0; i<M; i++){
			scanf("%d",&arr[i]);
		}

		int median_index = ((M+1)/2);
		printf("Median: %d\n", quick_select(arr, 0, M-1, median_index));
	}
}