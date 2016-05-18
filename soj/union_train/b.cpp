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
const int maxn = 2e5 + 5;
const ll inf = 1e18;
ll A[maxn];
ll dp[maxn];
ll W;
int dfs(int l, int r, int dl, int dr) {
    int mid = (l + r) >> 1;
    int dm = dl;
    if(l < mid) dm =  dfs(l, mid - 1, dl, dr);
    ll g = inf;
    for (int i = dm; i <= dr && i < mid; i++) {
        if(g >= dp[i] + (A[mid] - A[i+1]) * (A[mid] - A[i+1]) + W) {
            g = dp[i] + (A[mid] - A[i+1]) * (A[mid] - A[i+1]) + W;
            dm = i;
        }
    }
    int res = dm;
    dp[mid] = g;
    /* pr(mid); */
    /* pr(dm); */
    /* prln(dp[mid]); */
    if(mid < r) res = dfs(mid + 1, r, dm, dr);
    return res;
}
int n;

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        sa(n);
        scanf("%lld", &W);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &A[i]);
        }
        dfs(1, n, 0, n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
