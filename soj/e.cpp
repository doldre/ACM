/************************************************
 *Author        :mathon
 *Created Time  :2016年05月03日 星期二 12时51分46秒
 ***********************************************/
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
vector<int> vi;
#define xx first
#define yy second
#define lowbit(x) (x&-x)
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
typedef pii P;
const int inf = 0x3f3f3f3f;
const int maxn = 600 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

queue<P> que;
char mp[maxn][maxn];
int d[maxn][maxn];
int f[maxn][maxn];
int ans;
int n, m, k;
void dfs(int x, int y, int dist, int time) {
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(mp[x][y] == 'W') return;
//    pr(x); prln(y); pr(dist); prln(time);
    if(time == 0) return;
    if(dist >= d[x][y]) return;
    d[x][y] = dist;
    if(mp[x][y] == 'R' && dist < f[x][y]) {
        f[x][y] = dist;
        que.push(P(x, y));
        return;
    }
    if(mp[x][y] == 'E') ans = min(ans, dist);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny, dist + 1, time - 1);
    }
}


void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            d[i][j] = inf;
        }
    }
}

void solve() {
    ans = inf;
    while(!que.empty()) {
        P cur = que.front(); que.pop();
        int x = cur.xx, y = cur.yy;
        init();
        dfs(x, y, f[x][y], k);
    }
}


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        while(!que.empty()) que.pop();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                f[i][j] = inf;
            }
        }

        sa(n); sa(m); sa(k);
        int x, y;
        for (int i = 0; i < n; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; j++) {
                if(mp[i][j] == 'S') {
                    x = i; y = j;
                }
            }
        }
        init();
        que.push(P(x, y));
        f[x][y] = 0;
        solve();
        if(ans == inf) {
            printf("Poor RunningPhoton!\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
