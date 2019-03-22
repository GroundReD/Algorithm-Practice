//13458_2.cpp

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> v(n);
	vector<long long> answer(n);

	for(int i = 0 ;i < n ; i++) {
		cin >> v[i];
	}
	
	long long b, c;

	cin >>b >> c;

	for(int i = 0 ; i < n ; i++) {
		
		long long all;
		long long sub = 0;

		all = v[i]>=b?v[i]-b:0;

		if(all>0) {
			sub = all%c==0?all/c:all/c+1;
		}

		answer[i] = 1+sub;
	}

	long long sum =0;

	for(int i = 0 ; i < n ; i ++) {
		sum += answer[i];
	}

	cout << sum;

}