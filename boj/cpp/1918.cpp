// 1918.cpp

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	string ans;
	stack<char> stk;

	for(int i = 0 ; i<str.length() ; i++) {
		
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
		}

		if(str[i] == '('){
			stk.push(str[i]);
		} else if (str[i] == ')') {
			while(stk.top() != '(') {
				cout<<stk.top();
				stk.pop();
			}
			stk.pop();
		} else if (str[i] == '*' || str[i] == '/') {

			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				cout<<stk.top();
				stk.pop();
			}

			stk.push(str[i]);
		} else if (str[i] == '+' || str[i] == '-') {
			while (!stk.empty() && stk.top() != '(') {
				cout<<stk.top();
				stk.pop();
			}
			stk.push(str[i]);
		}

	}

	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
	}

	return 0;
}