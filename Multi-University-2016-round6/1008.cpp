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
const int MAXN = 1000 + 5;
int n, s;
int A[MAXN];
int dp[2][MAXN][3][3];

void add(int &a, int b) {
    a = (a + b) % MOD;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &s);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        memset(dp[0], 0, sizeof(dp[0]));
        dp[0][0][0][0] = 1;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur ^= 1;
            for (int j = 0; j <= s; j++) {
                for (int s1 = 0; s1 <= 2; s1++) {
                    for (int s2 = 0; s2 <= 2; s2++) {
                        dp[cur][j][s1][s2] = 0;
                        if(j >= A[i]) {
                            add(dp[cur][j][s1][s2], dp[cur ^ 1][j-A[i]][s1][s2]);
                            if(s1 > 0) {
                                add(dp[cur][j][s1][s2], dp[cur ^ 1][j-A[i]][s1-1][s2]);
                            }
                        }
                        add(dp[cur][j][s1][s2], dp[cur ^ 1][j][s1][s2]);
                        if(s2 > 0) {
                            add(dp[cur][j][s1][s2], dp[cur ^ 1][j][s1][s2-1]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= s; i++) {
            add(ans, dp[cur][i][2][2]);
        }
        ans = (ans * 2) % MOD * 2 % MOD;
        cout << ans << endl;
    }
    return 0;
}

