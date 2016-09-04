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
const int MOD = 1e6 + 3;
ll fact[MOD];

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll cal_2(ll x, ll n) {
    ll res = n;
    x--;
    while(x) {
        res += x / 2;
        x /= 2;
    }
    return res;
}

ll n, k;

ll cal() {
    ll t = mod_pow(2, n, MOD);
    if(k > t) return 0;
    ll res = 1;
    for (int i = 0; i < k; i++, t--) {
        res = res * t % MOD;
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%lld%lld", &n, &k);
    int cnt = 0;
    ll tmp = k - 1;
    for (; tmp; tmp >>= 1) cnt++;
    if(cnt > n) return 0 * printf("1 1\n");
    ll inv2 = mod_pow(2, MOD - 2, MOD); 
    ll c = cal_2(k, n);
    ll a = mod_pow(mod_pow(2, n, MOD), k, MOD);
    ll b = cal();
    a = a * mod_pow(inv2, c, MOD) % MOD;
    b = b * mod_pow(inv2, c, MOD) % MOD;
    printf("%lld %lld\n", (a - b + MOD) % MOD, a);
    return 0;
}

