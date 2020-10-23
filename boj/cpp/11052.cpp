// 11052.cpp

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> price(n+1);
	vector<int> max_output(n+1);

	for (int i = 1; i <=n; ++i) {
		cin>>price[i];
	}

	for (int i = 1 ; i <=n; ++i) {
		for (int j = 1; j <=i; ++j) {
			max_output[i] = max(max_output[i], price[j]+max_output[i-j]);

		}
	}

	cout << max_output[n];

	return 0;
}