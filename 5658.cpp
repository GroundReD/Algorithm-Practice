//sw5658.cpp

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int n,k;
bool comp(long long a, long long b) {
	if(a>b) {
		return true;
	} else return false;
}
int main() {

	freopen("sample_input.txt","r",stdin);

	int T;
	cin>>T;

	for(int t = 1 ; t<=T ; t++){
		cin>>n>>k;

		deque<long long> v(n);

		for(int i = 0 ; i < n; i++) {
			char tmp;
			cin>>tmp;

			if(tmp<'A') {
				v[i] = tmp-'0';
			} else{
				v[i] = tmp-'A'+10;
			}
		}

		int count = n/4;

		vector<long long> value;
		set<long long, greater<long long> >  s;
		for(int i = 0;  i< count ; i++) {

			for(int a = 0 ; a<v.size() ; a+=count) {
				long long tmp=0;
				for(int b= 0 ; b<count ; b++){
					tmp*=16;
					tmp+=v[a+b];
				}
				s.insert(tmp);
			}
			int back = v.back();
			v.push_front(back);
			v.pop_back();
			
		}

		sort(value.begin(), value.end(), comp);
		// for (std::vector<long long>::iterator i = value.begin(); i != value.end(); ++i)
		// {
		// 	cout<<*i<<'\n';	
		// }

		long long index=1;
		long long answer = 0;
		for(set<long long>::iterator i = s.begin() ; i!= s.end();i++) {
			if(index == k ){
				answer = *i;
				break;
			} else index++;

		}
		cout<<"#"<<t<<' '<<answer<<'\n';
	}

	return 0;
}