#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int T;
    T =10;
 
    for(int i = 0 ; i<T ; i++) {
        vector<int> point(101);
        int n;
        int tmp, max=-1;
        int index;
        cin >> n;
        for (int j = 0;j<1000;++j) {
            tmp =0;
            cin >> tmp;
            point[tmp]++;
        }
        for (int i = 100;i>=0;--i) {
            if( max < point[i] ) {
                max = point[i];
                index = i;
            }
        }
        cout <<"#"<<n<<" "<<index<<endl;
    }
 
return 0;
}