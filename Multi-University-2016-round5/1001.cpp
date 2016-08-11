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
const int maxn = 2000 + 5;
double dp[maxn][25];
const double inf = 1e15;
int K, W;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    K = 2001, W = 15;
    W = min(W, 15);

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = inf;
        }
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 1; k <= i; k++) {
                dp[i][j] = min(dp[i][j],
                        dp[k-1][j-1] * k / (i + 1) + 
                        dp[i-k][j] * (i + 1 - k) / (i + 1) + 1);
            }
        }
    }
    while(~scanf("%d%d", &K, &W)) {
        W = min(W, 15);
        printf("%.6f\n", dp[K][W]);
    }
    return 0;
}

