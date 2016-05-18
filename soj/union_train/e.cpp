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
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
const int maxh = 5e5 + 5;
int h[maxn], dp[2][maxh];
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        int n;
        sa(n);
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            sa(h[i]);
            tot += h[i];
        }
        int now = 1;
        for (int i = 0; i < maxh; i++) dp[0][i] = dp[1][i] = -inf;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            memcpy(dp[now], dp[now^1], sizeof(dp[now]));
            for (int j = 0; j <= tot; j++) {
                if(j + h[i] <= tot) dp[now][j+h[i]] = max(dp[now][j+h[i]], dp[now^1][j] + h[i]);
                dp[now][abs(j-h[i])] = max(dp[now][abs(j-h[i])], dp[now^1][j] + h[i]);
            }
            now ^= 1;
        }
        if(dp[now^1][0] <= 0) {
            printf("GG\n");
        } else printf("%d\n", dp[now^1][0] / 2);
    }
    return 0;
}
