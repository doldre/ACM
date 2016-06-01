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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 10000 + 5;
int dfn[maxn], low[maxn];
int ans = 0;
int n, m;
vector<pii> G[maxn];

int stamp;
void dfs(int v, int fa) {
    dfn[v] = low[v] = ++stamp;
    for (int i = 0; i < (int)G[v].size(); i++) {
        int u = G[v][i].xx;
        if(G[v][i].yy == fa) continue;
        if(dfn[u] == -1) {
            dfs(u, G[v][i].yy);
            low[v] = min(low[u], low[v]);
        } else {
            low[v] = min(low[v], dfn[u]);
        }
        if(low[u] > dfn[v]) ans++;
    }
    /* prln(v); */
    /* pr(dfn[v]); prln(low[v]); */
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }
        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(pii(v, i));
            G[v].push_back(pii(u, i));
        }
        stamp = 0;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if(dfn[i] == -1) {
                dfs(i, -1);
            }
        }
        printf("Case %d: %d\n", Cas, ans);
    }
    return 0;
}
