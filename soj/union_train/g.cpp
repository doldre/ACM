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
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
struct Edge {
    int to, w, c;
    Edge() {}
    Edge(int to, int w, int c): to(to), w(w), c(c) {}
};
vector<Edge> G[maxn];
int n, m;
int s, e;
pii path[maxn];
int dist[maxn];

int dij(int s) {
    fill(dist, dist + maxn, inf);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > que;
    que.push(pii(0, s));
    while(!que.empty()) {
        pii cur = que.top(); que.pop();
        if(cur.yy == e) return cur.xx;
        if(cur.xx > dist[cur.yy]) continue;
        int d = cur.xx, u = cur.yy;
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].to;
            if(G[u][i].c <= 0) continue;
            if(dist[v] > d + G[u][i].w) {
                dist[v] = d + G[u][i].w;
                path[v] = pii(u, i);
                que.push(pii(dist[v], v));
            }
        }
    }
    return inf;
}

void dfs(int v) {
    if(v == s) return;
    G[path[v].xx][path[v].yy].c -= 1;
    dfs(path[v].xx);
}

int solve() {
    int min_dist = dij(s);
    int ans = 0;
    while(true) {
        int d = dij(s);
        if(d == inf || d != min_dist) break;
        ans++;
        dfs(e);
    }
    return ans;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(Edge(v, w, 1));
        }
        scanf("%d%d", &s, &e);
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
