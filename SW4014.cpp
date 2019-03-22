//sw4014.cpp

#include <iostream>

using namespace std;

int board[20][20];
int height[20];
bool upslope[20];
bool downslope[20];
int n, x;

bool isflat(int start, int end) {

	if (start<0 || end>= n) {
		return false;
	}

	for(int i = start ; i<end ; i++) {
		if(height[i] != height[i+1]) {
			return false;
		}
	}
	return true;

}

bool check() {

	for(int i = 0 ; i < n-1; i++){
		int tmp = height[i]>height[i+1]?height[i]-height[i+1]:height[i+1]-height[i];
		if(tmp>=2) {
			return false;
		}
	}

	for(int i = 0 ; i < 20 ; i++) {
		upslope[i] = false;
		downslope[i] = false;
	}
	
	for(int i = 0 ; i < n-1 ; i++) {
		int tmp = height[i]-height[i+1];

		if(tmp == -1) {
			int start = i-x+1;
			int end = i;

			if(isflat(start,end)) {
				for(int j = start; j<=end ; j++) {
					upslope[j] = true;
				}
			} else {
				return false;
			}
		}

		else if(tmp == 1) {
			int start = i+1;
			int end = i+x;

			if(isflat(start,end)) {
				for(int j = start; j<=end ; j++) {
					downslope[j] = true;
				}
			} else {
				return false;
			}

		}
	}

	for(int i = 0 ; i < n ; i++){
		if(upslope[i]== true && downslope[i] == true) {
			return false;
		}
	}

	return true;

}
int main() {

	int T;
	cin >> T;

	for(int t = 0 ; t < T ; t++) {
		cin >> n >> x;
		int answer=0;

		for(int i = 0 ; i < 20 ; i++) {
			for(int j = 0 ; j < 20 ; j++){
				board[i][j] = 0;
			}
			height[i] = 0;
			upslope[i] = false;
			downslope[i] = false;
		}

		for(int i = 0; i<n ; i++) {
			for(int j = 0 ; j <  n; j++) {
				cin >>board[i][j];
			}
		}

		for(int i = 0 ; i < n; i++) {
			for(int j = 0 ; j < n ; j++) {
				height[j] = board[i][j];
			}

			if(check()) {
				cout << "row " << i+1<<'\n';
				answer+=1;
			}

		}

		for( int i = 0 ; i < n ; i++) {
			for(int j = 0; j<n ; j++) {
				height[j] = board[j][i];
			}

			if(check()){
				cout << "col " << i+1<<'\n';
				answer+=1;
			}
		}

		cout<<answer<<'\n';
	}

	return 0;
}