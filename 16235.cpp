//16235.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m,n,k;
vector<int> treemaps[10][10];
int feed[10][10];
int maps[10][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m>> k;

	for( int i = 0; i<n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			cin>> feed[i][j];
			maps[i][j] = 5;
		}
	}

	for(int i = 0 ; i< m ; i++) {
		int row, col,year;
		cin >> row >> col >>year;

		treemaps[row-1][col-1].push_back(year);
	}


	for(int K = 0 ; K<k ; K++) {
		vector<int> deadTree[10][10];

		//spring
		for(int i=0; i<n ; i++) {
			for(int j = 0 ; j<n ; j++) {
				if(treemaps[i][j].empty()) {
					continue;
				}
				priority_queue<int, vector<int>, greater<int> > q;
				for(int k = 0 ; k<treemaps[i][j].size() ; k++) {
					q.push(treemaps[i][j][k]);
				}

				vector<int> tmp;
				while(!q.empty()) {
					int y = q.top();
					if(y > maps[i][j]){
						q.pop();
						deadTree[i][j].push_back(y);
					} else {
						maps[i][j] -= y;
						q.pop();
						tmp.push_back(y+1);
					}
				}
			
				treemaps[i][j] = tmp;
			}
		}

		//summer
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if(deadTree[i][j].empty()) {
					continue;
				}

				for(int k = 0; k<deadTree[i][j].size() ; k++) {
					maps[i][j] += deadTree[i][j][k]/2;
				}
			}
		}

		for( int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if(treemaps[i][j].empty()) {
					continue;
				}

				for(int k = 0 ; k<treemaps[i][j].size() ; k++) {
					if(treemaps[i][j][k] %5 == 0){

						if(i-1>=0) {
							if(j-1>=0) {
								treemaps[i-1][j-1].push_back(1);
							}

							treemaps[i-1][j].push_back(1);
							if(j+1<n) {
								treemaps[i-1][j+1].push_back(1);
							}	
						}

						if(i+1<n) {
							if(j-1>=0) {
								treemaps[i+1][j-1].push_back(1);
							}

							treemaps[i+1][j].push_back(1);
							if(j+1<n) {
								treemaps[i+1][j+1].push_back(1);
							}	
						}

						if(j-1>= 0) {
							treemaps[i][j-1].push_back(1);	
						}

						if( j+1<n ) {
							treemaps[i][j+1].push_back(1);
						}
					}
				}
			}
		}

		//winter

		// cout<<"\npremap\n";
		// for(int i = 0 ; i < n; i++) {
		// 	for(int j = 0 ; j<n ; j++) {
		// 		cout<<maps[i][j]<<"\t";
		// 	}
		// 	cout<<endl;
		// }

		// cout<<"\nmap\n";
		for(int i = 0 ; i < n; i++) {
			for(int j = 0 ; j<n ; j++) {
				maps[i][j]+=feed[i][j];
				// cout<<maps[i][j]<<"\t";
			}
			// cout<<endl;
		}

		// cout<<"\ntree\n";

		// for(int i = 0 ; i < n; i++) {
		// 	for(int j = 0 ; j<n ; j++) {
		// 		for(int k = 0 ; k<treemaps[i][j].size();k++) {
		// 			cout<<i+1<<' '<<j+1<<' '<<treemaps[i][j][k] << '\n';
		// 		}
		// 	}
		// }
	}

	int answer = 0;

	for(int i =0 ; i<n ; i++) {
		for(int j = 0 ;j<n ; j++) {
			answer+=treemaps[i][j].size();
		}
	}

	cout<<answer;

	return 0;
}