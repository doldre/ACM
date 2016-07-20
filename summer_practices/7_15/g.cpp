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
const int maxn = 300 + 5;
const int maxv = 300 + 5;
int d[maxn][maxn];

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

int A[maxn];
int ans[maxn][maxn];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n, m;
        scanf("%d%d", &n, &m);
        int s = n + m + 1, t = s + 1;
        dinic.init(t + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            dinic.add_edge(s, i, A[i] - A[i-1] - m);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &A[i]);
            dinic.add_edge(n + i, t, A[i] - A[i-1] - n);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dinic.add_edge(i, j + n, 19);
            }
        }
        int tmp = dinic.max_flow(s, t);
        // prln(tmp);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)dinic.G[i].size(); j++) {
                int u = i, v = dinic.G[i][j].to - n;
                if(v > m) continue;
                int c = 19 - dinic.G[i][j].cap + 1;
                ans[u][v] = c;
            }
        }
        printf("Matrix %d\n", Cas);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
            }
        }
    }
    return 0;
}

