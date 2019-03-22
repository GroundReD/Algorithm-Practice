// 1935.cpp

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string str;
double value[26];
stack<double> st;

double char2double(char ch) {
	int index = ch - 65;
	return value[index];
}

int main() {

	cin >>n;
	cin >>str;

	for(int i = 0 ; i < n ; i++ ){
		cin >> value[i];
	}

	double ans = 0;

	for(int i = 0 ; i <str.length() ; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			st.push(char2double(str[i]));
		} else {
			double b = st.top();
			st.pop();
			double a= st.top();
			st.pop();

			double tmp;
			if (str[i] == '+'){
				tmp = a+b; 
			} else if (str[i] == '-'){
				tmp = a-b;
			} else if (str[i] == '*'){
				tmp = a*b;
			} else if (str[i] == '/'){
				tmp = a/b;
			}
			st.push(tmp);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;

}