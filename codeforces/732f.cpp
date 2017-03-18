#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl

const int MAXN = 4e5 + 5, MAXM = 4e5 + 5;
int fa[MAXN], cnt[MAXN];

int dfsNum, DFN[MAXN], low[MAXN];
bool insta[MAXN];
stack<int> sta;

struct Edge {
    int from, to, nxt, used;
}es[MAXM << 1];
int head[MAXN], tot;

void ginit() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add_edge(int u, int v) {
    es[tot].from = u;
    es[tot].to = v;
    es[tot].used = false;
    es[tot].nxt = head[u];
    head[u] = tot++;
}

int n, m;
int ans, maxid, maxx;
void tarjan(int u, int pre, bool flag) {
    DFN[u] = low[u] = ++dfsNum;
    insta[u] = true;
    sta.push(u);
    for (int i = head[u]; ~i; i = es[i].nxt) {
        int v = es[i].to;
        if(v == pre) continue;
        if(!es[i^1].used) {
            es[i].used = flag;
            if(flag) {
                // pr(u); prln(v);
            }
        }
        if(DFN[v] != -1) {
            if(insta[v]) {
                low[u] = min(DFN[v], low[u]);
            }
        } else {
            tarjan(v, u, flag);
            low[u] = min(low[u], low[v]);
        }
    }
    
    if(DFN[u] == low[u]) {
        int t = 0;
        while(true) {
            int v = sta.top(); sta.pop();
            insta[v] = false;
            fa[v] = u;
            t++;
            if(v == u) break;
        }
        cnt[u] = t;
        ans = max(ans, t);
        if(t > maxx) {
            maxx = t;
            maxid = u;
        }
    }
}

int main() {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
#endif
    ginit();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfsNum = 0;
    memset(DFN, -1, sizeof(DFN));
    ans = 0;
    maxx = 0;
    tarjan(1, -1, false);
    dfsNum = 0;
    memset(DFN, -1, sizeof(DFN));
    tarjan(maxid, -1, true);
    printf("%d\n", ans);
    for (int i = 0; i < tot; i++) {
        if(!es[i].used) {
            printf("%d %d\n", es[i].from, es[i].to);
        }
    }
    return 0;
}
