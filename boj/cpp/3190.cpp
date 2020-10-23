//3190.cpp 뱀

#include <iostream>
#include <vector>

#define WALL 0
#define TRACE 1
#define APPLE 2

using namespace  std;


typedef struct _POS{
    int row;
    int col;
}POS;

typedef struct _DIR
{
    int second;
    char dir;
}DIR;

typedef struct _SNAKE
{
    POS head;
    POS tail;
    int length;
    int second;
    int head_dir;
    int tail_dir;
    // up,     right,     down,     left
    // 0,    1,        2,        3
    
}SNAKE;

POS move (POS cur, int dir) {
    switch(dir) {
        case 0:
            cur.row-=1;
            break;
        case 1:
            cur.col+=1;
            break;
        case 2:
            cur.row+=1;
            break;
        case 3:
            cur.col-=1;
            break;
        default:
            break;
            
    }
    return cur;
}

int main() {
    int n;
    cin >>n;
    
    // # of apple
    int k;
    cin >>k;
    
    int board[102][102] = {0,};
    
    for (int i = 1 ; i <=n ; i++) {
        for (int j =1; j <=n ; j++) {
            board[i][j] = 8;
        }
    }
    
    for (int i = 0 ; i < k ; i++) {
        int row,col;
        cin >> row >> col;
        board[row][col] = APPLE;
    }
    
    int l;
    cin >> l;
    vector<DIR> d(l);
    
    for (int i = 0 ; i < l;i++) {
        DIR tmp;
        cin >> tmp.second >> tmp.dir;
        d[i]=tmp;
    }
    
    int dir_head_count = 0;
    int dir_tail_count = 0;
    SNAKE snake={{1,1},{1,1},1,0,1,1};
    board[1][1] = TRACE;
    
    while (1) {
        if (snake.head.row > 0 && snake.head.row <=n && snake.head.col >0 && snake.head.col <= n) {
            
            if (d[dir_head_count].second == snake.second){
                if ( d[dir_head_count].dir == 'L') {
                    snake.head_dir = (snake.head_dir-1)%4;
                    if (snake.head_dir == -1) {
                        snake.head_dir = 3;
                    }
                } else if (d[dir_head_count].dir == 'D') {
                    snake.head_dir = (snake.head_dir+1)%4;
                }
                dir_head_count+=1;
            }
            snake.second +=1;
            snake.head = move(snake.head, snake.head_dir);
            
            if (board[snake.head.row][snake.head.col] == WALL || board[snake.head.row][snake.head.col] == TRACE) {
                break;
            } else if (board[snake.head.row][snake.head.col] == APPLE ) {
                snake.length++;
                board[snake.head.row][snake.head.col] = TRACE;
            } else {
                board[snake.head.row][snake.head.col] = TRACE;
                board[snake.tail.row][snake.tail.col] = 8;
                
                if (d[dir_tail_count].second+snake.length == snake.second)
                {
                    if ( d[dir_tail_count].dir == 'L')
                    {
                        snake.tail_dir = (snake.tail_dir-1)%4;
                        if (snake.tail_dir == -1) {
                            snake.tail_dir = 3;
                        }
                    } else if (d[dir_tail_count].dir == 'D')
                    {
                        snake.tail_dir = (snake.tail_dir+1)%4;
                    }
                    dir_tail_count+=1;
                }
                snake.tail = move(snake.tail, snake.tail_dir);
                
                // cout << snake.head.row << ' ' << snake.head.col << '\n';
                // cout << snake.tail.row << ' ' << snake.tail.col << '\n';
                // cout << snake.length << ' ' << snake.second << '\n';
            }
            
            // for (int i = 1 ; i <=n ; i++) {
            //     for (int j =1; j <=n ; j++) {
            //     	if (board[i][j] == 8){
            //     		cout << "0 ";
            //     	}else {
            //         	cout << board[i][j] << ' ';
            //         }
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
        }
        else {
            // cout<<"break\n";
            break;
        }
        
    }
    
    cout << snake.second<<'\n';
    
    return 0;
    
    
}

