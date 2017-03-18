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

const int MAXN = 1000 + 5;
const int INF = 0x3f3f3f3f;
struct Bomb {
    ll x, y, r, c;
    Bomb(ll x, ll y, ll r, ll c):x(x), y(y), r(r), c(c) {}
    Bomb() {}
}bombs[MAXN];

bool judge(const Bomb &a, const Bomb &b) {
    ll sqr_dis = (a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y);
    return sqr_dis <= a.r * a.r;
}
int n;
vector<int> G[MAXN];

int dfsNum, DFN[MAXN], low[MAXN];
int fa[MAXN], min_cost[MAXN], gid;
int indeg[MAXN];
bool insta[MAXN];
stack<int> sta;
void tarjan(int u) {
    DFN[u] = low[u] = ++dfsNum;
    sta.push(u);
    insta[u] = true;
    for (auto v: G[u]) {
        if(DFN[v] != -1) {
            if(insta[v]) low[u] = min(low[u], DFN[v]);
        } else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == DFN[u]) {
        int mc = INF;
        ++gid;
        while(true) {
            int v = sta.top(); sta.pop();
            insta[v] = false;
            fa[v] = gid;
            mc = min((ll)mc, bombs[v].c);
            if(u == v) break;
        }
        min_cost[gid] = mc;
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            int x, y, r, c;
            scanf("%d%d%d%d", &x, &y, &r, &c);
            bombs[i] = Bomb(x, y, r, c);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i == j) continue;
                if(judge(bombs[i], bombs[j])) {
                    G[i].push_back(j);
                }
            }
        }
        memset(DFN, -1, sizeof(DFN));
        dfsNum = 0;
        map<pii, bool> used;
        gid = 0;
        memset(indeg, 0, sizeof(indeg));
        for (int i = 1; i <= n; i++) {
            if(DFN[i] == -1) {
                tarjan(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto j: G[i]) {
                int u = fa[i], v = fa[j];
                if(u == v) continue;
                if(!used[pii(u, v)]) {
                    indeg[v]++;
                    used[pii(u, v)] = true;
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= gid; i++) {
            if(indeg[i] == 0) {
                ans += min_cost[i];
            }
        }
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}
