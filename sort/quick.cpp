//quick sort
#include <stdio.h>
#include <stdlib.h>


int *arr;

void swap(int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void quick_sort(int left, int right){
	int j = left;
	int i= j+1;
	int pivot = j;

	if (left<right) {
		for (;i<right;i++){
			if( arr[pivot] > arr[i]) {
				j++;
				swap(i,j);
			} 
		}
		swap(pivot, j);

		pivot = j;

		quick_sort(left,pivot);
		quick_sort(pivot+1, right);

	}
	
}

int main() {
	int n,i;

	scanf("%d",&n);

	arr = (int*) malloc (sizeof(int)*n);

	for (i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	quick_sort(0, n);

	for (i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i]);
	}
	
}


