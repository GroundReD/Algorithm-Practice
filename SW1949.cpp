//SW1949.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[10][10] = {0,};
int max_value = 0;
int visited[10][10] = {0,};
int n,k;
int answer = -1;

typedef struct {
	int row;
	int col;
	int height;
	int length;
	bool isDigged;
} POS;

void clear() {
	max_value = 0;
	answer = 0;

	for (int i = 0; i<10 ; ++i ) {
		for (int j = 0; j<10 ; ++j) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void find(POS pos) {
	
	int curRow = pos.row;
	int curCol = pos.col;
	int curHeight = pos.height;

	//지도 바깥
	if (pos.row < 0 || pos.row >= n || pos.col < 0 || pos.col>=n) {
		return;
	}

	//방문 기록
	visited[curRow][curCol] = 1;

	//up
	if (curRow > 0) {
		if (map[curRow-1][curCol] < curHeight && visited[curRow-1][curCol] != 1) {
			POS nextPos = {curRow-1, curCol,map[curRow-1][curCol], pos.length+1, pos.isDigged};
			find(nextPos);

		} else if (!pos.isDigged && map[curRow-1][curCol]-k < curHeight && visited[curRow-1][curCol] != 1) {
			POS nextPos = {curRow-1, curCol, curHeight-1, pos.length+1, !pos.isDigged};
			find(nextPos);
		}
	}

	//right
	if (curCol < n-1) {
		if (map[curRow][curCol+1] < curHeight && visited[curRow][curCol+1] != 1) {
			POS nextPos = {curRow, curCol+1 ,map[curRow][curCol+1], pos.length+1, pos.isDigged};
			find(nextPos);

		} else if (!pos.isDigged && map[curRow][curCol+1]-k < curHeight && visited[curRow][curCol+1] != 1) {
			POS nextPos = {curRow, curCol+1 ,curHeight-1, pos.length+1, !pos.isDigged};

			find(nextPos);
		}
	}
	//down
	if (curRow < n-1) {
		if (map[curRow+1][curCol] < curHeight && visited[curRow+1][curCol] != 1) {
			POS nextPos = {curRow+1, curCol,map[curRow+1][curCol], pos.length+1, pos.isDigged};
			find(nextPos);

		} else if (!pos.isDigged && map[curRow+1][curCol]-k < curHeight && visited[curRow+1][curCol] != 1) {
			POS nextPos = {curRow+1, curCol,curHeight-1, pos.length+1, !pos.isDigged};

			find(nextPos);
		}
	}

	//left
	if (curCol > 0) {
		if (map[curRow][curCol-1] < curHeight && visited[curRow][curCol-1] != 1) {
			POS nextPos = {curRow, curCol-1,map[curRow][curCol-1], pos.length+1, pos.isDigged};
			find(nextPos);

		} else if (!pos.isDigged && map[curRow][curCol-1]-k < curHeight && visited[curRow][curCol-1] != 1) {
			POS nextPos = {curRow, curCol-1,curHeight-1, pos.length+1, !pos.isDigged};
			find(nextPos);
		}
	}

	visited[curRow][curCol] = 0;
	answer = pos.length>answer?pos.length:answer;
	return;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0 ; t<T ; ++t) {

		cin >>n >>k;

		for (int i = 0; i<n;i++) {
			for (int j = 0;j<n;j++) {
				cin >> map[i][j];
				if (max_value <= map[i][j]) {
					max_value = map[i][j];
				}
			}
		}


		for (int i = 0; i<n;i++) {
			for (int j = 0;j<n;j++) {
				if (map[i][j] == max_value) {
					POS pos= { i,j, max_value, 1, false};
					find(pos);
				} else continue;
			}
		}

		cout<<"#"<< t+1<<" "<< answer<<endl;

		clear();
	}

	return 0;
}