//SW1226.cpp

#include <iostream>

using namespace std;

char _map[16][16] = {-1,};
int _visit[16][16]  = {0,};
int answer = 0;

typedef struct {
    int row;
    int col;
}POS;

int solve (POS pos) {
    
    POS nextPos = {0,0};
    
    if (_map[pos.row][pos.col] == '3') {
        answer = 1;
        return 1;
    }
    
    _visit[pos.row][pos.col] = 1;
    
    //up
    if (pos.row-1 >= 0 && _map[pos.row-1][pos.col] != '1' && _visit[pos.row-1][pos.col] != 1) {
        nextPos.row = pos.row-1;
        nextPos.col = pos.col;
        solve(nextPos);
    }
    // right
    if (pos.col+1 < 16 && _map[pos.row][pos.col+1] != '1' && _visit[pos.row][pos.col+1] != 1) {
        nextPos.row = pos.row;
        nextPos.col = pos.col+1;
        solve(nextPos);
        
    }
    
    // down
    if (pos.row+1 < 16 && _map[pos.row+1][pos.col] != '1' && _visit[pos.row+1][pos.col] != 1) {
        nextPos.row = pos.row+1;
        nextPos.col = pos.col;
        solve(nextPos);
        
    }
    
    // left
    if (pos.col-1 >= 0 && _map[pos.row][pos.col-1] != '1'&& _visit[pos.row][pos.col-1] != 1) {
        nextPos.row = pos.row;
        nextPos.col = pos.col-1;
        solve(nextPos);
        
    }
    
    _visit[pos.row][pos.col] = 0;
    
    return 0;
}

int main(){
    
    for (int t = 0 ; t<10 ; ++t) {
        int index;
        cin >>index;
        POS start_pos = {0,0};
        
        for (int i = 0; i<16 ; ++i) {
            for (int j = 0 ; j<16; ++j) {
                cin >> _map[i][j];
                if (_map[i][j] == '2') {
                    start_pos.row = i;
                    start_pos.col = j;
                }
            }
        }
        solve(start_pos);
        
        cout << "#"<<t+1<<" "<<answer<<endl;
        answer = 0;
    }
    
    
    return 0;
}

