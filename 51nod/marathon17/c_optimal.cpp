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
const ll mod = 1e9 + 7;
const int MAXN = 100 + 5;
const int MAXM = 5e4 + 5;
int mat[MAXN][MAXN][MAXN]; //邻接矩阵
ll f[MAXN], g[MAXN]; //g[i] 表示i的倍数的路径数，f[i] 表示i的路径数
int n, m;
int a[MAXM], b[MAXM], c[MAXM];
ll dp[MAXN];
vector<int> fac[MAXN];
void init() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            fac[j].push_back(i);
        }
    }
}

ll dfs(int x, int u) {
    if(dp[u] != -1) return dp[u];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if(mat[x][u][i]) {
            ans = (ans + mat[x][u][i] * (dfs(x, i) + 1)) % mod;
        }
    }
    return dp[u] = ans;
}

ll cal(int x) {
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if(dp[i] == -1) dfs(x, i);
        ans = (ans + dp[i]) % mod;
    }
    return ans;
}
    
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        for (auto x: fac[c[i]]) {
            mat[x][a[i]][b[i]]++;
        }
    }
    for (int x = 1; x <= 100; x++) {
        g[x] = cal(x);
    }
    for (int i = 100; i > 0; i--) {
        f[i] = g[i];
        for (int j = i + i; j <= 100; j += i) {
            f[i] = (f[i] - f[j] + mod) % mod;
        }
    }
    printf("%lld\n", f[1]);
    int T; scanf("%d", &T);
    while(T--) {
        int x, y;
        scanf("%d%d", &x, &y);
        set<int> s;
        for (auto i: fac[c[x]]) {
            s.insert(i);
            mat[i][a[x]][b[x]]--;
        }
        c[x] = y;
        for (auto i: fac[c[x]]) {
            s.insert(i);
            mat[i][a[x]][b[x]]++;
        }
        for (auto i: s) {
            g[i] = cal(i);
        }
        for (int i = 100; i > 0; i--) {
            f[i] = g[i];
            for (int j = i + i; j <= 100; j += i) {
                f[i] = (f[i] - f[j] + mod) % mod;
            }
        }
        printf("%lld\n", f[1]);
    }
    return 0;
}

