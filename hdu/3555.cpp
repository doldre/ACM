/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int N = 64;
ll dp[N][10][2][2];
int dig[N];
ll dfs(int pos, int pre, bool istrue, bool limit) {
    if(pos < 0) return istrue;
    if(dp[pos][pre][istrue][limit] != -1) return dp[pos][pre][istrue][limit];
    ll ret = 0;
    int last = limit ? dig[pos] : 9;
    for (int i = 0; i <= last; i++) {
        ret += 
            dfs(pos - 1, i, istrue || (pre == 4 && i == 9), limit && (i == last));
    }
    return dp[pos][pre][istrue][limit] = ret;
}

ll solve(ll x) {
    int len = 0;
    memset(dp, -1, sizeof(dp));
    while(x) {
        dig[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, 0, false, true);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        ll x; scanf("%lld", &x);
        printf("%lld\n", solve(x));
    }
    return 0;
}

