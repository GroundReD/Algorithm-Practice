//14501.cpp

#include <iostream>

using namespace std;
int max(int a, int b) {
	if(a>b) {
		return a;
	} else
		return b;
}
int main() {

	int n;
	cin >> n;
	int arr[16][2] = {0,};
	int dp[21] = {0,};

	for(int i = 0 ; i<21 ; i++) {
		dp[i] = 0;
		if(i > n) {
			dp[i] = -987654321;
		} 
	}

	for(int i = 1 ; i <= n ; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for(int i = n ; i>0 ; i--) {
		
		dp[i] = max(dp[i+1], arr[i][1]+dp[i+arr[i][0]]);
	
	}

	int answer = dp[1];

	for(int i = 1 ; i<= n ; i++) {
		if(answer < dp[i]) {
			answer = dp[i];
		}
	}

	cout<<answer;
	return 0;
}