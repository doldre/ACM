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
const ll mod = 1e9 + 7;
const int maxn = 100 + 5;

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll dp[maxn][2];

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
    }
    ll t = (dp[n][0] + dp[n][1]) % mod;
    cout << (mod_pow(2, n) - t + mod) % mod << endl;
    return 0;
}
