//2156.cpp

#include <iostream>
#include <vector> 
using namespace std;
int main() {
	int n;
	cin >>n;
	vector<int> wine(n+1);
	vector<int> d(n+1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> wine[i]; 
	}

	d[1] = wine[1];
	d[2] = d[1]+wine[2];

	for (int i = 3 ; i<=n ;++i) {
		d[i] = d[i-1];

		if ( d[i] < d[i-2]+wine[i]) {
			d[i] = d[i-2]+wine[i];
		}

		if (d[i] < d[i-3]+wine[i-1]+wine[i]) {
			d[i] = d[i-3]+wine[i-1]+wine[i];
		}
	}

	for (int i = 0 ; i<=n ; i++) {
		cout << d[i] << ' ';
	}
	cout <<'\n';
	cout << d[n] <<'\n';



	return 0;
}