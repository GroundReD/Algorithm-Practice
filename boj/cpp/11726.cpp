//11726.cpp

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;

	cin >> n;
	vector<int> v(n);

	v[0] = 1;
	v[1] = 2;


	for (int i = 2; i < n; ++i)
	{
		v[i] = v[i-1] + v[i-2];
		v[i] %=10007;
	}

	cout << v[n-1];

	return 0;
}