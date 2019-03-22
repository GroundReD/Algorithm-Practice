//merge sort

#include <stdio.h>
#include <stdlib.h>

int *arr;
int *temp;

// 0   2  3 4
// 1 3 5  2 4

//0 7 -> 3
//0 3 -> 1 -> merge 0 1 3 - 1 3  2 4
//0 1 -> 0 -> merge 0 0 1 - 3 1
//2 3 -> 2 -> merge 2 2 3 - 4 2
void merge(int low, int mid, int high) {
	int i, j, k;
	int tmp;

	i=low;
	j=mid+1;
	k=low;

	// 6 7  4 5 8 9 

	while (i<=mid && j<=high) {
		if(arr[i] > arr[j]) {
			temp[k] = arr[j];
			j++;
			k++;
		} else {
			temp[k] = arr[i];
			i++;
			k++;
		}
	}

	while(i<=mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	while(j<=high) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	for(i=low;i<=high;i++){
		arr[i] = temp[i];
	}
}

void merge_sort(int low, int high) {
	int mid = (low + high) /2;

	if (low<high) {
		merge_sort(low, mid);
		merge_sort(mid+1, high);
		merge(low,mid,high);
	}

}


int main () {
	int n;
	int i;
	int mid;

	scanf("%d", &n);

	arr = (int*) malloc (sizeof(int)*n);
	temp = (int*) malloc (sizeof(int)*n);

	for (i=0; i<n;i++) {
		scanf("%d",&arr[i]);
	}

	merge_sort(0,n-1);

	for(i=0;i<n;i++) {
		printf("%d\n",arr[i]);
	}

	free(arr);
	free(temp);

	return 0;
}