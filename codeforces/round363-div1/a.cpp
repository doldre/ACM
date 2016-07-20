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
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
int A[maxn];
int dp[maxn][3];
// 0 休息， 1 比赛， 2 运动
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 3; k++) {
            dp[i][0] = min(dp[i-1][k] + 1, dp[i][0]);
        }
        if(A[i] & 1) {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }

        if((A[i] >> 1) & 1) {
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    printf("%d\n", ans);
    return 0;
}

