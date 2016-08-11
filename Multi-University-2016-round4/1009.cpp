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

const int MAXN = 300010;
const int MAXM = 800010;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to, nxt, cap, flow;
}edge[MAXM];

int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];

void init() {
    tol = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w, int rw = 0) {
    edge[tol].to = v; edge[tol].cap = w; edge[tol].nxt = head[u];
    edge[tol].flow = 0; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].nxt = head[v];
    edge[tol].flow = 0; head[v] = tol++;
}

// 起始点，终点， 点的数目，编号无所谓
int sap(int start, int end, int N) {
    memset(gap, 0, sizeof(gap));
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N) {
        if(u == end) {
            int Min = INF;
            for (int i = pre[u]; i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for (int i = pre[u]; i != -1; i = pre[edge[i^1].to]) {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].nxt) {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u]) {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag) {
            u = v;
            continue;
        }
        int Min = N;
        for (int i = head[u]; i != -1; i = edge[i].nxt) {
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}
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
        init();
        int s = n * n + n + 15, t = s + 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                add_edge(i * n + j, n * n + i, INF, 0);
                add_edge(i * n + j, n * n + j, INF, 0);
                add_edge(s, i * n + j, w[i][j] + w[j][i], 0);
            }
        }
        for (int i = 0; i < n; i++) {
            add_edge(n * n + i, t, A[str[i] - '0'], 0);
            add_edge(n * n + i, n * n + n + str[i] - '0', INF, 0);
        }
        for (int i = 0; i < 10; i++) {
            add_edge(n * n + n + i, t, B[i] - A[i], 0);
        }
        int min_cut = sap(s, t, n * (n - 1) / 2 + n + 10 + 2);
        // prln(min_cut);
        printf("Case #%d: %d\n", Cas, tot - min_cut);
    }
    return 0;
}

