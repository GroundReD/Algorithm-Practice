// 16236.cpp

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct POS {
    int row;
    int col;
}pos;

typedef struct FISH {
    pos prePos;
    pos curPos;
    int size;
    int eat;
    int time;
} fish;

int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};
int n;
vector<vector<int> > map;
vector<pos> fishes[7];

//작은 물고기 남아있으면 false 아니면 true
bool check(fish tmp) {
    
    int checkEmpty = 0;
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j<n ; j++) {
            if(tmp.size > map[i][j] && map[i][j]!=0 ){
                return false;
            }
            checkEmpty += map[i][j];
        }
    }
    if(checkEmpty == 0) {
        return true;
    }
    
    return true;
}

void clearQueue(queue<fish> &q) {
    queue<fish> empty;
    swap(q,empty);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    
    map.assign(n, vector<int> (n,99999999));
    
    pos start;
    for(int i =0 ; i<n ; i++) {
        for(int j =0 ; j<n ; j++) {
            cin>>map[i][j];
            if(map[i][j] == 9) {
                start.row = i;
                start.col = j;
                map[i][j] = 0;
            } else if (map[i][j] != 0) {
                pos tmp = {i,j};
                fishes[map[i][j]].push_back(tmp);
            }
        }
    }
    
    
    queue<fish> q;
    int answer = 0;
    fish baby = {start, start, 2,0,0};
    pos preVisit = start;
    q.push(baby);
    
    while(!q.empty()) {
        fish curFish = q.front();
        pos curPos = curFish.curPos;
        q.pop();
        
        //잡아먹음
        if(map[curPos.row][curPos.col] < curFish.size && map[curPos.row][curPos.col] != 0) {
            while(!q.empty()) {
                fish tmpFish=q.front();
                q.pop();
                if(map[tmpFish.curPos.row][tmpFish.curPos.col] < tmpFish.size && tmpFish.time == curFish.time && map[tmpFish.curPos.row][tmpFish.curPos.col] != 0) {
                    if(tmpFish.curPos.row < curFish.curPos.row) {
                        curFish = tmpFish;
                        curPos = curFish.curPos;
                        curFish.prePos = curFish.curPos;
                    } else if(tmpFish.curPos.row == curFish.curPos.row) {
                        if(tmpFish.curPos.col < curFish.curPos.col) {
                            curFish = tmpFish;
                            curPos = curFish.curPos;
                            curFish.prePos = curFish.curPos;
                        }
                    }
                }
            }
            curFish.prePos = curFish.curPos;
            // cout<<curFish.curPos.row<<' '<<curFish.curPos.col << " size : "<<curFish.size<<" eat : " <<curFish.eat<<" time : " <<curFish.time<<'\n';
            map[curFish.curPos.row][curFish.curPos.col] = 0;
            
        }
        
        if(check(curFish)) {
            answer = curFish.time;
            break;
        }
        
        // 위 왼쪽 오른쪽 아래 순으로 탐색
        for(int i = 0 ; i<4 ; i++) {
            fish nextFish = curFish;
            pos nextPos = {curFish.curPos.row+dy[i],curFish.curPos.col+dx[i]};
            // 화면 밖으로 넘어가면
            if(nextPos.row< 0 || nextPos.row >=n || nextPos.col <0 || nextPos.col >=n) {
                // cout<<endl;
                continue;
            }
            
            if(nextPos.row == curFish.prePos.row && nextPos.col == curFish.prePos.col) {
                continue;
            }
            
            //몸집 큰 물고기
            if(map[nextPos.row][nextPos.col] > curFish.size) {
                // cout<<endl;
                continue;
            }// 0이거나 같은 크기 물고기
            else if(map[nextPos.row][nextPos.col] == 0 || map[nextPos.row][nextPos.col] == curFish.size) {
                nextFish.prePos = curPos;
                nextFish.curPos = nextPos;
                nextFish.time++;
                q.push(nextFish);
            }//작은 물고기
            else if(map[nextPos.row][nextPos.col] < curFish.size) {
                nextFish.prePos = curPos;
                nextFish.curPos = nextPos;
                nextFish.time++;
                nextFish.eat++;
                if(nextFish.eat ==nextFish.size) {
                    nextFish.size++;
                    nextFish.eat = 0;
                }
                // map[nextPos.row][nextPos.col] = 0;
                // clearQueue(q);
                q.push(nextFish);
                break;
            }
        }
    }
    
    cout<<answer<<'\n';
    
    
    return 0;
}

