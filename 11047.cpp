#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	int answer = 0;

	cin >> n >> k;

	vector<int> price(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}

	for (int i = n-1 ; i >= 0 ; i--) {
		answer += k/price[i];
		k = k%price[i];
	}

	cout << answer;


	return 0;
}