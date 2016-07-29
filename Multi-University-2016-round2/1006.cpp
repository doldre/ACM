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
const ll mod = 1e9 + 7;

inline ll fast_pow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

inline ll inv(ll x) {
    return fast_pow(x, mod - 2);
}

const int maxn = 1e5 + 5;
const int maxm = 4e5 + 5;
struct Edge {
    int to, nxt;
    Edge() {};
}edge[maxm];
int head[maxn], tot;
int n, m;

void init() {
    tot = 0;
    memset(head, -1, sizeof(int) * (n + 1));
}
void add_edge(int u, int v) {
    edge[tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}

int DFN[maxn], Low[maxn], dfsNum;
int w[maxn];
int rt[maxn], cnt_rt;
bool vised[maxn];
ll val[maxn];
ll ans[maxn];
ll Sum;
void dfs(int u) {
    val[u] = w[u];
    vised[u] = true;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(vised[v]) continue;
        dfs(v);
        val[u] = val[u] * val[v] % mod;
    }
}

ll tarjan(int u, int fa, int root) {
    // pr(u); prln(fa);
    ll res = w[u], sum = 0, rest = w[u];
    DFN[u] = Low[u] = ++dfsNum;
    int cnt_child = 0;
    bool is_cut = false;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(DFN[v] == -1) {
            cnt_child++;
            ll tmp = tarjan(v, u, root);
            res = (res * tmp) % mod;
            Low[u] = min(Low[v], Low[u]);
            if(fa == -1) {
                sum = (sum + tmp) % mod;
            }
            if(fa == -1 && cnt_child > 1) {
                is_cut = true;
            }
            if(fa != -1 && Low[v] >= DFN[u]) {
                is_cut = true;
                rest = (rest * tmp) % mod;
                sum = (sum + tmp) % mod;
            }
        } else {
            Low[u] = min(Low[u], DFN[v]);
        }
    }
    if(!is_cut) {
        // 孤立点
        if(fa == -1 && cnt_child == 0) {
            ans[u] = (Sum - w[u] + mod) % mod;
        } else {
            ans[u] = ((Sum - val[root] + mod) % mod + 
                    val[root] * inv(rest) % mod) % mod;
        }
    } else {
        ll val_fa = val[root] * inv(rest) % mod;
        // prln(sum);
        if(fa != -1) {
            sum = (sum + val_fa) % mod;
        }
        ans[u] = ((Sum - val[root] + mod) % mod + sum) % mod;
    }
    // prln(res);
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
        }
        init();
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        memset(vised, 0, sizeof(int) * (n + 1));
        cnt_rt = 0;
        Sum = 0;
        for (int i = 1; i <= n; i++) {
            if(!vised[i]) {
                rt[cnt_rt++] = i;
                dfs(i);
                Sum = (Sum + val[i]) % mod;
            }
        }
        memset(DFN, -1, sizeof(int) * (n + 1));
        dfsNum = 0;
        for (int i = 0; i < cnt_rt; i++) {
            int u = rt[i];
            // prln(u);
            tarjan(u, -1, u);
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            // prln(ans[i]);
            res = (res + ans[i] * i) % mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}

