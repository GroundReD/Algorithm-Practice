//13460.cpp

#include <iostream>

using namespace std;

char board[11][11];
int n,m;
int answer;

typedef struct POS{
	int row;
	int col;
} Pos;

void clear_board() {
	for(int i =0 ;i<11 ; ++i){
		for(int j=0;j<11;++j){
			board[i][j] = ' ';
		}
	}
}

int search(Pos curRedPos, Pos curBluePos, int count){
	
	int redRow=curRedPos.row;
	int redCol=curRedPos.col;

	int blueRow=curBluePos.row;
	int blueCol = curBluePos.col;

	// 0 :red 1:blue
	int row_priority = redRow>blueRow?0:1;
	int col_priority = redCol>blueCol?0:1;

	
	//blue first
	if (row_priority) {

		// right m
		while (1) {
			if (blueCol<m && board[blueRow][blueCol+1] == 'O') {
				answer=-1;
				return 0;
			} else if (blueCol<m && board[blueRow][blueCol+1] == 'R'){
				break;
			} else if (blueCol<m && board[blueRow][blueCol+1] == '.'){
				blueCol++;
				continue;
			} else {
				break;
			}

			if (redCol<m && board[redRow][redCol+1] == 'O') {
				answer=-1;
				return 0;
			} else if (redCol<m && board[redRow][redCol+1] == 'R'){
				break;
			} else if (redCol<m && board[redRow][redCol+1] == '.'){
				blueCol++;
				continue;
			} else {
				break;
			}
		}

	}
	
	//left m
	if (redcol<m && board[redRow][redCol+1] != '#') {
				redCol+=1;
			}
	//up n

	//down n

	return 0;
}

int main () {
	cin >>n>>m;
	Pos redPos = {0,0};
	Pos bluePos = {0,0};
	Pos outPos = {0,0};

	for(int i = 1 ; i <= n ;++i){
		for(int j =1;j<=m;++j){
			cin >> board[i][j];

			if (board[i][j]=='R') {
				redPos.row = i;
				redPos.col = j;
			} else if ( board[i][j] == 'B') {
				bluePos.row = i;
				bluePos.col = j;
			} else if (board[i][j] == 'O') {
				outPos.row = i;
				outPos.col = j;
			}
		}
	}

	search(redPos,bluePos,0);



	for(int i = 1 ; i <= n ;++i){
		for(int j =1;j<=m;++j){
			cout<< board[i][j] << ' ';
		}
		cout<<'\n';
	}
	return 0;
}