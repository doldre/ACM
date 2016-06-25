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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;
const int maxk = 10 + 5;
char s[maxn], t[maxn];
int dp[maxk][maxn][maxn];
int lcp[maxn][maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m, K;
    scanf("%d%d%d", &n, &m, &K);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    s[0] = '*', t[0] = '#';
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(s[i] == t[j]) {
                lcp[i][j] = lcp[i-1][j-1] + 1;
            }
        }
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                if(s[j] == t[k]) {
                    int d = lcp[j][k];
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-d][k-d] + d);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
