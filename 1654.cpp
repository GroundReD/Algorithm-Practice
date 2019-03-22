// 1654.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;
long long k ,n;
long long _max = -1;

bool check(long long mid) {
	int result = 0;
	for(int i = 0 ; i <v.size() ; i++) {
		result+= v[i]/mid;
	}

	return result>=n;
}

int main (){

	

	cin >>k>>n;

	v.assign(k,0);

	for(int i = 0 ; i < k ; i++){
		cin>>v[i];
		if(_max < v[i]){
			_max = v[i];
		}
	}

	long long answer = -1;
	long long left = 1;
	long long right = _max;

	while(left <= right) {
		long long mid = (left+right)/2;

		if(check(mid)) {
			if(mid > answer) {
				answer = mid;
			}
			left = mid+1;
		} else {
			right = mid-1;
		}
	}

	cout<<answer<<'\n';

	return 0;
}