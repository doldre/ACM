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


const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5;

ll fast_pow(ll x, int n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = res * x % MOD;;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

struct Edge {
    int to, nxt;
    ll w;
}es[MAXM * 2];

int head[MAXN], tot;
void edge_init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add_edge(int u, int v, ll w) {
    es[tot].to = v; es[tot].w = w;
    es[tot].nxt = head[u];
    head[u] = tot++;
}
int n, m;

ll dis[MAXN];
ll A[MAXM*3];
ll P[65], sz;
bool can[65];
vector<ll> V;
void dfs(int u, ll s) {
    if(dis[u] == -1) dis[u] = s;
    else {
        A[++sz] = dis[u] ^ s;
        return ;
    }
    V.push_back(dis[u]);
    for (int i = head[u]; ~i; i = es[i].nxt) {
        int v = es[i].to;
        dfs(v, s ^ es[i].w);
    }
}

int cnt_bit[65][2];
ll Gauss_Base() {
    for (int i = 62; i >= 0; i--) {
        for (int j = 1; j <= sz; j++) {
            if((A[j] >> i) & 1) {
                P[i] = A[j];
                break;
            }
        }
        for (int j = 1; j <= sz; j++) {
            if((A[j] >> i) & 1) A[j] ^= P[i];
        }
    }
    int cnt = 0;
    memset(can, 0, sizeof(can));
    for (int i = 62; i >= 0; i--) {
        for (int j = 62; j >= 0; j--) {
            if((P[i] >> j) & 1) can[j] = true;
        }
        if(P[i] != 0) cnt++;
    }

    memset(cnt_bit, 0, sizeof(cnt_bit));

    for (ll x: V) {
        for (int i = 0; i <= 62; i++) {
            cnt_bit[i][(x>>i)&1]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 62; i++) {
        ll one = (ll)cnt_bit[i][0] * cnt_bit[i][1];
        one %= MOD;
        ll zero = (ll)cnt_bit[i][1] * (cnt_bit[i][1] - 1) / 2 + 
            (ll)cnt_bit[i][0] * (cnt_bit[i][0] - 1) / 2;
        zero %= MOD;

        ans += one * fast_pow(2, i + cnt - (can[i] != 0)) % MOD;
        ans %= MOD;
        if(can[i] != 0) ans += zero * fast_pow(2, i + cnt - 1) % MOD;
        ans %= MOD;
    }
    return ans;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    edge_init();
    memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if(dis[i] == -1) {
            V.clear();
            sz = 0;
            dfs(i, 0);
            memset(P, 0, sizeof(P));
            ans += Gauss_Base();
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

