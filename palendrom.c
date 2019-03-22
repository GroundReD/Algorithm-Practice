//palendrom.c

#include <stdio.h>
#include <stdbool.h>

char str[7] = "abdcba";


int pal(char strr[], int start, int end, int type) {
	int check;

	if( start > end) {
		return 0;
	}
	
	if(strr[start] == strr[end]) {
		check = pal(strr, start+1, end-1, 0);
	}

	else if (strr[start] == strr[end-1]){
		check =	pal(strr, start, end-1, 1);
	} else if (strr[start+1] == strr[end]){
		check = pal(strr, start+1, end, 1);
	} else {
		check = 2;
	}

	return check;

}

int main() {
	int i;
	int len = 0;
	int count = 0;

	for(i=0;i<25; i++) {
		if(str[i] == '\0'){
			break;
		}
		len++;
	}

	pal(str,0,len,0);


	return 0;
}