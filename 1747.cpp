//1747.cpp

#include <iostream>
#include  <vector>
using namespace std;

bool isPrime[2000001];

void getPrime() {

	for(int i = 0 ; i <=2000000 ; i++) {
		isPrime[i]= true;
	}

	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;

	for(int i = 2;i<=2000000 ; i++){
		if(isPrime[i]) {
			for(int j = i+i ; j<=2000000 ; j+=i) {
				isPrime[j] = false;
			}	
		}
	}
}

bool checkpel(int n){
	int dec = 1000000;
	int index = 7;

	while(1){
		if (n/dec != 0) {
			break;
		}

		dec/=10;
		index--;
	}
	vector<int> v(index);
	
	for(int i = 0 ; i < index ; i++) {
		v[i]=n%10;
		n/=10;
	}

	int left = 0;
	int right = index-1;

	while(left<=right) {
		if(v[left] != v[right]) {
			return false;
		}
		left++;
		right--;
	}

	return true;

}

int findpel(int n) {
	for(int i = n ; i <= 2000000 ; i++) {
		if(isPrime[i] && checkpel(i)) {

			return i;
		}
	}

	return 0;
}


int main(int argc, char const *argv[])
{

	int n; 
	cin >>n;

	getPrime();
	cout<<findpel(n)<<'\n';

	return 0;
}