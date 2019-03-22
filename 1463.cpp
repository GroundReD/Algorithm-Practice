//1463_bottom.cpp

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> v(1000001); 	
	cin >> n;

	v[1] = 0;
	v[2] = 1;
	v[3] = 1;

	for (int i = 4 ; i <= n ; ++i) {
		v[i] = v[i-1]+1;

		if ( i % 2 == 0 && v[i] > v[i/2]+1 ) {
			v[i] = v[i/2]+1;
		}

		if ( i % 3 == 0 && v[i] > v[i/3]+1 ) {
			v[i] = v[i/3]+1;
		}
	}

	cout << v[n];

	return 0;
}