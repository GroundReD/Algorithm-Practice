#include <stdio.h>

int main() {
	int num = 0;
	scanf("%d", &num);

	int num_5 = num/5;
	int num_3 = 0;

	int result = 0;

	while(1) { 
		if ( num%5 == 0) {
			result = num/5 + num_3;
			break;
		}

		else if (num < 0 ) {
			result = -1;
			break;
		}

	num_3++;

	num -= 3;

	}

	printf("%d\n", result);

	return 0;
}