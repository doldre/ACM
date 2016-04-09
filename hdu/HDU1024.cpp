#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 10;
const ll inf = (ll)1e13 + 7;
int S[maxn];
ll dp[maxn], pre_max[maxn];
int n, m;

int main() {
    while(scanf("%d%d", &m, &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &S[i]);
            dp[i] = 0;
            pre_max[i] = 0;
        }
        dp[0] = 0; pre_max[0] = 0;
        ll ans = -inf;
        for (int i = 1; i <= m; i++) {
            ans = -inf;
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j-1] + S[j], pre_max[j-1] + S[j]);
                pre_max[j-1] = ans;
                ans = max(ans, dp[j]);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
