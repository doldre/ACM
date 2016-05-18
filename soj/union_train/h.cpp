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
const int maxn = 100 + 5;
const int maxk = 100000 + 5;
int dp[maxk];
int A[maxn], M[maxn];
int n, k;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        sa(n); sa(k);
        for (int i = 1; i <= n; i++) {
            sa(A[i]);
        }
        for (int i = 1; i <= n; i++) {
            sa(M[i]);
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if(dp[j] >= 0) dp[j] = M[i];
                else if(j >= A[i] && dp[j-A[i]] > 0) dp[j] = dp[j-A[i]] - 1;
            }
        }
        if(dp[k] >= 0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
