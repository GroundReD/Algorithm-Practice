// 10844.cpp

#include <iostream>

using namespace std;

int main() {
	long long n, ans=0;
	cin >> n;	

	long long arr[101][10] = {0,};


	for (int i = 1; i<=n; i++) {
		for(int j=0; j<10; j++) {
			if(i == 1 && j != 0) {
				arr[i][j] = 1;
			} else {
				if (j == 0) {
					arr[i][j] = arr[i-1][j+1];
				} else if ( j == 9) {
					arr[i][j] = arr[i-1][j-1];
				} else {
					arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1];	
				}
			}	
			arr[i][j]%=1000000000;		
		}
	}

	for (int i = 0 ; i<10 ; i++) {
		ans+=arr[n][i];
	}

	ans %= 1000000000;
	cout << ans;

	return 0;
}