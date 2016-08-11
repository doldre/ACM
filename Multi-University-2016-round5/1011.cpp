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
const ll mod = 1e9 + 7;
const int maxn = 1000 + 5;
ll dp[maxn][maxn];
int n, m;
int A[maxn], B[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &B[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(A[i] == B[j]) {
                    dp[i][j] = (dp[i-1][j-1] + 1) % mod;
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j] + 
                        dp[i][j-1] - dp[i-1][j-1] + mod) % mod;
            }
        }
        printf("%lld\n", dp[n][m]);
    }
    return 0;
}

