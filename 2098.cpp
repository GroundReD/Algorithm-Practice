//2098.cpp

#include <iostream>
#include <algorithm>
#define MAX_VALUE 987654321
using namespace std;

int weight[17][17];
int visit[17][1<<16];
int n;

int tsp(int current, int visited) {

	// 모든 노드 방문 했을 때
	if(visited == (1<<n)-1) {
		//마지막 노드에서 1로 돌아가는 길이 있다면
		if (weight[current][1] != 0) {
			return weight[current][1];	
		}
		return MAX_VALUE;
		
	}


	int &currentCost = visit[current][visited];


	if (currentCost != 0) {
		return currentCost;
	}

	currentCost = MAX_VALUE;


	for(int i = 1; i<=n ; i++) {
		//i 번째 노드에 방문 안했고 현재노드에서 I번째 노드로 연결된 길이 있으면
		if( (visited & (1<<(i-1))) == 0  
		&& weight[current][i] != 0) {
			currentCost = min(currentCost, weight[current][i] + tsp(i,visited | 1<<(i-1)));
		} 
	}

	return currentCost;
}

int main(int argc, char const *argv[])
{
	for(int i = 0 ; i < 17; i++) {
		for (int j = 0 ; j <17 ; j++) {
			weight[i][j] = 0;
		}
	}

	cin >> n;

	for(int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> weight[i][j];		
		}
	}

	cout<<tsp(1,1)<<'\n';

	return 0;
}