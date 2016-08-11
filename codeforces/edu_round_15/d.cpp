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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    ll ans = 0;
    ans += min(d, k) * a;
    d -= min(d, k);
    if(b * k <= a * k + t) {
        ans += d * b;
        d = 0;
    } else {
        ll t1 = d / k;
        ans += t1 * (a * k+ t);
        d -= t1 * k;
        ans += min(b * d, t + a * d);
    }
    cout << ans << endl;
    return 0;
}

