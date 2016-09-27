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
const ll INF = 1e15;
const int MAXN = 3000 + 5;
map<ll, ll> dp[MAXN];
int A[MAXN];
int n;

ll cal(ll x) {
    for (int i = 0; i <= n; i++) dp[i].clear();
    dp[1][x] = abs(x - A[1]);
    for (int i = 2; i <= n; i++) {
        map<ll, ll> &mp = dp[i];
        for (auto x: dp[i-1]) {
            ll a = x.xx, b = x.yy;
            if(A[i] > a) {
                if(mp.find(A[i]) == mp.end()) {
                    mp[A[i]] = INF;
                }
                mp[A[i]] = min(mp[A[i]], b);
                if(mp.find(a+1) == mp.end()) {
                    mp[a+1] = INF;
                }
                mp[a+1] = min(mp[a+1], b + A[i] - (a + 1));
            } else {
                if(mp.find(a+1) == mp.end()) {
                    mp[a+1] = INF;
                }
                mp[a+1] = min(mp[a+1], b + a + 1 - A[i]);
            }
        }
    }
    ll ans = INF;
    for (auto x: dp[n]) {
        ans = min(ans, x.yy);
    }
    return ans;
}

ll solve() {
    ll l = 0, r = 1e9 + 1;
    ll m1 = (l + r) >> 1, m2 = (m1 + r) >> 1;
    while(l < r - 1) {
        if(cal(m1) < cal(m2)) {
            r = m2;
            m2 = m1;
            m1 = (m1 + l) >> 1;
        } else {
            l = m1;
            m1 = m2;
            m2 = (m2 + r) >> 1;
        }
    }
    ll m = (l + r) >> 1;
    ll ans = INF;
    ans = min(ans, cal(l));
    ans = min(ans, cal(m));
    ans = min(ans, cal(r));
    return ans;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    ll ans = solve();
    printf("%lld\n", ans);
    return 0;
}

