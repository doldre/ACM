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

const int MAXN = 1e5 + 5;
int V[MAXN];
int W1[MAXN], W2[MAXN];
int path[MAXN];
struct Edge {
    int v, c, next;
    Edge() {}
};
int head[MAXN], tot;
Edge edge[MAXN<<2];
void ginit() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add_edge(int u, int v, int c) {
    edge[tot].v = v;
    edge[tot].c = c;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int n;

void dfs1(int u, int fa) {
    W1[u] = V[u];
    W2[u] = V[u];
    path[u] = u;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(v == fa) continue;
        dfs1(v, u);
        W1[u] += max(0, W1[v] - 2 * edge[i].c);
    }
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(v == fa) continue;
        int tmp = W1[u] - max(0, W1[v] - 2 * edge[i].c);
        tmp += max(0, W2[v] - edge[i].c);
        if(tmp > W2[u]) {
            W2[u] = tmp;
            path[u] = v;
        }
    }
}

int ans[MAXN];
void dfs2(int u, int fa, int sum1, int sum2) {
    // printf("u = %d fa = %d sum1 = %d sum2 = %d\n", u, fa, sum1, sum2);
    // printf("W1[u] = %d W2[u] = %d\n", W1[u], W2[u]);
    ans[u] = max(W1[u] + sum2, W2[u] + sum1);
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(v == fa) continue;
        if(v == path[u]) {
            int t = V[u];
            for (int i = head[u]; ~i; i = edge[i].next) {
                int vv = edge[i].v;
                if(vv == fa || vv == v) continue;
                int tmp = W1[u] - max(0, W1[vv] - 2 * edge[i].c);
                tmp += max(0, W2[vv] - edge[i].c);
                t = max(tmp, t);
            }
            // pr(v);
            // prln(t);
            int nsum1 = sum1 + W1[u] - max(0, W1[v] - 2 * edge[i].c) - edge[i].c * 2;
            nsum1 = max(0, nsum1);
            int tmp1 = sum1 + t - max(0, W1[v] - 2 * edge[i].c) - edge[i].c;
            int tmp2 = sum2 + W1[u] - max(0, W1[v] - 2 * edge[i].c) - edge[i].c;
            int nsum2 = max(tmp1, tmp2);
            nsum2 = max(0, nsum2);
            dfs2(v, u, nsum1, nsum2);
        } else {
            int nsum1 = sum1 + W1[u] - max(0, W1[v] - 2 * edge[i].c) - edge[i].c * 2;
            nsum1 = max(0, nsum1);
            int tmp1 = sum1 + W2[u] - max(0, W1[v] - 2 * edge[i].c) - edge[i].c;
            int tmp2 = sum2 + W1[u] - max(0, W1[v] - 2 * edge[i].c) - edge[i].c;
            int nsum2 = max(tmp1, tmp2);
            nsum2 = max(0, nsum2);
            dfs2(v, u, nsum1, nsum2);
        }
    }
}    

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        ginit();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &V[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        dfs1(1, -1);
        dfs2(1, -1, 0, 0);
        printf("Case #%d:\n", Cas);
        for (int i = 1; i <= n; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

