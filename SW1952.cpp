//SW1952.cpp
#include <iostream>

#define DAY 0
#define MONTH 1
#define MONTH_3 2
#define YEAR 3
using namespace std;

int price[4];
int month[12];
int answer=1024*1024*1024*2-1;

int solve(int curMonth, int curCost ) {

	if (curMonth > 11) {
		if (answer > curCost) {
			answer = curCost;
		}
		return 0;
	}

	// day
	solve(curMonth+1, curCost+price[DAY]*month[curMonth]);
	// month
	solve(curMonth+1, curCost+price[MONTH]);
	// 3 month
	solve(curMonth+3, curCost+price[MONTH_3]);
	// year
	solve(curMonth+12, curCost+price[YEAR]);
	
}

int main()
{	
	int T;
	cin >> T;

	for (int t = 0 ; t<T ; ++t) {
        answer = 1024*1024*1024*2-1;
		cin >> price[DAY] >> price[MONTH] >> price[MONTH_3]>>price[YEAR];

		for (int i = 0 ; i <12 ; ++i ){
			cin >> month[i];
		}

		solve(0, 0);

		cout <<"#"<<t+1<< ' ' << answer<<'\n';
	}
	
	return 0;
}