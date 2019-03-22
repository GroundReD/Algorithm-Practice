//14888.cpp 연산자 끼워넣기
// dfs 사용

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int N;
int _max = 2<<30, _min = ~(2<<30);

int solve (int depth, int value, int plus, int minus, int mul, int div ) {
	if (depth >= N) {
		if (_max<value) {
			_max = value;
		}

		if (_min > value) {
			_min = value;
		}

		return 0;
	}

	if (plus > 0) {
		solve(depth+1, value+a[depth], plus-1, minus, mul, div);
	}

	if (minus > 0) {
		solve(depth+1, value-a[depth], plus, minus-1, mul, div);

	}

	if (mul > 0) {
		solve(depth+1, value*a[depth], plus, minus, mul-1, div);
	} 

	if (div > 0) {
		solve(depth+1, value/a[depth], plus, minus, mul, div-1);
	}

	return 0;

}

int main () {
	
	cin >> N;
	vector<int> op(N-1);

	for (int i = 0 ; i < N; ++i) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	for (int i = 0 ; i<4 ; ++i) {
		cin >> op[i];
	}

	solve(1,a[0], op[0],op[1],op[2],op[3]);

	cout<<_max<<'\n'<<_min<<'\n';

	return 0;
}