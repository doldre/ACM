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
const int maxv = 30000+ 5;

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

const int maxn = 100 + 5;
char str[maxn];
int A[10], B[10];
int w[maxn][maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n; scanf("%d", &n);
        scanf("%s", str);
        for (int i = 0; i < 10; i++) {
            scanf("%d%d", &A[i], &B[i]);
        }
        int tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &w[i][j]);
                tot += w[i][j];
            }
        }
        dinic.init(maxv - 1);
        int s = n * n + n + 15, t = s + 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dinic.add_edge(i * n + j, n * n + i, inf);
                dinic.add_edge(i * n + j, n * n + j, inf);
                dinic.add_edge(s, i * n + j, w[i][j] + w[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            dinic.add_edge(n * n + i, t, A[str[i] - '0']);
            dinic.add_edge(n * n + i, n * n + n + str[i] - '0', inf);
        }
        for (int i = 0; i < 10; i++) {
            dinic.add_edge(n * n + n + i, t, B[i] - A[i]);
        }
        int min_cut = dinic.max_flow(s, t);
        // prln(min_cut);
        printf("Case #%d: %d\n", Cas, tot - min_cut);
    }
    return 0;
}

