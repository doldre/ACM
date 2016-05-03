/************************************************
 *Author        :mathon
 *Created Time  :一  5/ 2 14:46:55 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 3000 + 5;
int n, m;
vector<int> G[maxn];

pii orig[maxn][maxn], rev[maxn][maxn];
int d[maxn][maxn];

void bfs(int s, int dist[]) {
    for (int i = 0; i <= n; i++) dist[i] = -1;
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for (int i = 0; i < (int)G[cur].size(); i++) {
            int v = G[cur][i];
            if(dist[v] == -1) {
                dist[v] = dist[cur] + 1;
                que.push(v);
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        bfs(i, d[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            orig[i][j] = pii(d[i][j], j);
            rev[j][i] = pii(d[i][j], i);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(orig[i] + 1, orig[i] + n + 1);
        sort(rev[i] + 1, rev[i] + n + 1);
    }
    int ans = 0, R[4] = {0};
    for (int b = 1; b <= n; b++) {
        for (int c = 1; c <= n; c++) {
            if(b == c || d[b][c] == -1) continue;
            int x, y, i;
            i = n;
            while(rev[b][i].yy == b || rev[b][i].yy == c) i--;
            x = rev[b][i].yy;
            i = n;
            while(orig[c][i].yy == x || orig[c][i].yy == b ||
                    orig[c][i].yy == c) i--;
            y = orig[c][i].yy;
            /* pr(i);pr(x); prln(y); */
            if(d[x][b] + d[b][c] + d[c][y] > ans) {
                ans = d[x][b] + d[b][c] + d[c][y];
                R[0] = x, R[1] = b, R[2] = c, R[3] = y;
            }

            i = n;
            while(orig[c][i].yy == b || orig[c][i].yy == c) i--;
            y = orig[c][i].yy;
            i = n;
            while(rev[b][i].yy == b || rev[b][i].yy == c ||
                    rev[b][i].yy == y) {
                i--;
            }
            x = rev[b][i].yy;
            /* pr(i); pr(x); prln(y); */
            if(d[x][b] + d[b][c] + d[c][y] > ans) {
                ans = d[x][b] + d[b][c] + d[c][y];
                R[0] = x, R[1] = b, R[2] = c, R[3] = y;
            }
        }
    }
    printf("%d %d %d %d\n", R[0], R[1], R[2], R[3]);
}

int main(void)
{
#ifdef LOCAL
    /* freopen("in.txt", "r", stdin); */
    //freopen("out.txt", "w", stdout);
#endif
    sa(n); sa(m);
    rep(i, 0, m) {
        int u, v;
        sa(u); sa(v);
        G[u].push_back(v);
    }
    solve();
    return 0;
}
