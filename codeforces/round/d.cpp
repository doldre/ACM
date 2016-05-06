/************************************************
 *Author        :mathon
 *Created Time  :五  5/ 6 00:42:47 2016
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
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1e5 + 10;
ll a[maxn], b[maxn];
ll n, k;

bool judge(ll x) {
    ll t = 0;
    for (int i = 0; i < n; i++) {
        t += max(0LL, a[i] * x - b[i]);
        if(t > k) return false;
    }
    return true;
}

int solve() {
    ll l = 0, r = 2e9 + 7;
    while(r - l > 1) {
        ll m = (l + r) >> 1;
        if(judge(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &b[i]);
    }
    ll ans = solve();
    cout << ans << endl;
    return 0;
}
