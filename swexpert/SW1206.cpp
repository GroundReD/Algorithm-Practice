//SW1206.cpp
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int _max(int a, int b, int c, int d) {
    int m=-1;
    m = max(a,b);
    m = max(m,c);
    m = max(m,d);

    return m;
}
 
int main() {
    for(int i = 0 ; i<10 ; i++) {
        int N,answer=0;
        cin >> N;
        vector<int> apart(N);

        for (int j = 0; j<N ; j++) {
            cin>>apart[j];
        }

         for (int j = 2; j<N-2 ; j++) {
             int max_height = _max(apart[j-2],apart[j-1],apart[j+1],apart[j+2]);
             if(apart[j]- max_height > 0 ) {
                 answer += apart[j]-max_height;
             }
         }
         cout<<"#"<<i+1<<" "<< answer<<endl;

    }
 
return 0;
}