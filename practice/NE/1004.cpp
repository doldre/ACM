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

const int MAXN = 200 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int X[MAXN], Y[MAXN];
int vx[MAXN<<1], vy[MAXN<<1], cntx, cnty;
char mp[MAXN<<1][MAXN<<1];
int used[MAXN<<1][MAXN<<1];
int r, c, n;

ll dfs(int x, int y) {
    if(used[x][y] || mp[x][y]) return 0;
    used[x][y] = 1;
    ll res = (ll)(vx[x] - vx[x-1]) * (vy[y] - vy[y-1]);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx <= 0 || nx > r || ny <= 0 || ny > c) continue;
        res += dfs(nx, ny);
    }
    return res;
}
        

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &r, &c);
        cntx = cnty = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &X[i], &Y[i]);
            vx[cntx++] = X[i];
            vx[cntx++] = X[i] + 1;
            vy[cnty++] = Y[i];
            vy[cnty++] = Y[i] + 1;
        }
        vx[cntx++] = 1;
        vx[cntx++] = 2;
        vx[cntx++] = r;
        vx[cntx++] = r + 1;
        vy[cnty++] = 1;
        vy[cnty++] = 2;
        vy[cnty++] = c;
        vy[cnty++] = c + 1;
        sort(vx, vx + cntx);
        sort(vy, vy + cnty);
        cntx = unique(vx, vx + cntx) - vx;
        cnty = unique(vy, vy + cnty) - vy;
        // pr(cntx); prln(cnty);
        memset(mp, 0, sizeof(mp));
        for (int i = 1; i <= n; i++) {
            int idx = lower_bound(vx, vx + cntx, X[i]) - vx + 1;
            int idy = lower_bound(vy, vy + cnty, Y[i]) - vy + 1;
            // pr(idx); prln(idy);
            mp[idx][idy] = 1;
        }
        r = lower_bound(vx, vx + cntx, r) - vx + 1;
        c = lower_bound(vy, vy + cnty, c) - vy + 1;
        memset(used, 0, sizeof(used));
        vector<ll> ans;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                ll t = dfs(i, j);
                if(t > 0) ans.push_back(t);
            }
        }
        sort(ans.begin(), ans.end());
        printf("Case #%d:\n", Cas);
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%lld%c", ans[i], i == (int)ans.size()- 1 ? '\n' : ' ');
        }
    }
    return 0;
}

