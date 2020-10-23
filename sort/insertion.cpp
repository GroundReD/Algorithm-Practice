//insertion sort

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j;
	int tmp=0;
	scanf("%d", &n);

	int *arr = (int *) malloc (sizeof(int)*n);

	for (i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}

	for (i=1;i<n;i++) {
		tmp = arr[i];
		j=i-1;
		while(j >=0 && tmp < arr[j]) { 
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = tmp;
	}

	for(i = 0;i<n;i++) { 
		printf("%d\n",arr[i]);
	}

	return 0;
}