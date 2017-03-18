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

const int MAXN = 750 + 5;
ll A[MAXN];
ll dp[MAXN][MAXN];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    dp[n+1][0] = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i + 1; j++) {
            dp[i][j] = max(min(dp[i+1][j] + A[i], A[i]), dp[i+1][j-1]);
        }
        dp[i][0] = min(dp[i+1][0] + A[i], A[i]);
    }
    while(m--) {
        ll x; scanf("%lld", &x);
        int ans = lower_bound(dp[1], dp[1] + n, -x) - dp[1];
        cout << ans << endl;
    }
    return 0;
}

