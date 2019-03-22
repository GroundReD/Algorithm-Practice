//
//  main.cpp
//  sdstest
//
//  Created by Gred on 2018. 7. 22..
//  Copyright © 2018년 Gred. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    
    stack<int> s;
    
    for (int i = 0 ; i<n ; i++) {
        string tmp;
        cin >> tmp;
        
        if (tmp.compare("push") == 0) {
            int x;
            cin >> x;
            s.push(x);
        } else if (tmp.compare("top")==0) {
            if (!s.empty()) {
                int x = s.top();
                cout << x <<'\n';
            } else {
                cout<<-1<<'\n';
            }
            
        } else if (tmp.compare("size")==0) {
            cout<<s.size()<<'\n';
        
        } else if (tmp.compare("empty")==0) {
            if(s.empty()) {
                cout<<1<<'\n';
            } else {
                cout << 0<<'\n';
            }
            
        } else if (tmp.compare("pop") == 0) {
            if(!s.empty()) {
                int x = s.top();
                s.pop();
                cout <<x<<'\n';
            } else {
                cout << -1<<'\n';
            }
        }
    }
    
    
    
    return 0;
}
