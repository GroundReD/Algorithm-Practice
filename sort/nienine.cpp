//nienine.cpp

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	string a[] = {"","십","백","천","만","십만","백만","천만","억","십억","백억"};
	string c[] = {"", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};

	int num;
	cin >> num;

	stack<string> st;

	int dec = 0;
	while(num!=0) {
		int tmp = num%10;
		num /= 10;

		cout<<tmp << ' '<< num<<'\n';
		string tmpstr;
		if(tmp == 1 && dec != 0) {
			tmpstr = a[dec];
		}else {
			tmpstr = c[tmp]+a[dec];	
		}
		string *ptsr = tmpstr;
		
		st.push(tmpstr);
		dec++;
	}

	while(!st.empty()) {
		cout<<st.top();
		st.pop();
	}

	return 0;
}