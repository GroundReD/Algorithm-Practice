#include <stdio.h>
#define LEFT -1
#define RIGHT 1

int t[4];
int check_lotate[5] = {1,};

int rotate_one(int t, int dir) {
    int bit = 0;
    
    if( dir == 1 ) {
        bit = t%10;
        t /= 10;
        t += bit*10000000;
    } else if ( dir == -1 ) {
        bit = t/10000000;
        t = (t%10000000) * 10;
        t += bit;
    }
    
    return t;
}

int rotate_all(int n, int dir, int r_dir) {
    
    if(n<0 || n>3) {
        return 0;
    }
    t[n] = rotate_one(t[n],r_dir);
    
    if (dir == LEFT && check_lotate[n] == 0) {
        rotate_all(n-1, LEFT, -r_dir);
    } else if (dir == RIGHT && check_lotate[n+1] == 0) {
        rotate_all(n+1, RIGHT, -r_dir);
    } else if (dir == 0){
        if (check_lotate[n] == 0) {
            rotate_all(n-1, LEFT, -r_dir);
        }
        if (check_lotate[n+1] == 0) {
            rotate_all(n+1, RIGHT, -r_dir);
        }
    }
    
    return 0;
}

int main() {
    
    int rotate_num;
    int rotate_t, rotate_dir;
    int dir;
    int i,j;
    int result;
    
    scanf("%d",&t[0]);
    scanf("%d",&t[1]);
    scanf("%d",&t[2]);
    scanf("%d",&t[3]);
    
    
    scanf("%d",&rotate_num);
    
    for ( i=0;i<rotate_num;i++) {
        scanf("%d %d", &rotate_t, &rotate_dir);
        
        check_lotate[0] = 1;
        check_lotate[4] = 1;
        for (j=1;j<4;j++) {
            if ( (t[j-1]/100000)%10 == (t[j]/10)%10 ) {
                check_lotate[j] = 1;
            } else {
                check_lotate[j] = 0;
            }
        }
        
        rotate_all(rotate_t-1, 0, rotate_dir);
    }
    
    result = t[0]/10000000 + t[1]/10000000*2 + t[2]/10000000*4 + t[3]/10000000*8;
    
    printf("%d\n",result);
    return 0;
    
}
