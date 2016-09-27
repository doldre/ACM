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

const ll MOD = 1e9 + 7;
const int MAXK = 1e3 + 10, MAXT = 100 + 10;
const int zero = MAXK * MAXT*2;
ll dp[2][MAXK*MAXT*4];

ll pre_sum[2][MAXK*MAXT*4];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int a, b, k, t;
    scanf("%d%d%d%d", &a, &b, &k, &t);
    dp[0][zero] = 1;
    int now = 0;
    for (int i = 1; i < 4*MAXK*MAXT; i++) {
        pre_sum[0][i] = pre_sum[0][i-1] + dp[0][i];
    }
    for (int i = 1; i <= t; i++) {
        now ^= 1;
        ll sum = 0;
        for (int j = 1; j <= 4*k + 1; j++) {
            sum = (sum + (2*k - abs(j - 1 - 2*k) + 1) * dp[now^1][j]) % MOD;
        }
        for (int j = 2*k + 1; j + 2*k + 1 < 4*MAXK*MAXT; j++) {
            dp[now][j] = sum;
            sum -= pre_sum[now^1][j] - pre_sum[now^1][j-2*k-1];
            sum += pre_sum[now^1][j+2*k+1] - pre_sum[now^1][j];
            sum = (sum % MOD + MOD) % MOD;
        }
        for (int j = 1; j < 4*MAXK*MAXT; j++) {
            pre_sum[now][j] = (pre_sum[now][j-1] + dp[now][j]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = zero + 1 + b - a; i < 4*MAXK*MAXT; i++) {
        ans = (ans + dp[now][i]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}

