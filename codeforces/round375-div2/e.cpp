#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 200 + 5;
struct Edge {
    int v, f, nxt;
    Edge() {}
    Edge(int v, int f, int nxt):v(v), f(f), nxt(nxt) {}
}edge[MAXN*MAXN*2];
int head[MAXN], tot;
void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}
void add_edge(int u, int v, int f) {
    edge[tot] = Edge(v, f, head[u]);
    head[u] = tot++;
}
int deg[MAXN];
vector<pair<int, int> > ans;
int n, m;

void dfs(int u) {
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v, f = edge[i].f;
        if(f == -1) continue;
        if(f == 0) ans.push_back(make_pair(u, v));
        edge[i].f = edge[i^1].f = -1;
        dfs(v);
    }
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n, m; scanf("%d%d", &n, &m);
        init();
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add_edge(a, b, 0);
            add_edge(b, a, 0);
            deg[a]++; deg[b]++;
        }
        vector<int> v;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if(deg[i] % 2) {
                v.push_back(i);
            } else cnt++;
        }
        for (int i = 0; i < (int)v.size() - 1; i += 2) {
            int u = v[i], to = v[i+1];
            add_edge(u, to, 1);
            add_edge(to, u, 1);
        }
        ans.clear();
        for (int i = 1; i <= n; i++) dfs(i);
        printf("%d\n", cnt);
        for (auto x: ans) {
            printf("%d %d\n", x.first, x.second);
        }
    }
    return 0;
}
