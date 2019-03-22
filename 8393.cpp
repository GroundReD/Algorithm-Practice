#include <stdio.h>

int main() {

	int num = 0;
	scanf("%d", &num);
	int i;
	int result = 0;

	for (i = 1 ; i <= num ;i++ ) {
		result += i;
	}

	printf("%d",result);

	return 0;
}