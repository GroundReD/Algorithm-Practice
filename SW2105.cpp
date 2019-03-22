#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T,n;
    cin >> T;
    
    for (int t = 0; t < T; ++t)
    {
        
        vector< vector<int> > v;
        
        int answer = -1;
        bool isContinue=true;
        
        cin >> n;
        if (n < 4 || n> 20) {
            continue;
        }
        
        for (int i = 0; i < n; ++i)
        {
            vector<int> tmp;
            for (int j = 0; j < n; ++j)
            {
                int s;
                cin >> s;
                tmp.push_back(s);
            }
            v.push_back(tmp);
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout<< i << ", " << j<<endl;
                if((i == 0 && j == 0)
                   || (j == 0)
                   || (j == n)
                   || (i == n && j == n)   )
                    continue;
                
                for (int row = 1; row<=n ; row++)
                {
                    for (int  col= 1 ; col <= n; col++)
                    {
                        vector<int> mem(101);
                        mem[v[i][j]] = 1;
                        isContinue = true;
                        
                        if (col+j < n
                            && j-col >= 0
                            && i+row+col < n
                            && 2*(row+col) > answer)
                        {
                            cout<<"start"<<endl;
                            int curRow = i;
                            int curCol = j;
                            //right down
                            for (int k = 0; k<row ;++k)
                            {
                                curRow++;
                                curCol++;
                                
                                if (curCol < n && mem[v[curRow][curCol]] != 1) {
                                    mem[v[curRow][curCol]] = 1;
                                    cout << "(" << curCol <<"," << curRow << ") : " << v[curRow][curCol] <<endl;
                                } else {
                                    isContinue = false;
                                    break;
                                }
                            }
                            
                            if (!isContinue) continue;
                            
                            for (int k = 0; k<col ;++k)
                            {
                                curRow++;
                                curCol--;
                                
                                if (curCol<n && mem[v[curRow][curCol]] != 1) {
                                    mem[v[curRow][curCol]] = 1;
                                    cout << "(" << curCol <<"," << curRow << ") : " << v[curRow][curCol] <<endl;
                                } else {
                                    isContinue = false;
                                    break;
                                }
                            }
                            
                            if (!isContinue) continue;
                            
                            for (int k = 0; k<row ;++k)
                            {
                                curRow--;
                                curCol--;
                                
                                if (mem[v[curRow][curCol]] != 1) {
                                    mem[v[curRow][curCol]] = 1;
                                    cout << "(" << curCol <<"," << curRow << ") : " << v[curRow][curCol] <<endl;
                                } else {
                                    isContinue = false;
                                    break;
                                }
                            }
                            
                            if (!isContinue) continue;
                            
                            for (int k = 0; k<col ;++k)
                            {
                                curRow--;
                                curCol++;
                                
                                if (mem[v[curRow][curCol]] != 1) {
                                    mem[v[curRow][curCol]] = 1;
                                    cout << "(" << curCol <<"," << curRow << ") : " << v[curRow][curCol] <<endl;
                                } else if (curRow != i && curCol != j ){
                                    isContinue = false;
                                    break;
                                }
                            }
                            
                            if (!isContinue) continue;
                            
                            answer = 2*(col+row);
                            cout<<answer<<endl;
                        }
                        
                    }
                }
            }
            
        }
        cout << answer <<endl;
    }
    
    return 0;
}
