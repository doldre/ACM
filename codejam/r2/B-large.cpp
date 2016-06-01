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
const int maxn = 200 + 5;
int N, K;
double P[maxn];
double dp[maxn][maxn], v[maxn];

double solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i-1][j] * (1.0 - v[i]);
            if(j > 0) dp[i][j] += dp[i-1][j-1] * v[i];
        }
    }
    return dp[K][K/2];
}
int main(void)
{
#ifdef LOCAL
    freopen("B-small.txt", "r", stdin);
    freopen("B-small-out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        sort(P, P + N);
        double res = 0;
        for (int i = 0; i < K; i++) {
            int cnt = 1;
            for (int j = 0; j < i; j++) {
                v[cnt++] = P[j];
            }
            for (int j = N - 1; j >= N - (K - i); j--) {
                v[cnt++] = P[j];
            }
            res = max(res, solve());
        }
        printf("Case #%d: %.9f\n", Cas, res);
    }
    return 0;
}
