// 1620.cpp

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int string2int(string tmp) {
	int answer = 0;
	for(int i = 0 ; i < tmp.size() ; i++) {
		int a = tmp[i]-'0';
		answer*=10;
		answer += a;
	} 

	return answer;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	map<int, string> num2pokemon;
	map<string, int> pokemon2num;

	for(int i = 0 ; i< n ; i++){
		string tmp;
		cin >>tmp ;

		num2pokemon[i+1] = tmp;
		pokemon2num[tmp] = i+1;


	}

	vector<string> answer(m);

	for(int i = 0 ; i < m ; i++) {
		cin >>answer[i];
	}

	for(int i = 0 ;i <m ; i++){

		if(answer[i][0] >= '0' && answer[i][0] <= '9') {
			int tmp = string2int(answer[i]);
			cout << num2pokemon[tmp]<<'\n';
		} else {
			cout<<pokemon2num[answer[i]]<<'\n';
		}

	}

	return 0;
}