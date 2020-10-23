//1463_top.cpp

#include <iostream>

int d[100001] = {0,};
using namespace std;


int calc (int n) {
	if(n==1){
		return 0;
	}

	if (d[n] > 0) {
		return d[n];
	}

	d[n] = calc(n-1) + 1;

	if (n%2 == 0) {
		int tmp = calc(n/2) + 1;
		if( d[n] > tmp) {
			d[n] = tmp;
		}
	}

	if (n%3 == 0) {
		int tmp = calc(n/3) +1;
		if( d[n] > tmp) {
			d[n] = tmp;
		}
	}

	return d[n];
}

int main() {
	int n;
	cin >> n;

	cout<< calc(n);

	return 0;
}