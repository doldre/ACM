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

const ll INF = 1e16;
const int MAXN = 1e5 + 5;
string str[MAXN][2];
int n;
int C[MAXN];
ll dp[MAXN][2];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> str[i][0];
        str[i][1] = str[i][0];
        reverse(str[i][1].begin(), str[i][1].end());
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = INF;
    }
    dp[1][0] = 0; dp[1][1] = C[1];
    for (int i = 2; i <= n; i++) {
        if(str[i][0] >= str[i-1][0]) {
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        }
        if(str[i][0] >= str[i-1][1]) {
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }
        if(str[i][1] >= str[i-1][0]) {
            dp[i][1] = min(dp[i][1], dp[i-1][0] + C[i]);
        }
        if(str[i][1] >= str[i-1][1]) {
            dp[i][1] = min(dp[i][1], dp[i-1][1] + C[i]);
        }
    }
    ll ans = min(dp[n][0], dp[n][1]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}

