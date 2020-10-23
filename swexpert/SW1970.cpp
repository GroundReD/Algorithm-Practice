//SW1970.cpp
#include <iostream>

using namespace std;

int money[8] = {50000,10000,5000,1000,500,100,50,10};
int tmp[8] = {0,};
int answer[8] = {0,};
int _min = 1000001;


int solve (int n, int price, int k) {
    
    if (_min <= n) {
        return 1;
    }
    
    
    if (price == 0) {
        _min = n;
        for (int i  = 0 ; i <8 ;++i) {
            answer [i] = tmp[i];
        }
        return 0;
    }
    
    for (int i = k ; i < 8 ; ++i) {
        if (price - money[i] >= 0) {
            tmp[i] +=1;
            solve(n+1, price - money[i], i);
            tmp[i] -= 1;
        }
    }
    
    return 0;
    
    
}

int main() {
    
    int T;
    cin >> T;
    
    for (int t = 0 ; t<T ; t++) {
        int price;
        cin >> price;
        
        solve(0, price/10*10, 0);
        
        cout << "#" << t+1<< ' ';
        for (int i = 0 ; i<8;++i) {
            cout << answer[i] << ' ' ;
            answer[i] = 0;
        }
        cout << '\n';
        
        _min = 1000001;
        
    }
    
    return 0;
}