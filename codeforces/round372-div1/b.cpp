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

typedef pair<long long, int> pli;
const ll INF = 1e15;
const int MAXN = 1e3 + 5;
const int MAXM = 1e4 + 5;
struct Edge {
    int u, v, w, next;
    bool flag;
    Edge() {}
    Edge(int u, int v, int w, int next):u(u), v(v), w(w), next(next) {}
}es[MAXM<<1];
int head[MAXN], tot;
int n, m, L, s, t;
ll dist[MAXN];
int pre[MAXN];

void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add_edge(int u, int v, int w) {
    es[tot] = Edge(u, v, w, head[u]);
    head[u] = tot++;
}

ll djikstra() {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        pre[i] = -1;
    }
    dist[s] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > que;
    que.push(pli(0, s));
    while(!que.empty()) {
        pli cur = que.top(); que.pop();
        ll d = cur.xx, u = cur.yy;
        if(d > dist[u]) continue;
        for (int i = head[u]; ~i; i = es[i].next) {
            int v = es[i].v, w = es[i].w;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = i;
                que.push(pli(dist[v], v));
            }
        }
    }
    return dist[t];
}

bool modify(int d) {
    bool ok = false;
    for (int u = t; ~u; u = es[pre[u]].u) {
        if(es[pre[u]].flag) {
            es[pre[u]].w = L - d + 1;
            es[pre[u]^1].w = L - d + 1;
            ok = true;
            break;
        }
    }
    return ok;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        if(w == 0) {
            es[tot-1].w = 1;
            es[tot-1].flag = true;
        }
        add_edge(v, u, w);
        if(w == 0) {
            es[tot-1].w = 1;
            es[tot-1].flag = true;
        }
    }
    bool ok = false;
    while(true) {
        ll d = djikstra();
        if(d < L) {
            if(!modify(d)) break;
        } else if(d == L) {
            ok = true;
            break;
        } else {
            break;
        }
    }
    if(ok) {
        printf("YES\n");
        for (int i = 0; i < m; i++) {
            printf("%d %d %d\n", es[i<<1].u, es[i<<1].v, es[i<<1].w);
        }
    } else printf("NO\n");
    return 0;
}

