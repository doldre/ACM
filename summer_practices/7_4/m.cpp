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
const ll inf = 0x3fffffff;
const int maxn = 2000 + 5;
int dp[maxn][maxn];

int ap[maxn], bp[maxn], as[maxn], bs[maxn];
int T, MaxP, W;
int que[maxn], head, tail; 
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int cas; scanf("%d", &cas);
    while(cas--) {
        scanf("%d%d%d", &T, &MaxP, &W);
        for (int i = 1; i <= T; i++) {
            scanf("%d%d%d%d", &ap[i], &bp[i], &as[i], &bs[i]);
        }
        for (int i = 0; i <= T; i++) {
            for (int j = 0; j <= MaxP; j++) {
                dp[i][j] = -inf;
            }
        }

        for (int i = 1; i <= W + 1; i++) {
            for (int j = 0; j <= as[i]; j++) {
                dp[i][j] = max(dp[i][j], -ap[i] * j);
            }
        }

        for (int i = 2; i <= T; i++) {
            for (int j = 0; j <= MaxP; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            if (i > W + 1) {
                head = tail = 0;
                for (int j = 0; j <= MaxP; j++) {
                    while(tail > head && que[tail-1] < dp[i-W-1][j] + ap[i] * j) tail--;
                    que[tail++] = dp[i-W-1][j] + ap[i] * j;
                    dp[i][j] = max(dp[i][j], que[head] - ap[i] * j);
                    if(j - as[i] >= 0) {
                        if(que[head] == dp[i-W-1][j-as[i]] + ap[i] * (j-as[i])) head++;
                    }
                }

                head = tail = 0;
                for (int j = MaxP; j >= 0; j--) {
                    while(tail > head && que[tail-1] < dp[i-W-1][j] + bp[i] * j) tail--;
                    que[tail++] = dp[i-W-1][j] + bp[i] * j;
                    dp[i][j] = max(dp[i][j], que[head] - bp[i] * j);
                    if(j + bs[i] <= MaxP) {
                        if(que[head] == dp[i-W-1][j+bs[i]] + bp[i] * (j+bs[i])) head++;
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= MaxP; j++) {
            ans = max(ans, dp[T][j]);
        }
        cout << ans << endl;
    }
    return 0;
}

