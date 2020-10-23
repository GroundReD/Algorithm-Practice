// 1725.cpp

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> v(n+1);
	stack<int> st;

	for(int i = 1 ; i <= n ; i++) {
		cin>>v[i];
	}
	int ans = 0;
	st.push(0);
	for(int i = 1 ; i<=n+1; i++) {
		while(!st.empty() && v[i] < v[st.top()]) {
			int height = v[st.top()];
			st.pop();

			int width = i;
			if (!st.empty()) {
				width = i - st.top()-1;	
			}
			

			ans = max(ans, height*width);
		}

		st.push(i);
	}

	while(!st.empty()) {
		int height = v[st.top()];
        st.pop();
        int width = n;
        if (!st.empty()) {
            width = n-st.top()-1;
        }
        if (ans < width*height) {
            ans = width*height;
        }
	}

	cout <<ans;

	return 0;
}