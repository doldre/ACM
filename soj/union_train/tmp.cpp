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
const int maxn = 2000 + 5;
const int offset = 3000 + 5;
int TA[maxn], TB[maxn];
int dp[2][2*offset + 5];
int n;

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        sa(n);
        for (int i = 1; i <= n; i++) {
            sa(TA[i]); sa(TB[i]);
        }
        int now = 0;
        memset(dp, 0x3f, sizeof(dp));
        dp[0][offset] = 0;
        for (int i = 1; i <= n; i++) {
            now ^= 1;
            int ta = TA[i], tb = TB[i];
            memset(dp[now], 0x3f, sizeof(dp[now]));
            for (int j = -offset; j <= offset; j++) {
                if(dp[now^1][j + offset] == inf) continue;
                /* prln(dp[now][j + offset]); */
                if(j >= 0) {
                    if(j + ta <= offset) {
                        dp[now][j + ta + offset] = min(dp[now][j + ta + offset], dp[now ^ 1][j + offset] + ta);
                    }
                    dp[now][j - tb + offset] = min(dp[now][j - tb + offset], dp[now^1][j + offset] + max(0, tb - j));
                } else if(j < 0) {
                    if(j - tb >= -offset) {
                        dp[now][j - tb + offset] = min(dp[now][j - tb + offset], dp[now ^ 1][j + offset] + tb);
                    }
                    dp[now][j + ta + offset] = min(dp[now][j + ta + offset], dp[now ^ 1][j + offset] + max(0, ta + j));
                }
            }
        }
        int ans = inf;
        for (int i = -offset; i < offset; i++) {
            /* printf("%d ", dp[now][i + offset]); */
            ans = min(ans, dp[now][i + offset]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
