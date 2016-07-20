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
const int maxn = 10;
const ll mod = 1e9 + 7;
int n, m;
ll dp[maxn + 1][1<<maxn];

ll fast_pow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2) {
        if(n < m) swap(n, m);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1<<m); j++) {
                if(dp[i][j] > 0) {
                    for (int k = 1; k < (1<<m); k++) {
                        int cnt = __builtin_popcount(k);
                        dp[i+1][j|k] = (dp[i+1][j|k] + dp[i][j] * fast_pow(2, cnt) % mod) % mod;
                    }
                }
            }
        }
        cout << dp[n][(1<<m)-1] << endl;
    } 
    return 0;
}

