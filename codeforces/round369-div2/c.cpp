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

const ll INF = 1e14;
const int MAXN = 100 + 5;
int P[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN];
int n, m, k;
int C[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &P[i][j]);
        }
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            for (int k = 0; k < MAXN; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    if(C[1] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[1][j][1] = P[1][j];
        }
    } else dp[1][C[1]][1] = 0;
    for (int i = 1; i < n; i++) {
        if(C[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k <= i; k++) {
                    if(C[i + 1] == 0) {
                        for (int nxt = 1; nxt <= m; nxt++) {
                            dp[i+1][nxt][k + (nxt != j)] = min(
                                    dp[i][j][k] + P[i+1][nxt], 
                                    dp[i+1][nxt][k + (nxt != j)]);
                        }
                    } else {
                        dp[i+1][C[i+1]][k + (C[i+1] != j)] = min(
                                dp[i][j][k], 
                                dp[i+1][C[i+1]][k + (C[i+1] != j)]);
                    }
                }
            }
        } else {
            int j = C[i];
            for (int k = 0; k <= i; k++) {
                if(C[i + 1] == 0) {
                    for (int nxt = 1; nxt <= m; nxt++) {
                        dp[i+1][nxt][k + (nxt != j)] = min(
                                dp[i][j][k] + P[i+1][nxt], 
                                dp[i+1][nxt][k + (nxt != j)]);
                    }
                } else {
                    dp[i+1][C[i+1]][k + (C[i+1] != j)] = min(
                            dp[i][j][k], 
                            dp[i+1][C[i+1]][k + (C[i+1] != j)]);
                }
            }
        }
    }
    ll ans = INF;
    for (int j = 1; j <= m; j++) {
        ans = min(dp[n][j][k], ans);
    }
    if(ans == INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
