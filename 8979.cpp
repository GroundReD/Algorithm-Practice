//8979.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct COUNTRY {
	int name;
	int gold;
	int silver;
	int bronze;
	int rank;
}country;

int n,k;

bool comp(country c1, country c2) {
	if( c1.gold != c2.gold) {
		return c1.gold > c2.gold;
	} else if (c1.silver != c2.silver) {
		return c1.silver > c2.silver;
	} else if (c1.bronze != c2.bronze) {
		return c1.bronze > c2.bronze;
	} else {
		return c1.name == k;
	}
}

int main() {

	cin >> n >> k;

	vector<country> v(n);

	for(int i = 0 ; i < n ; i++) {
		country c;
		cin >> c.name >> c.gold >> c.silver>> c.bronze;
		v.push_back(c);
	}

	sort(v.begin(), v.end(), comp);

	for( int i = 0 ; i<n ; i++) {
		if(v[i].name == k) {
			cout << i+1;
			break;
		}
	}


	return 0;
}