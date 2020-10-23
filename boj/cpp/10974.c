//순열 출력

#include <stdio.h>
#include <stdlib.h>

int *arr;

void swap (int a, int b) {
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void rightRotate(int start, int end) {
    int last = arr[end];
    int i = 0;

    for (i = end; i>start ; i--) {
        arr[i] = arr[i-1];
    }

    arr[start] = last;
}

void leftRotate(int start, int end) {
    int first = arr[start];
    int i;

    for (i = start; i<end ; i++) {
        arr[i] = arr[i+1];
    }

    arr[end] = first;

}

void permutation (int *arr, int n, int k, int depth) {
    int i = 0;

    if (k == depth) {
        for (i = 0; i<k ; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (i = depth ; i<n ; i++) {
        rightRotate(depth, i);
        permutation(arr, n, k, depth+1);
        leftRotate(depth, i);
    }
}

int main() {
    int n;
    int i;

    scanf("%d", &n);

    arr = (int*) malloc (sizeof(int)*n);

    for (i = 0; i<n ; i++) {
        arr[i] = i+1;
    }

    permutation(arr, n, n, 0);


}