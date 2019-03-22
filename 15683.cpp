//15683.cpp

#include <iostream>
#include <vector>

#define up 1
#define	right 2
#define down 4
#define left 8

using namespace std;

typedef struct POS{
	int row;
	int col;
	int type;
}pos;



int rotate[5][5] = {
	{up,right,down,left},
	{up|down, right|left, up|down, right|left},
	{up|right, right|down, down|left, left|up},
	{left|up|right, up|right|down, right|down|left, down|left|up},
	{left|up|down|right,left|up|down|right,left|up|down|right,left|up|down|right}
};
int colDir[4] = {0,1,0,-1};
int rowDir[4] = {-1,0,1,0};

int n,m;
vector<vector<int> > board;
vector<pos> camera;

void watch(vector<vector<int> > &tmpBoard, pos camera, int degree) {
	int type = camera.type -1;
	pos curPos = camera;

	for(int i = 0 ; i < 4 ; i++) {
		if(rotate[type][degree] & (1<<i)) {
			for(int curRow = curPos.row ; ; curRow+=rowDir[i]) {
				for(int curCol =curPos.col ;; curCol+=colDir[i]) {
					if (curRow >= n || curCol >= m || curRow<0 ||  curCol<0 || tmpBoard[curRow][curCol] == 6) {
						break;
					} 

					if(tmpBoard[curRow][curCol] == 0) {
						tmpBoard[curRow][curCol] = -1;
					} 
				}
			}
		}
	}
}


int check(vector<vector<int> > tmpBoard) {
	int sum= 0;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0; j<m ; j++) {
			if(tmpBoard[i][j] == 0) {
				sum+=1;
			}
		}
	}
	return sum;
}

void dfs(vector<vector<int> > tmpBoard, int depth) {

	if(depth > camera.size()) {
		return;
	}

	vector<vector<int> > copyBoard;
	copyBoard.assign(tmpBoard.begin(), tmpBoard.end());
	pos curCamera = camera[depth];

	for(int i = 0 ; i < 4 ; i++ ) {
		watch(copyBoard, curCamera, i);
		dfs(copyBoard, depth+1);
		copyBoard = tmpBoard;

	}




}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	board.assign(n, vector<int>(m,0));

	for(int i =0 ; i<n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			cin >> board[i][j];
			if(board[i][j] != 0 && board[i][j] !=6) {
				pos tmp = {i ,j, board[i][j]};
				camera.push_back(tmp);
			}
		}
	}


	dfs(board, 0);




	return 0;
}