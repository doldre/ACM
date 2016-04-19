/************************************************
 *Author        :mathon
 *Created Time  :二  4/19 22:58:11 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll inf = 2e9;
ll quick_pow(ll x, ll n) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll solve(ll x) {
    bool isp = (x >= 0);
    x =  abs(x);
    vector<int> cnt;
    for (ll i = 2; i*i <= x; i++) {
        int c = 0;
        while(x % i == 0) {
            x /= i;
            c++;
        }
        if(c > 0) {
            cnt.push_back(c);
        }
    }
    if(x > 1) {
        cnt.push_back(1);
    }
    ll ans = 0;
    for (int i = 0; i < (int)cnt.size(); i++) {
        ans = gcd(ans, cnt[i]);
    }
    if(isp) return ans;
    else {
        while(ans % 2 == 0) ans /= 2;
        return ans;
    }
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        ll x;
        scanf("%lld", &x);
        ll ans = solve(x);
        printf("Case %d: %lld\n", Cas, ans);
    }
    return 0;
}
