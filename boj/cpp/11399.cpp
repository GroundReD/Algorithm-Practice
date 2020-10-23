#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int answer = 0;
	cin >> n;

	vector<int> time(n);

	for (int i = 0 ; i<n; ++i) {
		cin >> time[i];
	}

	sort(time.begin(), time.end());

	for (int i = 0 ; i<n ; i++) {
		for (int j = 0 ; j <= i ; j++) {
			answer += time[j]; 
		}
	}

	cout<< answer;
	return 0;
}