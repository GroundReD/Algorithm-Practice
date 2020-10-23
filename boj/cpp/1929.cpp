#include <iostream>
#define NMAX 1000000
using namespace std;

bool checkPrime[NMAX+1];

int main () {

	for(int i = 0 ; i<=NMAX ; i++) {
		checkPrime[i] = true;
	}

	checkPrime[0] = false;
	checkPrime[1] = false;

	for( int i = 1 ; i<=NMAX ; i++) {

		if (checkPrime[i]) {
			for(int j = i*2 ; j<=NMAX ; j+=i ) {
				checkPrime[j] = false;
			}
		}
	} 
	int m,n;
	cin >> m>>n;

	for(int i = m ; i<=n ; i++) {
		if (!checkPrime[i]) {
			cout<<i<<'\n';
		}
	}

	return 0;
}