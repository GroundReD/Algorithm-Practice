//13458.cpp

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	long long b,c;
	cin >>n;
	vector<long long> a(n);

	for (int i = 0 ; i < n ; ++i) {
		cin >> a[i];
	}
	cin >>b>>c;
	long long count=0;

	for (int i = 0 ; i<n ; ++i) {
		a[i] = a[i]>=b?a[i]-b:0;
		count+=1;

		if(a[i] > 0) {
			long long tmp = a[i]/c;
			long long r = a[i]%c;

			if (r == 0) {
				count+=tmp;
			} else {
				count+=tmp+1;
			}
		}
	}


	cout << count << '\n';
	return 0;
}