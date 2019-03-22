//9102.cpp

#include <iostream>
#include <string>

using namespace std;
string check(string s) {
    int chk = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i]=='(') chk++;
        else if (s[i]==')') chk--;
        
        if(chk<0) return "NO";
    }
    
    if (chk==0) return "YES";
    else return "NO";
}

int main () {
    int T;
    cin >> T;
    
    for (int i = 0 ; i<T ; i++) {
        string s;
        cin >> s;
        cout << check(s)<<'\n';
    }
    return 0;
}


