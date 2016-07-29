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
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int cnt_leaves[maxn];
int dp[maxn][2];
vector<int> G[maxn];

void dfs(int u, int fa) {
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u);
        cnt_leaves[u] += cnt_leaves[v];
        dp[u][0] += dp[v][0] + ((cnt_leaves[v] & 1) ? 1 : 2);
    }

    dp[u][1] = dp[u][0];
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dp[u][1] = min(dp[u][1], 
                dp[u][0] - dp[v][0] + dp[v][1] + ((cnt_leaves[v] & 1) ? 1 : -1));
    }
    if(G[u].size() == 1) {
        dp[u][0] = 0;
        dp[u][1] = 0;
        cnt_leaves[u] =  1;
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    int n;
    while(T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        memset(cnt_leaves, 0, sizeof(cnt_leaves));
        memset(dp, 0, sizeof(dp));
        if(n == 2) {
            puts("1");
            continue; 
        }
        int u = 1;
        for (u = 1; u <= n && G[u].size() == 1; u++);
        dfs(u, -1);
        printf("%d\n", dp[u][cnt_leaves[u] & 1]);
    }
    return 0;
}

