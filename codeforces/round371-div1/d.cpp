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

const int MAXN = 1000 + 5;
int dp[MAXN][MAXN];
int f[11][11][MAXN][MAXN];
int A[MAXN][MAXN];
int LOG[MAXN];
int n, m;

void st_init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[0][0][i][j] = dp[i][j];
        }
    }
    LOG[1] = 0;
    for (int i = 2; i < MAXN; i++) LOG[i] = LOG[i>>1] + 1;
    for (int ki = 0; 1 << ki <= n; ki++) {
        for (int kj = 0; 1 << kj <= m; kj++) {
            for (int i = (1 << ki); i <= n; i++) {
                for (int j = (1 << kj); j <= m; j++) {
                    if(kj > 0) {
                        f[ki][kj][i][j] = max(f[ki][kj-1][i][j-(1<<(kj-1))],
                                f[ki][kj-1][i][j]);
                    } else if(ki > 0) {
                        f[ki][kj][i][j] = max(f[ki-1][kj][i-(1<<(ki-1))][j],
                                f[ki-1][kj][i][j]);
                    }
                }
            }
        }
    }
}

int query(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) return 0;
    // int a = LOG[x2-x1+1], b = LOG[y2-y1+1];
    int a = log2(x2-x1+1), b = log2(y2-y1+1);
    int r[4];
    r[0] = f[a][b][x1+(1<<a) - 1][y1+(1<<b)-1];
    r[1] = f[a][b][x2][y1+(1<<b)-1];
    r[2] = f[a][b][x1+(1<<a)-1][y2];
    r[3] = f[a][b][x2][y2];
    return max({r[0], r[1], r[2], r[3]});
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(A[i][j]) {
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]),
                        dp[i][j-1]) + 1;
            }
        }
    }
    st_init();
    int Q; scanf("%d", &Q);
    while(Q--) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            if(query(x1 + m - 1, y1 + m - 1, x2, y2) >= m) {
                l = m;
            } else r = m;
        }
        printf("%d\n", l);
    }
    return 0;
}

