//14503.cpp 로봇청소기
#include <iostream>
#define CLEAN 2

using namespace std;

int N,M;
int board[50][50];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,-0,-1};

int clean(int x, int y, int dir) {
	bool chk = false;
	board[x][y] = CLEAN;
	int next_x, next_y;

	for (int i = 3 ; i >=0 ; --i ){
		next_x = x + dx[(dir+i)%4];
		next_y = y + dy[(dir+i)%4];

		if ( board[next_x][next_y] != 0 ) {
			continue;
		} else {
			chk = true;
			clean(next_x,next_y, dir+i);
			return 0;
		}
	}

	next_x = x + dx[(dir+2)%4];
	next_y = y + dy[(dir+2)%4];

	if (board[next_x][next_y] !=1) { 
		clean(next_x,next_y, dir);

	} else if ( board[next_x][next_y] == 1) {
		return 0;
	} 
	
	return 0;

}

int count() { 
	int cnt=0;
	for (int i = 1; i<N; ++i)
	{
		for (int j=1; j<M ;++j) {
			if (board[i][j] == 2) {
				cnt++;
			}
		}
	}

	return cnt;
}
int main () {
	cin >> N>>M;
	int x,y,d;

	cin >> x>>y>>d;

	for (int i = 0 ; i<N ; ++i) {
		for (int j = 0 ; j<M ; ++j){
			cin >>board[i][j];
		}
	}

	clean(x,y,d);
	cout<<count()<<'\n';

	return 0;
}