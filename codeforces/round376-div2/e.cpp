#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int MAXN = 2e5 + 5;
int A[MAXN];
ll sum[MAXN];
ll dp[MAXN][2];
int n;
const ll inf = 1e16;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        sum[i] = sum[i-1] + A[i];
        dp[i][0] = dp[i][1] = -inf;
    }
    ll max_a = sum[2], max_b = sum[2] - sum[3];
    dp[2][0] = max_a;
    dp[3][1] = max_b;
    dp[3][0] = sum[3];
    max_a = max(sum[2], sum[3]);
    for (int i = 4; i <= n; i++) {
        pr(max_a); prln(max_b);
        dp[i][0] = max_b + sum[i];
        dp[i][1] = max_a - sum[i];
        pr(dp[i][0]); prln(dp[i][1]);
        max_a = max(max_a, dp[i][0]);
        max_b = max(max_b, dp[i][1]);
    }
    printf("%lld\n", max(dp[n][0], dp[n][1]));
}
