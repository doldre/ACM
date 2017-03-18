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
const int MAXN = 5e4 + 5;
ll dp[MAXN][350];
int N;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * (j + 1) / 2 <= i; j++) {
            dp[i][j] = (dp[i-j][j] + dp[i-j][j-1]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i * (i + 1) / 2 <= N; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}

