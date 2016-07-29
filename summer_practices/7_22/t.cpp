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
const int maxn = 100 + 5;
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
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
    bool operator < (const Edge &b) const {
        return w < b.w;
    }
}edge[maxn*maxn];
int cnt_edge;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int N; scanf("%d", &N);
    cnt_edge = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x; scanf("%d", &x);
            edge[cnt_edge++] = Edge(i, j, x);
        }
    }
    int Q; scanf("%d", &Q);
    dsu.init(N);
    for (int i = 0; i < Q; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        dsu.merge(u, v);
    }
    int cost = 0;
    sort(edge, edge + cnt_edge);
    for (int i = 0; i < cnt_edge; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if(dsu.find(u) == dsu.find(v)) continue;
        // pr(u); prln(v);
        cost += w;
        dsu.merge(u, v);
    }
    printf("%d\n", cost);
    return 0;
}

