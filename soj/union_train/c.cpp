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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 400 + 5;
const int M = 50;
int A[maxn];
int dp[M][M][M][M];
int cnt[5];
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
       int n, m;
       sa(n); sa(m);
       memset(dp, -1, sizeof(dp));
       memset(A, 0, sizeof(A));
       for (int i = 1; i <= n; i++) {
           sa(A[i]);
       }
       memset(cnt, 0, sizeof(cnt));
       for (int i = 0; i < m; i++) {
           int x;
           sa(x);
           cnt[x]++;
       }
       dp[0][0][0][0] = A[1];
       int ans = 0;
       for (int i = 0; i <= cnt[1]; i++) {
           for (int j = 0; j <= cnt[2]; j++) {
               for (int k = 0; k <= cnt[3]; k++) {
                   for (int l = 0; l <= cnt[4]; l++) {
                       int pos = i * 1 + j * 2 + k * 3 + l * 4 + 1;
                       int last = -1;
                       if(i > 0) last = max(last, dp[i-1][j][k][l]);
                       if(j > 0) last = max(last, dp[i][j-1][k][l]);
                       if(k > 0) last = max(last, dp[i][j][k-1][l]);
                       if(l > 0) last = max(last, dp[i][j][k][l-1]);
                       if(last != -1) dp[i][j][k][l] = last + A[pos];
                       ans = max(dp[i][j][k][l], ans);
                       /* prln(pos); */
                       /* prln(dp[i][j][k][l]); */
                   }
               }
           }
       }
       printf("%d\n", ans);
    }
    return 0;
}
