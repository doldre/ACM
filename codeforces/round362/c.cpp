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
const ll MOD = 1e9 + 7;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll mod_multiply(ll a, ll b, ll mod) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) {
            res = (res + a) % mod;
        }
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    ll t = 1;
    ll flag = 1;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        flag = (flag * a) % 2;
        t = mod_multiply(t, a, MOD - 1);
    }
    t = (t - 1 + MOD - 1) % (MOD - 1);
    ll p = mod_pow(2, t, MOD);
    ll q = p;
    if(flag == 0) p = (p + 1) % MOD;
    else p = (p - 1) % MOD;
    p = mod_multiply(p, mod_pow(3, MOD - 2, MOD), MOD);
    cout << p << "/" << q << endl;
    return 0;
}

