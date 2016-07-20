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

const int maxb = 21;
const int maxg = 8;
const int maxn = 10;
int G, B, S;
int dp[1<<maxb];
int bags[maxb][maxn];
int colors[maxg];
int tot;
int dfs(int mask) {
    // pr(mask); prln(turn);
    //turn: 
    if(dp[mask] != -1) return dp[mask];
    int already_have = 0;
    int t_colors[maxg];
    memset(t_colors, 0, sizeof(t_colors));
    for (int i = 0; i < B; i++) {
        if((mask>>i) & 1) {
            for (int j = 0; j < G; j++) {
                t_colors[j] += bags[i][j];
            }
        }
    }

    for (int i = 0; i < G; i++) {
        already_have += t_colors[i] / S;
        t_colors[i] %= S;
    }

    // prln(already_have);
    int buf[maxg];
    int res = 0;
    for (int i = 0; i < B; i++) {
        if(!((mask >> i) & 1)) {
           memcpy(buf, t_colors, sizeof(buf));
            for (int j = 0; j < G; j++) {
                buf[j] += bags[i][j];
            }
            int cnt_new_gems = 0;
            for (int j = 0; j < G; j++) {
                cnt_new_gems += buf[j] / S;
            }
            if(cnt_new_gems > 0) {
                res = max(res,  cnt_new_gems + dfs((mask|(1<<i))));
            } else {
                res = max(res, tot - already_have - dfs((mask|(1<<i))));
            }
        }
    }
    return dp[mask] = res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d%d", &G, &B, &S) == 3 && G && B && S) {
        memset(bags, 0, sizeof(bags));
        memset(colors, 0, sizeof(colors));
        for (int i = 0; i < B; i++) {
            int n; scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                int x; scanf("%d", &x);
                x--;
                bags[i][x]++;
                colors[x]++;
            }
        }
        tot = 0;
        for (int i = 0; i < G; i++) {
            tot += colors[i] / S;
        }
        memset(dp, -1, sizeof(dp));
        int a = dfs(0);
        int b = tot - a;
        // prln(tot);
        // pr(a); prln(b);
        printf("%d\n", a - b);
    }
    return 0;
}

