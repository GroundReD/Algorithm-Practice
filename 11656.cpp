//11656.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	int s_size = s.size();
	vector<string> v(s_size);

	for (int i =0 ; i<s_size ; i++) {
		v[i] = s.substr(i,s_size-i);
	}

	sort(v.begin(), v.end());
	for (int i =0 ; i<s_size ; i++) {
			cout << v[i] <<'\n';
		}
	return 0;
}