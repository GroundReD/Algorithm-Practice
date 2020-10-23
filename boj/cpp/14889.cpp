//14889.cpp 스타트 링크 팀

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int _min = ~(2<<30);
int board[20][20];

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for(int j = 0 ; j < N; ++j)
		{
			cin>> board[i][j];
		}
	}

	vector<int> people(N);
	for (int i =0 ; i<N ;++i) {
		if(i<N/2) {
			people[i] = 0;
		} else {
			people[i] = 1;
		}
	}
	
	do {
		vector<int>s_team;
		vector<int>l_team;
		int s_score = 0;
		int l_score = 0;

		for(int i = 0 ; i < N ; ++i) {
			if(people[i] == 0) {
				s_team.push_back(i);
			} else {
				l_team.push_back(i);
			}
		}

		for (int i = 0; i <N/2; ++i) {
			for(int j = i+1; j<N/2;++j) {
				s_score += board[s_team[i]][s_team[j]] + board[s_team[j]][s_team[i]];
				l_score += board[l_team[i]][l_team[j]] + board[l_team[j]][l_team[i]];
			}
		}

		if( _min > max(s_score - l_score, l_score-s_score)) {
			_min = max(s_score - l_score, l_score-s_score);
		}
	}while(next_permutation(people.begin(), people.end()));

	cout << _min << '\n';

	return 0;
}