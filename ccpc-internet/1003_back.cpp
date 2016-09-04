// writted by dnvtmf
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000000007
#define FI first
#define SE second
#define PB emplace_back
#define VI vector<int>
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 100010;
struct edge {int next, to, cost;} e[NUM * 2];
int head[NUM], tot;
void gInit() {memset(head, -1, sizeof(head)); tot = 0;}
void add_edge(int u, int v, int c)
{
    e[tot] = (edge) {head[u], v, c};
    head[u] = tot++;
}
int n, V[NUM], w1[NUM], w2[NUM], id[NUM], ans[NUM];
//w1是从该点出发最后回到该点的最大值
//w2是从该点出发有一次不回来的最大值
//id是不回来的路的子树根节点
void dfs1(int u, int fa)
{
    w1[u] = V[u];
    w2[u] = V[u];
    id[u] = u;
    for(int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        dfs1(v, u);
        int tmp = max(0, w1[v] - e[i].cost - e[i].cost);
        w1[u] += tmp;
    }
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        int tmp = w1[u] - max(0, w1[v] - e[i].cost * 2) + max(0, w2[v] - e[i].cost);
        if(tmp > w2[u]) {
            w2[u] = tmp;
            id[u] = v;
        }
    }
}
//sum1同w1,sum2同w2
void dfs2(int u, int fa, int sum1, int sum2)
{
    ans[u] = max(w1[u] + sum2, w2[u] + sum1);
    int W1 = w1[u];
    int W2 = w2[u];
    int Id = id[u];
    W2 += sum1;
    if(W2 <= W1 + sum2) {
        W2 = W1 + sum2;
        Id = fa;
    }
    W1 += sum1;
    for(int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        if(v == Id) {
            int tmp1 = sum1 + V[u], tmp2 = sum2 + V[u];
            for(int j = head[u]; ~j; j = e[j].next) {
                int vv = e[j].to;
                if(vv == fa || v == vv) continue;
                int tmp = max(0, w1[vv] - e[j].cost - e[j].cost);
                tmp2 = max(tmp1 + max(0, w2[vv] - e[j].cost), tmp2 + tmp);
                tmp1 += tmp;
            }
            tmp1 = max(0, tmp1 - e[i].cost - e[i].cost);
            tmp2 = max(0, tmp2 - e[i].cost);
            dfs2(v, u, tmp1, tmp2);
        }
        else {
            int tmp = max(0, w1[v] - e[i].cost - e[i].cost);
            int tmp1 = max(0, W1 - tmp - e[i].cost - e[i].cost);
            int tmp2 = max(0, W2 - tmp - e[i].cost);
            dfs2(v, u, tmp1, tmp2);
        }
    }
}
int main()
{
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        gInit();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &V[i]);
        }
        for(int i = 1; i < n; ++i) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        dfs1(1, -1);
        dfs2(1, -1, 0, 0);
        printf("Case #%d:\n", cas);
        for(int i = 1; i <= n; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
