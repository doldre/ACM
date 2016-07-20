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
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100;
ll dp[maxn][1<<10];
int n, m;
void dfs(int x, int pos, int cur, int mask) {
    if(pos >= n) {
        // prln(mask);
        dp[cur+1][mask] += dp[cur][x];
        return;
    }
    if((x >> pos) & 1) {
        dfs(x, pos + 1, cur, mask);
    }
    if(!((x >> pos) & 1)) {
        dfs(x, pos + 1, cur, mask | (1 << pos));
    }
    if(pos < n - 1 && !((x >> pos) & 1) &&
            !((x >> (pos + 1)) & 1)) {
        dfs(x, pos + 2, cur, mask);
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2) {
        if(n > m) swap(n, m);
        for (int i = 0; i <= m + 1; i++) {
            for (int j = 0; j < (1<<n); j++) {
                dp[i][j] ^= dp[i][j];
            }
        }

        dp[1][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1<<n); j++) {
                if(dp[i][j] > 0) dfs(j, 0, i, 0);
            }
        }
        printf("%lld\n", dp[m+1][0]);
    }
    return 0;
}

