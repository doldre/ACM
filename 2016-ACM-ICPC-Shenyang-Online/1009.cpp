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

const int MAXN = 300 + 5;
bool non_prime[MAXN][MAXN];
int f[MAXN][MAXN];
int key[MAXN], A[MAXN];
ll dp[MAXN];
ll sum[MAXN];
int n;

int judge(int i, int j) {
    if(i == j) return 0;
    if(i > j) return 1;
    if(f[i][j] != -1) return f[i][j];
    for (int k = i; k < j; k++) {
        if(non_prime[k][j] && judge(k+1, j-1) && judge(i, k-1)) {
            return f[i][j] = 1;
        }
    }
    return f[i][j] = 0;
}

ll solve() {
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        for (int j = 1; j < i; j++) {
            if(judge(j, i)) {
                dp[i] = max(dp[i], dp[j-1] + sum[i] - sum[j-1]);
            }
        }
    }
    return dp[n];
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        memset(f, -1, sizeof(f));
        memset(dp, 0, sizeof(dp));
        memset(non_prime, 0, sizeof(non_prime));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &key[i]);
        }
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            sum[i] = sum[i-1] + A[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(__gcd(key[i], key[j]) > 1) {
                    non_prime[i][j] = true;
                } else non_prime[i][j] = false;
            }
        }
        ll ans = solve();
        printf("%lld\n", ans);
    }
    return 0;
}

