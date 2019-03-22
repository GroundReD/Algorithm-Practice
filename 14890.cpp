//14890.cpp 경사로

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[100][100];
int l,n;

int solve(vector<int> &r ){

	int size = r.size();
	vector<int> visit(n);

	for (int i =0; i < size-1;  ++i ) 
	{
		// 같으면 계속
		if (r[i] == r[i+1]) {
			continue;
		}
		// 다르면
		else if (r[i] < r[i+1]) 
		{
			//1 차이나는지 확인
			if (r[i+1]-r[i] != 1) 
			{
				return 0;
			}
			//1 차이나면 경사로 놓을 수 있는지 확인 
			// 범위 안 벗어나면
			else if (i-l+1>=0 )
			{
				for (int j = i-l+1; j<=i ; ++j) 
				{
					// 다 안같으면 
					if (r[j] != r[i]) 
					{
						return 0;
					}
					// 이미 경사로 놨으면
					if ( visit[j] == 1) 
					{
						return 0;
					}
				}
				// 경사로 놓음
				for (int j = i-l+1; j<=i ; j++) 
				{
					visit[j] = 1;
				}

			}
		}
	}

	return 1;
}

int main () {

	cin >>n>>l;
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		for(int j = 0 ; j <n ;++j) {
			cin >> board[i][j];
		}
	}

	// row 

	for (int i = 0 ; i < n ; ++i) {
		vector<int> r(n);
		
		for(int j=0; j<n ;++j) {
			r[j] = board[i][j];
		}

		answer += solve(r);
	}

	cout <<answer<<'\n';

	return 0;
}