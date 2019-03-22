//
//  queue
//
//  Created by Gred on 2018. 7. 22..
//  Copyright © 2018년 Gred. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    
    queue<int> q;
    
    for (int i = 0 ; i<n ; i++) {
        string tmp;
        cin >> tmp;
        
        if (tmp.compare("push") == 0) {
            int x;
            cin >> x;
            q.push(x);
        } else if (tmp.compare("front")==0) {
            if (!q.empty()) {
                int x = q.front();
                cout << x <<'\n';
            } else {
                cout<<-1<<'\n';
            }
            
        } else if (tmp.compare("back")==0) {
            if (!q.empty()) {
                int x = q.back();
                cout << x <<'\n';
            } else {
                cout<<-1<<'\n';
            }
            
        } else if (tmp.compare("size")==0) {
            cout<<q.size()<<'\n';
            
        } else if (tmp.compare("empty")==0) {
            if(q.empty()) {
                cout<<1<<'\n';
            } else {
                cout << 0<<'\n';
            }
            
        } else if (tmp.compare("pop") == 0) {
            if(!q.empty()) {
                int x = q.front();
                q.pop();
                cout <<x<<'\n';
            } else {
                cout << -1<<'\n';
            }
        }
    }
    
    
    
    return 0;
}

