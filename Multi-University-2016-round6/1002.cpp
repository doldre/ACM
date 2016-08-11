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
typedef long long LL;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int mod = 110119;
using namespace std;

int fac[mod + 7]; //定义范围为mod的范围！

void init() {
    fac[0] = 1;
    for (int i = 1; i <= mod; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
}

long long fastpow(long long a, long long b) {
    long long x = a % mod, ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        x = x * x % mod;
        b >>= 1;
    }
    return ret;
}
//求较大组合数取余
int C(int n, int m, int mod) {
    return m > n ? 0 : fac[n] * fastpow((long long)fac[m] * fac[n - m], mod - 2) % mod;
}

int lucas(long long n, long long m, int mod) {
    return m ? (long long)C(n % mod, m % mod, mod) * lucas(n / mod, m / mod, mod) % mod : 1;
}

ll cal(ll x, ll y) {
    ll tmp = 2 * y - x;
    if(tmp % 3 != 0) return 0;
    ll x2 = tmp / 3;
    ll x1 = y - 2 * x2;
    if(x1 < 0 || x2 < 0) return 0;
    return lucas(x1 + x2, x1, mod);
}

const int MAXR = 200;
pll ps[MAXR];
ll dp[MAXR];
ll n, m;
int r;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Cas = 0;
    init();
    while(scanf("%lld%lld%d", &n, &m, &r) == 3) {
        for (int i = 1; i <= r; i++) {
            scanf("%lld%lld", &ps[i].xx, &ps[i].yy);
        }
        sort(ps + 1, ps + r + 1);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= r; i++) {
            dp[i] = cal(ps[i].xx - 1, ps[i].yy - 1);
            for (int j = 1; j < i; j++) {
                if(ps[i].xx >= ps[j].xx && ps[i].yy >= ps[j].yy) 
                    dp[i] = (dp[i] - cal(ps[i].xx - ps[j].xx, ps[i].yy - ps[j].yy) * dp[j] % mod + mod) % mod;
            }
        }
        ll ans = cal(n - 1, m - 1);
        // prln(ans);
        for (int i = 1; i <= r; i++) {
            // pr(dp[i]);
            // prln(cal(n - X[i], m - Y[i]));
            if(ps[i].xx <= n && ps[i].yy <= m) 
                ans = (ans - dp[i] * cal(n - ps[i].xx, m - ps[i].yy) % mod) % mod;
        }
        ans = (ans % mod + mod) % mod;
        printf("Case #%d: %lld\n", ++Cas, ans);
    }
    return 0;
}

