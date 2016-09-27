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

const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 5;
const int maxv = 2000 + 5;

struct Dinic {
    struct edge {
        int to, cap, rev; 
        edge() {}
        edge(int to, int cap, int rev):to(to), cap(cap), rev(rev) {}
    };
    
    vector<edge> G[maxv];
    int num_v;
    int level[maxv];
    int iter[maxv];

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
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
const int MAXN = 2000 + 5, MAXM = 20000 + 5;
int U[MAXM], V[MAXM], W[MAXM];
int dis[MAXN];
int n, m;
vector<int> G[MAXN];

void bfs() {
    for (int i = 0; i <= n; i++) dis[i] = inf; 
    queue<int> que;
    dis[1] = 0;
    que.push(1);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i];
            if(dis[v] == inf) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
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
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &U[i], &V[i], &W[i]);
            G[U[i]].push_back(V[i]);
            G[V[i]].push_back(U[i]);
        }
        bfs();
        dinic.init(n);
        for (int i = 1; i <= m; i++) {
            if(dis[V[i]] == dis[U[i]] + 1) {
                dinic.add_edge(U[i], V[i], W[i]);
            } else if(dis[U[i]] == dis[V[i]] + 1) {
                dinic.add_edge(V[i], U[i], W[i]);
            }
        }
        int ans = dinic.max_flow(1, n);
        printf("%d\n", ans);
    }
    return 0;
}


