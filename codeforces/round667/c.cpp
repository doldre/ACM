#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int dp[maxn][4];
string buf[maxn][4];
string str;
int main(void)
{
    set<string> res;
    cin >> str;
    int len = str.size();
    dp[len][2] = 1;
    buf[len][2] = "";
    for (int i = len - 2; i >= 5; i--) {
        string t = str.substr(i, 2);
        if((dp[i+2][2] && buf[i+2][2] != t) || dp[i+2][3]) {
            dp[i][2] = 1;
            buf[i][2] = t;
            res.insert(t);
        }
        t = str.substr(i, 3);
        if(dp[i+3][2] || (dp[i+3][3] && buf[i+3][3] != t)) {
            dp[i][3] = 1;
            buf[i][3] = t;
            res.insert(t);
        }
    }
    cout << res.size() << endl;
    for (string x: res) {
        cout << x << endl;
    }
    return 0;
}
