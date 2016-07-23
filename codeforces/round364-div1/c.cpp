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
const int maxn = 1000 + 5;
const int maxv = 1000 + 5;
int d[maxn][maxn];

struct Dinic {
    struct edge {
        int to, cap, rev, num; 
        edge() {}
        edge(int to, int cap, int rev):to(to), cap(cap), rev(rev) {}
        edge(int to, int cap, int rev, int num):to(to), cap(cap),
        rev(rev), num(num) {}
    };
    
    vector<edge> G[maxv];
    int num_v;
    int level[maxv];
    int iter[maxv];

    void add_edge(int from, int to, int cap, int num) {
        G[from].push_back(edge(to, cap, (int)G[to].size(), num));
        G[to].push_back(edge(from, 0, (int)G[from].size() - 1, num));
    }
   
    void init(int num_v) {
        this->num_v = num_v;
        for (int i = 0; i <= num_v; i++) G[i].clear();
    }
    
    void bfs(int s) {
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if( d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        for (;;) {
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
    }
}dinic;
const int maxm = 3e4 + 5;
int n, m;
int s, t;
int weight[maxm];
int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        weight[i] = w;
        dinic.add_edge(x, y, 1, i);
        dinic.add_edge(y, x, 1, i);
    }
    int S = n + 1, T = n + 2;
    dinic.add_edge(S, s, inf, -1);
    dinic.add_edge(t, T, inf, -1);
    int flow = dinic.max_flow(S, T);
    if(flow > 2) {
        puts("-1");
    } else {
        vector<pii> ans;
        for (int i = 1; i <= n; i++) {
            for (auto &e: dinic.G[i]) {
                if(e.cap == 0) {
                    ans.push_back(pii(weight[e.num], e.num));
                }
            }
        }
        sort(ans.begin(), ans.end());
        int res = 0;
        for (int i = 0; i < flow; i++) {
            res += ans[i].xx;
        }
        printf("%d\n", res);
        printf("%d\n", flow);
        for (int i = 0; i < flow; i++) {
            printf("%d ", ans[i].yy);
        }
    }
    return 0;
}
