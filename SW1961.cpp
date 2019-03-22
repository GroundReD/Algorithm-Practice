// sw1961.cpp

#include <iostream>
#include <vector>


using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt","r",stdin);

	int T;
	cin >> T;

	for(int t = 1 ; t<=T ; t++) {
		int n;
		cin >> n;

		vector< vector<int> > board;

		for(int i = 0 ; i< n ; i++) {
			vector<int> tmp(n);
			for (int j = 0 ; j <n ; j++) {
				cin >> tmp[j];
			}
			board.push_back(tmp);
		}

		int rotateBoard[3][7][7] = {0,};

		for(int i = 0; i< n ; i++) {
			for( int j = 0; j<n ; j++) {
				rotateBoard[0][i][j] = board[n-j-1][i];
			}
		}

		for(int i = 0; i< n ; i++) {
			for( int j = 0; j<n ; j++) {
				rotateBoard[1][i][j] = board[n-i-1][n-j-1];
			}
		}

		for(int i = 0; i< n ; i++) {
			for( int j = 0; j<n ; j++) {
				rotateBoard[2][i][j] = board[j][n-i-1];
			}
		}

		cout<< "#"<<t<<'\n';

		for(int i = 0 ; i <n ; i++) {
			for (int k = 0 ;k<3 ; k++) {
				for(int j = 0 ; j <n ; j++) {
					cout<<rotateBoard[k][i][j];
				}
				cout << ' ';
			}
			cout<<'\n';
		}

	}
	return 0;
}