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

const int mod = 1e9 + 7;
const int maxn = 16;
ll d[maxn + 5][maxn + 5], dp[2][(1<<maxn) + 100];
ll memo[maxn + 5][maxn + 5];

void update(int a, int b, int m, int cur) {
    if((b >> m) & 1) {
        dp[cur][b ^ (1 << m)] = (dp[cur][b ^ (1 << m)] + 
                dp[cur ^ 1][a]) % mod;
    }
}

void init() {
    // for (int n = 1; n <= maxn; n++) {
        int n = 16;
        for (int m = 1; m <= maxn; m++) {
            int cur = 0;
            memset(dp[cur], 0, sizeof(dp[cur]));
            dp[0][(1<<m) - 1] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cur ^= 1;
                    memset(dp[cur], 0, sizeof(dp[cur]));
                    for (int  k = 0; k < (1<<m); k++) {
                        update(k, k << 1, m, cur);
                        if(i && !((k >> (m-1)) & 1)) {
                            update(k, (k << 1) ^ (1 << m) ^ 1, m, cur);
                        }
                        if(j && !(k & 1)) {
                            update(k, (k << 1) ^ 3, m, cur);
                        }
                    }
                    if(j == m - 1) {
                        d[i + 1][m] = dp[cur][(1<<m)-1];
                    }
                }
            }
            // d[n][m] = dp[cur][(1<<m)-1];
            // pr(n); pr(m);
            // prln(d[n][m]);
        }
    // }
}

ll cal(int n, int m) {
    if(memo[n][m] != -1) return memo[n][m];
    ll ans = 0;
    for (int mask = 0; mask < (1<<(m-1)); mask++) {
        // prln(mask);
        int last = -1;
        vector<int> w;
        for (int i = 0; i < m - 1; i++) {
            if((mask >> i) & 1) {
                w.push_back(i - last);
                last = i;
            }
        }
        w.push_back(m - 1 - last);
        ll g[maxn + 1];
        for (int i = 1; i <= n;  i++) {
            ll tmp = 1;
            for (int j = 0; j < (int)w.size(); j++) {
                // pr(i); prln(w[j]);
                tmp = tmp * d[i][w[j]] % mod;
                // pr(d[i][w[j]]);
                // prln(tmp);
            }
            g[i] = tmp;
            // printf("i = %d, g[i] = %lld\n", i, g[i]);
        }

        ll f[maxn + 1];
        for (int i = 1; i <= n; i++) {
            f[i] = g[i];
            for (int j = 1; j < i; j++) {
                f[i] = (f[i] - f[j] * g[i - j] % mod + mod) % mod;
            }
            // pr(i); prln(f[i]);
        }
        if(__builtin_popcount(mask) & 1) {
            ans = (ans - f[n] + mod) % mod;
        } else {
            ans = (ans + f[n] + mod) % mod;
        }
    }
    return memo[n][m] = ans;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    memset(memo, -1, sizeof(memo));
    init();
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        ll ans = cal(n, m);
        printf("%lld\n", ans);
    }
    return 0;
}

