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
const int maxm = 200 + 5;
const int maxn = 4e4 + 5;

struct DSU {
    int par[maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    
    void merge(int a, int b) {
        a = find(a), b = find(b);
        par[a] = b;
    }
}dsu;

struct Edge {
    int to, w;
    Edge() {}
    Edge(int to, int w): to(to), w(w) {}
};

vector<Edge> G[maxn], querry[maxn];
int used[maxn];
int ans[maxm];
int dist[maxn];
int n, m;

void dfs(int u, int d, int fa) {
   dist[u] = d;
   for (int i = 0; i < (int)G[u].size(); i++) {
       int v = G[u][i].to;
       if(v == fa) continue;
       dfs(v, d + G[u][i].w, u);
   }
}

void tarjan(int u, int fa) {
    used[u] = true;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].to;
        if(v == fa) continue;
        tarjan(v, u);
        dsu.merge(v, u);
    }
    
    for (int i = 0; i < (int)querry[u].size(); i++) {
        int v = querry[u][i].to;
        if (used[v]) {
            ans[querry[u][i].w] = dist[u] + dist[v] - 2 * dist[dsu.find(v)];
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) {
            G[i].clear();
            querry[i].clear();
        }
        for (int i = 1; i <= n - 1; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(Edge(v, w));
            G[v].push_back(Edge(u, w));
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            querry[u].push_back(Edge(v, i));
            querry[v].push_back(Edge(u, i));
        }
        memset(dist, -1, sizeof(dist));
        dfs(1, 0, -1);
        memset(used, 0, sizeof(used));
        dsu.init(n);
        tarjan(1, -1);
        for (int i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

