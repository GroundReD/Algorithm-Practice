#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct {
	int start, end;
} MEET;

bool compare(MEET a, MEET b) {
	if(a.end == b.end) {
		return a.start < b.start;
	} else {
		return a.end < b.end;
	}
}

int main () {

	int n;
	int answer = 0;
	cin >> n;
	vector<MEET> v;

	for (int i = 0; i < n; ++i)
	{
		MEET tmp;
		cin >> tmp.start >> tmp.end;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);

	int last = -1;

	for (int i = 0; i < n; ++i)
	{
		if(last <= v[i].start) {
			last = v[i].end;
			answer++;
		}
	}

	cout << answer;
	return 0;
}