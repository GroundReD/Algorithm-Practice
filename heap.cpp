#include <stdio.h>
#include <stdlib.h>

#define LEFT(x) (2*x+1)
#define RIGHT(x) (2*x+2)
#define PARENT(x) ((x-1)/2)
#define MAX(a,b) (a>b?a:b)

int *arr;

void swap(int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void max_heapfiy(int present, int length){
	int right = RIGHT(present);
	int left = LEFT(present);
	int index = 0;

	// printf("present : %d %d\n", present, arr[present]);
	// printf("left : %d %d \n", left, arr[left]);
	// printf("right : %d %d \n", right, arr[right]);
	
	if (left>length) {
		return;
	}

	if (right<=length) {
		if(arr[right] > arr[left]) {
			index = right;
		} else {
			index = left;
		}
	} else if ( left <= length) {
		index = left;
	}

	// printf("index : %d\n\n", index);

	if (arr[index] > arr[present] ) {
		// printf("swap %d and %d\n", arr[index], arr[present]);
		swap(present, index);
	} else {
		return;
	}

	max_heapfiy(index, length);
}

void make_heap(int length) {
	int i =0;
	for (i = length/2; i >=0 ; --i)
	{
		max_heapfiy(i, length);
	}
}

void heapsort(int length) { 
	int i = 0;
	for (i=length-1 ; i >0; --i)
	{
		swap(0,i);
		make_heap(i-1);
	}
}

int main() {
	int n,i;
	scanf("%d",&n);

	arr = (int *) malloc (sizeof(int)*n);
	for (i = 0; i < n; ++i)
	{	
		scanf("%d", &arr[i]);
	}
	make_heap(n);
	heapsort(n);

	for (i = 0; i < n; ++i)
	{	
		printf("%d\n",arr[i] );
	}

	

	return 0;

}