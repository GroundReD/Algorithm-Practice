//14500.cpp 테트로노미노

#include <iostream>

using namespace std;
int board[500][500];
int N,M;

typedef struct POS {
    int row;
    int col;
} POS;

POS block[19][4] = {
    // ****
    { (POS){0,0}, (POS){0,1}, (POS){0,2}, (POS){0,3} },
    { (POS){0,0}, (POS){1,0}, (POS){2,0}, (POS){3,0} },
    // **
    // **
    { (POS){0,0}, (POS){0,1}, (POS){1,0}, (POS){1,1} },
    // ***
    // *
    { (POS){0,0}, (POS){0,1}, (POS){0,2}, (POS){1,0} },
    { (POS){0,0}, (POS){1,0}, (POS){2,0}, (POS){2,1} },
    { (POS){0,0}, (POS){0,1}, (POS){0,2}, (POS){-1,2} },
    { (POS){0,0}, (POS){0,1}, (POS){1,1}, (POS){1,2} },
    
    // *
    // **
    // *
    { (POS){0,0}, (POS){1,0}, (POS){2,0}, (POS){1,1} },
    { (POS){0,0}, (POS){0,1}, (POS){0,2}, (POS){1,1} },
    { (POS){0,0}, (POS){0,1}, (POS){0,2}, (POS){-1,1} },
    { (POS){0,0}, (POS){0,1}, (POS){1,1}, (POS){-1,1} },
    
    //  **
    // **
    { (POS){0,0}, (POS){0,1}, (POS){-1,1}, (POS){-1,2} },
    { (POS){0,0}, (POS){1,0}, (POS){1,1}, (POS){2,1} },
    // **
    //  **
    { (POS){0,0}, (POS){0,1}, (POS){1,1}, (POS){1,2} },
    { (POS){0,0}, (POS){0,1}, (POS){-1,1}, (POS){1,0} },
    
    // ***
    //   *
    { (POS){0,0}, (POS){0,1}, (POS){0,2}, (POS){1,2} },
    { (POS){0,0}, (POS){0,1}, (POS){1,0}, (POS){2,0} },
    { (POS){0,0}, (POS){1,0}, (POS){1,1}, (POS){1,2} },
    { (POS){0,0}, (POS){0,1}, (POS){-1,1}, (POS){-2,1} }
    
};

int main () {
    cin >> N>>M;
    
    for (int i =0 ; i <N ; ++i) {
        for (int j = 0 ; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    
    int max = 2<<30;
    
    for (int i =0 ; i <N ; ++i) {
        for (int j = 0 ; j < M; ++j) {
            for (int k = 0 ; k < 19 ; ++k) {
                int sum = 0;
                int cnt = 0;
                for(int l = 0 ; l < 4 ; ++l) {
                    int row = i+block[k][l].row;
                    int col = j+block[k][l].col;
                    
                    if (row>= 0 && row < N && col >=0 && col < M) {
                        sum+=board[row][col];
                        cnt++;
                    }
                }
                if (cnt == 4 && max < sum) {
                    max = sum;
                }
            }
        }
    }
    cout << max << '\n';
    
    
    
    return 0;
}


