//SW2814.cpp
#include <iostream>

using namespace std;

int edges[11][11] = {0,};
int visit[11] = {0,};
int answer = 1;
int n,m ;


int solve (int row, int length) {

    if (length == n) {
        answer = n;
        return 0;
    }

    visit[row] = 1;
    
    for (int col =1;col<=n;++col) {
        if (edges[row][col] == 1 && visit[col] != 1) {
            cout << row << ' ' << col << ' '<<length<<'\n';
            solve(col, length+1);
        }
    }
    visit[row] = 0;
    
    if (length > answer ) {
        answer = length;
    }
    
    return 0;
    
}
int main () {
    int T;
    cin >> T;
    
    for (int t =0 ; t<T ; ++t) {
        
        cin >>n>>m;
        
        for (int i = 0 ; i < m ; ++i) {
            int x,y;
            cin >> x >> y;
            
            edges[x][y] = 1;
            edges[y][x] = 1;
        }
        
        for (int i=1 ; i<=n ; ++i) {
            solve(i,1);
        }
        
        cout <<"#"<<t+1<<' ' << answer<<'\n';
        answer = 1;

        for (int i = 0 ; i < 11 ; ++i) {
            for (int j = 0; j <11; ++j) {
                edges[i][j] = 0;
            }
        }
        
    }

    return 0;
}
