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
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

struct DSU {
    int par[maxn];
    int n;
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
    int from, to, w;
    Edge() {}
    Edge(int from, int to, int w):from(from), to(to), w(w) {}
}es[maxm];

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

vector<Edge> G[maxn];

int n, m;
int child[maxn];
double tmp;

void dfs(int u, int fa) {
    child[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].to;
        if(v == fa) continue;
        dfs(v, u);
        child[u] += child[v];
        tmp += ((double)child[v] * (n - child[v])) * G[u][i].w * 2;
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
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            es[i] = Edge(u, v, w);
        }
        
        sort(es, es + m, cmp);
        dsu.init(n);
        ll tot_w = 0;
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < m; i++) {
            Edge &e = es[i];
            int u = e.from, v = e.to, w = e.w;
            if(dsu.find(u) == dsu.find(v)) continue;
            tot_w += w;
            dsu.merge(u, v);
            G[u].push_back(Edge(u, v, w));
            G[v].push_back(Edge(v, u, w));
        }
        for (int i = 0; i <= n; i++) child[i] = 0;
        tmp = 0;
        dfs(1, -1);
        printf("%lld %.2f\n", tot_w, tmp / ((double)n*(n-1)));
    }
    return 0;
}

