//14502.cpp 연구소
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _POS {
    int x;
    int y;
    int visit;
} POS;

int board[8][8];
int N,M;
vector<POS> zero_pos;
vector<POS> two_pos;
vector<POS> recover_two_pos;
int answer = 2<<30;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void calc() {
    queue<POS> q;
    for (int i = 0 ; i < two_pos.size() ; ++i) {
        q.push(two_pos[i]);
    }
    
    while(!q.empty()) {
        POS tmp = q.front();
        q.pop();
        for (int i = 0 ; i < 4 ; ++i) {
            int x = tmp.x + dx[i];
            int y = tmp.y + dy[i];
            
            if (x < 0 || x >= N || y < 0 || y>=M || board[x][y] != 0) continue;
            
            board[x][y] =2;
            q.push((POS){x,y,0});
            recover_two_pos.push_back((POS){x,y,0});
        }
        
    }
}

void comp() {
    int safe=0;
    for(int i = 0 ; i < N ; ++i) {
        for (int j = 0 ; j < M ; ++j) {
//            cout<< board[i][j] << ' ';
            if ( board[i][j] == 0 ) {
                safe+=1;
            }
        }
//        cout<<'\n';
    }
//    cout << '\n';
    
    for (vector<POS>::iterator i = recover_two_pos.begin(); i != recover_two_pos.end(); ++i)
    {
        board[i->x][i->y] = 0;
    }
    
    recover_two_pos.clear();
    
    if (answer < safe) {
        answer = safe;
    }
}
int main() {
    
    
    cin >> N>>M;
    
    for (int i = 0; i<N ; ++i) {
        for (int j=0;j<M;++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                zero_pos.push_back((POS){i,j,0});
            } else if ( board[i][j] == 2) {
                two_pos.push_back((POS){i,j,0});
            }
        }
    }
    
    for (vector<POS>::iterator i = zero_pos.begin(); i != zero_pos.end(); ++i)
    {
        board[i->x][i->y] = 1;
        for (vector<POS>::iterator j = i+1; j != zero_pos.end(); ++j)
        {
            board[j->x][j->y] = 1;
            for (vector<POS>::iterator k = j+1 ; k != zero_pos.end(); ++k)
            {
                board[k->x][k->y] = 1;
                calc();
                comp();
                board[k->x][k->y] = 0;
            }
            board[j->x][j->y] = 0;
            
        }
        board[i->x][i->y] = 0;
    }
    
    cout << answer<<'\n';
    return 0;
}

