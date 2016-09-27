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

const ll INF = 1e15;
const int MAXN = 3000 + 5;
int n;
ll A[MAXN], B[MAXN], dp[MAXN][MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
        A[i] -= i;
    }
    memcpy(B, A, sizeof(A));
    sort(B, B + n);
    for (int i = 0; i < n; i++) {
        dp[0][i] = abs(A[0] - B[i]);
    }
    for (int i = 1; i < n; i++) {
        ll tmp = dp[i-1][0];
        for (int j = 0; j < n; j++) {
            tmp = min(tmp, dp[i-1][j]);
            dp[i][j] = tmp + abs(A[i] - B[j]);
        }
    }ll ans = INF;
    for (int i = 0; i < n; i++) ans = min(ans, dp[n-1][i]);
    printf("%lld\n", ans);
    return 0;
}

