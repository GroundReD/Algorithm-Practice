//11053.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int n = 0;
	cin >> n;
	vector<int> v(n);
	vector<int> d(n);

	for (int i = 0 ; i < n ; ++i) {
		cin >> v[i];
	}

	for (int i =0 ; i<n ; ++i) {
		d[i] = 1;
		for (int j = 0 ; j<i ; j++) {
			if (v[i] > v[j] && d[i]< d[j]+1) {
				d[i] = d[j]+1;
			}
		}
	}
	cout << *max_element(d.begin(), d.end())<<'\n';

	return 0;
}

