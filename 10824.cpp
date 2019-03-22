//10824.cpp

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1,s2,s3,s4;
	cin >> s1>>s2>>s3>>s4;

	long long a= stoll(s1+s2);
	long long b= stoll(s3+s4);

	cout <<a+b<<'\n';

	return 0;
}