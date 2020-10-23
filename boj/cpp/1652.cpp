//1652.cpp
#include <iostream> 

using namespace std;

int room[101][101];

int main () {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0 ; j < 101 ; ++j) {
			room[i][j] =0;
		}
	}

	int n;
	cin >>n;

	for(int i = 1; i<=n ; i++) {
		for (int j = 1; j <= n; ++j)
		{
			char tmp;
			cin >>tmp;

			if(tmp == '.') {
				room[i][j] = 1;
			} else if (tmp == 'X') {
				room[i][j] = 10;
			}
		}
	}

	int row,col;
	row=col=0;

	for(int i = 1; i<=n ; i++) {
		for (int j = 1; j <= n-1; ++j)
		{
			if(room[i][j] + room[i][j+1] == 2) {
				row++;
			}

			if(room[i][j-1] + room[i][j]+ room[i][j+1] == 3) {
				row--;
			}
		}
	}

	for(int j = 1; j<=n ; j++) {
		for (int i = 1; i <= n-1; ++i)
		{

			if(room[i][j] + room[i+1][j] == 2) {
				col++;
			}

			if(room[i-1][j] + room[i][j] + room[i+1][j] == 3){
				col--;	
			}


		}
	}



	cout << row << ' ' << col <<'\n';


	return 0;
}