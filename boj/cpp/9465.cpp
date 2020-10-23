// 9465.cpp

#include <iostream>

using namespace std;

long long point[100000][2];
long long d[100000][3];

int main()
{
	int T;
	cin >>T;

	for (int t = 0 ; t<T ; ++t) {
		long long n;
		cin >> n;
		long long ans=0;

		for (int j = 0;j<2;j++) {
			for (int i = 0 ; i <n;++i) {
				cin >> point[i][j];
			}
		}

		d[0][0] = 0;
		d[0][1] = point[0][0];
		d[0][2] = point[0][1];

		for (int i =1 ; i <n ; ++i) {
			d[i][0] = d[i-1][1]>d[i-1][2]?d[i-1][1]:d[i-1][2];

			d[i][1] = d[i-1][0]>d[i-1][2]?d[i-1][0]:d[i-1][2];
			d[i][1] += point[i][0];

			d[i][2] = d[i-1][0]>d[i-1][1]?d[i-1][0]:d[i-1][1];
			d[i][2] += point[i][1];
		}

		for (int i =0 ; i <n ; ++i) {
			long long tmp = d[i][0];

			if (tmp < d[i][1]) {	
				tmp = d[i][1];
			}

			if (tmp < d[i][2]){
				tmp = d[i][2];
			} 

			ans = tmp>ans?tmp:ans;
		}

		cout << ans<<'\n';

	}
	return 0;
}