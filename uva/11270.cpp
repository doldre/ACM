/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define xx first
#define yy second
#define lowbit(x) (x&-x)
#define pr(x) cout << #x << " = " << x << " " 
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;
ll dp[2][1<<10];
int n, m;
int now;
void update(int cur, int nxt) {
    if(nxt & (1 << m)) {
        dp[now][nxt^(1<<m)] += dp[now^1][cur];
    }
}

int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2) {
        if(m > n) swap(n, m);
        now = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][(1<<m)-1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                now ^= 1;
                memset(dp[now], 0, sizeof(dp[now]));
                for (int k = 0; k < (1<<m); k++) {
                    // prln(dp[now^1][k]);
                    update(k, k << 1);
                    if(i && !(k & (1 << (m-1)))) {
                        update(k, (k<<1) ^ 1 ^ (1<<m));
                    }
                    if(j && !(k & 1)) {
                        update(k, (k<<1) ^ 3);
                    }
                }
            }
        }
        printf("%lld\n", dp[now][(1<<m)-1]);
    }
	return 0;
}
