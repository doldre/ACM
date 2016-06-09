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
const int maxn = 5000 + 10;
vector<int> G[maxn], T[maxn];
int n, m;

int in[maxn], sccno[maxn], dfn[maxn], low[maxn], timestp, scc;
int stk[maxn], top;
void tarjan(int u) {
    dfn[u] = low[u] = ++timestp;
    in[u] = true;
    stk[++top] = u;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(low[u] == dfn[u]) {
        ++scc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            sccno[v] = scc;
            if(v == u) break;
        }
    }
}

bool vis[maxn];
int match[maxn];
bool dfs(int u) {
    for (int i = 0; i < (int)T[u].size(); i++) {
        int v = T[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) G[i].clear(), T[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }

        scc = timestp = 0;
        memset(dfn, 0, sizeof(dfn));
        for (int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);

        for (int i = 1; i <= n; i++) {
            int u = sccno[i];
            for (int j = 0; j < (int)G[i].size(); j++) {
                int v = sccno[G[i][j]];
                if(u == v) continue;
                T[u].push_back(v);
            }
        }

        int matches = 0;
        memset(match, -1, sizeof(match));
        for (int i = 1; i <= scc; i++) {
            memset(vis, 0, sizeof(vis));
            matches += dfs(i);
        }
        printf("%d\n", scc - matches);
    }
    return 0;
}
