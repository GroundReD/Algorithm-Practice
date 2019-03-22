// 1620.cpp

#include <iostream>
#include <map>
#include <string>

using namespace std;

int string2int(string tmp) {
    int answer = 0;
    for(int i = 0 ; i < tmp.size() ; i++) {
        int a = tmp[i]-'0';
        answer*=10;
        answer += a;
    }
    
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    map<int, string> num2pokemon;
    map<string, int> pokemon2num;
    
    for(int i = 1 ; i<= n ; i++){
        string tmp;
        cin >>tmp ;
        
        num2pokemon[i] = tmp;
        pokemon2num[tmp] = i;
    }
    
    cin.clear();
    
    for(int i = 0 ;i <m ; i++){
        string tmps;
        int tmpi;
        cin >>tmps;
        
        if(tmps[0] >= '0' && tmps[0] <= '9') {
            tmpi = string2int(tmps);
            cout << num2pokemon[tmpi]<<'\n';
        } else {
            cout<<pokemon2num[tmps]<<'\n';
        }
        cin.clear();
    }
    
    return 0;
}
