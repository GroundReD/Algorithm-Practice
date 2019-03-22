//sample.cpp
int main(){

	cin >> n >> m;

	vector<pair<int,int> > points;
	vector<int> comb;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			if(a[i][j] == 0){
				points.push_back(make_pair(i,j));
			}
		}
	}

	//0을 채우고 1을 채움
	for(int i=0; i<points.size()-3; i++){
		comb.push_back(0);
	}
	for(int i=0; i<3; i++){
		comb.push_back(1);
	}

	do{

		int tmp[8][8];

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
					tmp[i][j] = a[i][j];
			}
		}

		for(int i=0;i<comb.size();i++){
			if(comb[i] == 1){
				a[points[i].first][points[i].second] = 1;
			}
		}
		spread();
		count_and_get_max();

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
					a[i][j] = tmp[i][j];
			}
		}	

	}while(next_permutation(comb.begin(),comb.end()));

	cout << ans << '\n';

	return 0;
}