//14888_permutation.cpp 연산자 끼워넣기
// dfs 사용

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int N;
int _max = 2<<30, _min = ~(2<<30);

int main () {
	
	cin >> N;
	vector<int> op;

	for (int i = 0 ; i < N; ++i) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	for (int i = 0 ; i<4 ; ++i) {
		int tmp;
		cin >> tmp;
		for (int j = 0 ; j < tmp ; ++j){
			op.push_back(i);
		}
	}

	do {
		int value = a[0];

		for (int i = 0 ; i <op.size() ; ++i) {
			switch(op[i]) {
				case 0:
					value+=a[i+1];
					break;
				case 1:
					value-=a[i+1];
					break;
				case 2:
					value*=a[i+1];
					break;
				case 3:
					value/=a[i+1];
					break;
				default:
					break;
			}
		}

		if (_max < value) {
			_max = value;
		}

		if (_min > value) {
			_min = value;
		}

	}while(next_permutation(op.begin(), op.end()));

	cout<<_max<<'\n'<<_min<<'\n';

	return 0;
}