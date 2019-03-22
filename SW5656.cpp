// sw5656.cpp

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, w, h;
int orgin_board[15][12];
int board[15][12];


void initBoard() {
	for(int i = 0 ; i<h ; i++ ) {
		for(int j = 0 ; j <w ; j++) {
			board[i][j] = orgin_board[i][j];
		}
	}
}

int checkBoard() {
	int count = 0;

	for(int i = 0 ; i<h ; i++ ) {
		for(int j = 0 ; j <w ; j++) {
			if(board[i][j]!=0) {
				count+=1;
			}
		}
	}

	return count;	
}

void printBoard() {
	for(int i = 0 ; i<h ; i++ ) {
		for(int j = 0 ; j <w ; j++) {
			cout<< board[i][j] << ' ';
		}
		cout<<'\n';
	}
	cout<<'\n';
}
void splash(int row, int col, int range) { 

	board[row][col] = 0;

	for( int i = col-range+1 ; i < col+range ; i++) {
		if( i <0 || i >=w ) {
			continue;
		} else if (board[row][i] == 0) {
			continue;
		} else {
			// cout<< "splash "<< row << ' '<<i <<'\n';
			splash(row,i,board[row][i]);
		}
	}

	for( int i = row-range+1 ; i < row+range ; i++) {
		if( i <0 || i >=h ) {
			continue;
		} else if (board[i][col] == 0) {
			continue;
		} else {
			// cout<< "splash "<< i << ' '<<col <<'\n';
			splash(i,col,board[i][col]);
		}
	}

}

void down() {

	for(int col = 0 ; col<w ; col++) 
	{
		 for(int row = h-1 ; row>=0 ; row--) 
		 {
			if(board[row][col] == 0 )
			{
				for( int j = row-1 ; j>=0 ; j--) 
				{
					if(board[j][col] != 0 ) 
					{
						board[row][col] = board[j][col];
						board[j][col] = 0;
						break;
					}
				}
			}
		}
	} 
}

void bomb(int col) {
	// cout<<"bomb\n";

	int i;

	for(i = 0 ; i < h ; i++) {
		if (board[i][col] != 0) {
			break;
		}
	}

	// cout << i<<' '<<col <<' '<<board[i][col]<<'\n';
	int range = board[i][col];

	splash(i,col,range);
	

}

void solve() {

}

int main() {

	freopen("sample_input.txt","r",stdin);

	int T;
	cin >>T;
	for(int t=1 ; t<= T ; t++) {

		int answer = 987654321;

		for(int i = 0 ; i<15 ; i++) {
			for(int j = 0 ; j <12 ; j++) {
				orgin_board[i][j] = 0;
				board[i][j] = orgin_board[i][j];
			}
		}

		cin >>n>>w>>h;

		for(int i = 0 ; i<h ; i++) {
			for(int j = 0 ; j <w ; j++) {
				cin >> orgin_board[i][j];
				board[i][j] = orgin_board[i][j];
			}
		}

		int perm[4] = {0,};


		for(perm[0] = 0 ; perm[0]<w ; perm[0]++) {
			for(perm[1] = 0 ; perm[1]<w ; perm[1]++) {
				for(perm[2] = 0 ; perm[2]<w ; perm[2]++) {
					for(perm[3] = 0 ; perm[3]<w ; perm[3]++) {
						initBoard();

						for(int i = 0 ; i <n ; i++) {
							bomb(perm[i]);
							down();
						}

						int tmp_answer = checkBoard();
		

						if(answer > tmp_answer) {
							answer = tmp_answer;
						}

						if(answer == 0) {
							break;
						}


						if(n<4){
							break;
						} 	
					}
					if(n<3) break;
					if(answer == 0) {
							break;
					}
				}
				if(n<2) break;
				if(answer == 0) {
							break;
				}
			}
		}

		cout<<"#"<<t<<' ' << answer <<'\n';
	}


	return 0;
}