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

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1e4 + 5;
int p[MAXN], s[MAXN];
ll dp[MAXN];
int n, c;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            dp[j] = min(dp[j-1] + s[i], dp[j] + p[i] + (ll)j * c);
        }
        dp[0] = dp[0] + p[i];
    }
    ll ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

