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

const ll inf = 1e15;
const int maxn = 350000 + 5;
const int maxm = 300 + 5;

ll A[maxm], B[maxm], T[maxm];
ll dp[2][maxn];
ll n, m, d;
ll que[maxn], head, tail;
ll pos[maxn];
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int tt;
    sa(tt);
    while(tt--) {
        scanf("%lld%lld%lld", &n, &m, &d);
        ll res = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%lld%lld%lld", &A[i], &B[i], &T[i]);
            res += B[i];
        }

        memset(dp, 0, sizeof(dp));
        int now = 0;
        for (int i = 1; i <= m; i++) {
            now ^= 1;
            head = tail = 0;
            ll len = (T[i] - T[i-1]) * d;
            for (int j = 1; j <= n && j <= len; j++) {
                ll v = dp[now^1][j];
                while(tail > head && que[tail-1] > v) tail--;
                que[tail] = v;
                pos[tail] = j;
                tail++;
            }
            for (int j = 1; j <= n; j++) {
                if(j + len <= n) {
                    ll v = dp[now^1][j+len];
                    while(tail > head && que[tail - 1] > v) tail--;
                    que[tail] = v;
                    pos[tail] = j + len;
                    tail++;
                }
                while(j - pos[head] > len) head++;
                dp[now][j] = que[head] + abs(A[i] - j);
            }
        }
        /* for (int i = 1; i <= n; i++) { */
        /*     printf("%lld ", dp[now][i]); */
        /* } */
        /* puts(""); */
        ll ans = inf;
        for (int i = 1; i <= n; i++) ans = min(ans, dp[now][i]);
        printf("%lld\n", res - ans);
    }
    return 0;
}
