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

const int MAXN = 1e5 + 5;
int n, p;

struct Edge {
    int to, w;
    Edge() {}
    Edge(int to, int w):to(to), w(w) {}
};
vector<Edge> G[MAXN];

ll d[MAXN], dp[MAXN];
int que[MAXN], q_end, last;

ll Y(int x) {
    return dp[x] + d[x] * d[x];
}
ll X(int x) {
    return d[x];
}

ll ans;
void dfs(int u, int fa, ll dis) {
    d[u] = dis;
    // pr(u); prln(d[u]);
    if(u == 1) {
        dp[u] = 0;
    } else {
        for (; ; last++) {
            if(last == q_end - 1) {
                break;
            }
            int a = que[last], b = que[last+1];
            if(dp[b] + (d[u] - d[b]) * (d[u] - d[b]) >
                    dp[a] + (d[u] - d[a]) * (d[u] - d[a]))
                break;
        }
        int a = que[last];
        // pr(u); prln(a);
        dp[u] = dp[a] + (d[u] - d[a]) * (d[u] - d[a]) + p;
        // prln(dp[u]);
    }
    ans = max(ans, dp[u]);
    int m_last = last;
    vector<int> v;
    while(q_end >= 2) {
        int a = que[q_end - 1], b = que[q_end - 2];
        if((Y(u) - Y(a)) * (X(a) - (X(b))) > 
                (Y(a) - Y(b)) * (X(u) - X(a))) {
            break;
        }
        v.push_back(que[q_end-1]);
        q_end--;
    }
    que[q_end++] = u;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].to, w = G[u][i].w;
        if(v == fa) continue;
        dfs(v, u, dis + w);
    }
    q_end--;
    last = m_last;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        que[q_end++] = v[i];
    }
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &p);
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 0;  i < n - 1; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(Edge(v, w));
            G[v].push_back(Edge(u, w));
        }
        ans = 0;
        dfs(1, -1, 0);
        printf("%lld\n", ans - p);
    }
    return 0;
}

