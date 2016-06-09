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
typedef pair<ll, int> pli;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll inf = 1e15;
const int maxn = 10000 + 5;
struct Edge {
    int to, dis;
    ll cap;
    Edge() {}
    Edge(int to, ll cap, int dis):to(to), cap(cap), dis(dis) {}
};

vector<Edge> G[maxn];
int n, m, K;

ll dist[maxn];
ll dijk(ll value) {
    for (int i = 0; i <= n; i++) dist[i] = inf;
    dist[1] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > que;
    que.push(pli(0, 1));
    while(!que.empty()) {
        pli cur = que.top(); que.pop();
        ll d = cur.xx;
        int u = cur.yy;
        if(d > dist[u]) continue;
        if(u == n) return dist[u];
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].to;
            if(G[u][i].cap < value) continue;
            if(dist[v] > dist[u] + G[u][i].dis) {
                dist[v] = dist[u] + G[u][i].dis;
                que.push(pli(dist[v], v));
            }
        }
    }
    return inf;
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
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v, cap, dis;
            scanf("%d%d%d%d", &u, &v, &cap, &dis);
            G[u].push_back(Edge(v, cap, dis));
            G[v].push_back(Edge(u, cap, dis));
        }
        ll l = 0, r = inf;
        while(l < r - 1) {
            ll m = (l + r) >> 1;
            if(dijk(m) > K) {
                r = m;
            } else {
                l = m;
            }
        }
        if(l == 0) {
            printf("Poor RunningPhoton!\n");
        } else {
            printf("%lld\n", l);
        }
    }
    return 0;
}
