//selection sort
#include <stdio.h>

int arr[] = {100, 106, 104, 103, 100, 110, 115, 150, 170, 182};

int main() {
	int i,j;
	int min = 1000;
	int index = -1;
	int cnt = 0;
	int tmp;

	for(i = 0 ; i<10; i++) {
		min = arr[i];
		index = i;
		for(j = i;j <10 ; j++) {
			if(min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}

		printf("min : %d\n", min);

		if( min != arr[i]) {
			tmp = arr[index];
			arr[index] = arr[i];
			arr[i] = tmp;
			cnt++;
		}
	}



	for(i = 0 ; i < 10  ; i++) {
		printf("%d ", arr[i]);
	}

	printf("\ncnt : %d\n", cnt);

	return 0;
}