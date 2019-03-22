//1152.cpp

#include <iostream>
#include <string>

using namespace std;

int main() {

	int answer = 0;
	string str;
	getline(cin,str);

	for(int i = 0; i<str.size() ; i++) {
		if(str[i]==' ') {
			answer++;
		}
	}

	if(str[0]==' ') {
		answer--;
	}

	if(str[str.size()-1] == ' '){
		answer--;
	}

	cout<<answer+1;

	return 0;
}