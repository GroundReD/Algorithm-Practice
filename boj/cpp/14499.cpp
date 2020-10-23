//14499.cpp 주사위 굴리기

#include <iostream>
using namespace std;

int board[20][20] = {0,};
int dice[6] = {0,};
int _move[1000] = {0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int move_dice(int next_x, int next_y, int dir) {

	int tmp;

	switch(dir) {
		case 1:
			tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[3];
			dice[3] = dice[2];
			dice[2] = tmp;
			break;
		case 2:
			tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[5];
			dice[5] = tmp;
			break;
		case 3:
			tmp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[4];
			dice[4] = dice[5];
			dice[5] = tmp;
			break;
		case 4:
			tmp = dice[0];
			dice[0] = dice[5];
			dice[5] = dice[4];
			dice[4] = dice[2];
			dice[2] = tmp;
			break;
		default:
			break;
	}

	// cout<<"board\t: "<<board[next_y][next_x]<<'\n';

	if (board[next_y][next_x] == 0) {
		board[next_y][next_x] = dice[5];
	} else {
		dice[5] = board[next_y][next_x];
		board[next_y][next_x] = 0;
	}
			

	// cout<<'\t'<<dice[0]<<'\n';
	// cout<<dice[1]<<'\t'<<dice[2]<<'\t'<<dice[3]<<'\n';
	// cout<<'\t'<<dice[4]<<'\n';
	// cout<<'\t'<<dice[5]<<"\n\n";

	cout<<dice[2]<<'\n';
	return 0;
}

int main () {
	int n,m;
	int x,y;
	int k;

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	cin >>n>>m>>y>>x>>k;

	for (int i=0 ; i < n ; ++i) {
		for (int j = 0 ; j<m ; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i=0 ; i<k ; ++i) {
		cin >> _move[i];
	}

	int cur_x = x;
	int cur_y = y;
	int next_x = x;
	int next_y = y;

	if (board[y][x] == 0) {
		board[y][x] = dice[5];
	} else {
		dice[5] = board[y][x];
		board[y][x] = 0;
	}

	for (int i = 0 ; i<k ; ++i) { 
		cur_x = next_x;
		cur_y = next_y;
		next_x += dx[_move[i]-1];
		next_y += dy[_move[i]-1];
		// cout << "current\t: " << cur_y << ' ' <<cur_x <<'\n';
		// cout << "next\t: " << next_y << ' ' <<next_x <<'\n';
		if (next_x >= 0 && next_x <m && next_y >= 0 && next_y < n) {
			move_dice(next_x,next_y, _move[i]);
		} else {
			next_x = cur_x;
			next_y = cur_y;
		}
	}

	return 0;
}