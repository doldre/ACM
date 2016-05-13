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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const ll inf = 0x3f3f3f3f3f3f;
const int maxn = 5e5 + 5;
ll dp[maxn];
ll sum[maxn];
int n, M;
int dfs(int l, int r, int dl, int dr) {
    int mid = (l + r) >> 1;
    int dm = dl;
    if(l < mid) dm = dfs(l, mid - 1, dl, dr);
    ll g = inf;
    int tm = dm;
    for (; dm <= dr && dm < mid; dm++) {
        if(g > dp[dm] + (sum[mid] - sum[dm]) * (sum[mid] - sum[dm]) + M) {
            g = dp[dm] + (sum[mid] - sum[dm]) * (sum[mid] - sum[dm]) + M;
            tm = dm;
        }
    }
    int res = tm;
    dp[mid] = g;
    if(mid < r) res = dfs(mid + 1, r, tm, dr);
    return res;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &M) == 2) {
        for (int i = 1; i <= n; i++) {
            int x;
            sa(x);
            sum[i] = sum[i - 1] + x;
        }
        dfs(1, n, 0, n);
        cout << dp[n] << endl;
    }
    return 0;
}
