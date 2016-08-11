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
typedef unsigned int uint;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 18;
char color[1<<MAXN][MAXN], dp[1<<MAXN];
int n;
char str[MAXN + 5];
int G[MAXN];
uint pows[1<<MAXN];
void init() {
    pows[0] = 1;
    for (int i = 1; i < 1<<MAXN; i++) {
        pows[i] = pows[i-1] * 233;
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            G[i] = 0;
            for (int j = 0; j < n; j++) {
                G[i] |= (str[j] - '0') << j;
            }
        }
        for (int i = 0; i < (1<<n); i++) {
            dp[i] = 100;
            for (int j = 0; j < n; j++) {
                color[i][j] = 0;
            }
        }
        dp[0] = 0;
        for (int mask = 1; mask < (1<<n); mask++) {
            for (int i = 0; i < n; i++) {
                if((mask >> i) & 1) {
                    int tmp = 0;
                    int c = (mask ^ (1 << i)) & G[i];
                    for (int j = 0; j < n; j++) {
                        if((c >> j) & 1) {
                            tmp |= 1 << color[mask ^ (1 << i)][j];
                        }
                    }
                    // int cnt = 1;
                    // while((tmp >> cnt) & 1) cnt++; 
                    int cnt = __builtin_ctz(~(tmp | 1));
                    tmp = max((int)dp[mask ^ (1 << i)], cnt);
                    if(tmp < dp[mask]) {
                        dp[mask] = tmp;
                        memcpy(color[mask], color[mask ^ (1 << i)], sizeof(color[mask]));
                        color[mask][i] = cnt;
                    }
                }
            }
        }
        uint ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            ans += dp[mask] * pows[mask];
        }
        printf("%u\n", ans);
    }
    return 0;
}
