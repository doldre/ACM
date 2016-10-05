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

const int INF = 0x3f3f3f3f;
const int MAXN = 200 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char mp[MAXN][MAXN];
int G[MAXN][MAXN];
vector<pii> soldiers;
vector<pii> empties;
int d[MAXN][MAXN];
pii s, t;
int n, m;

bool solve() {
    memset(d, 0x3f, sizeof(d));
    queue<pii> que;
    que.push(s);
    d[s.xx][s.yy] = 0;
    while(!que.empty()) {
        pii cur = que.front(); que.pop();
        if(cur == t) return true;
        int x = cur.xx, y = cur.yy;
        // pr(x); prln(y);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(d[x][y] + 1 >= G[nx][ny]) continue;
            if(d[nx][ny] > d[x][y] + 1) {
                d[nx][ny] = d[x][y] + 1;
                que.push(pii(nx, ny));
            }
        }
    }
    return false;
}

void pre_solve() {
    memset(d, 0x3f, sizeof(d));
    queue<pii> que;
    for (int i = 0; i < (int)soldiers.size(); i++) {
        pii x = soldiers[i];
        d[x.xx][x.yy] = 0;
        que.push(x);
    }
    while(!que.empty()) {
        pii cur = que.front(); que.pop();
        int x = cur.xx, y = cur.yy;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(mp[nx][ny] == '#') continue;
            if(d[nx][ny] > d[x][y] + 1) {
                d[nx][ny] = d[x][y] + 1;
                que.push(pii(nx, ny));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mp[i][j] != '#') {
                G[i][j] = min(d[i][j], G[i][j]);
            }
        }
    }
}
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", mp[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mp[i][j] == '@') {
                s = pii(i, j);
            } else if(mp[i][j] == '$') {
                soldiers.push_back(pii(i, j));
            } else if(mp[i][j] == '%') {
                t = pii(i, j);
                G[i][j] = INF;
            } else if(mp[i][j] == '.') {
                empties.push_back(pii(i, j));
                G[i][j] = INF;
            }
        }
    }
    pre_solve();
    // pr(s.xx); prln(s.yy);
    // pr(t.xx); prln(t.yy);
    if(solve()) puts("Yes");
    else puts("No");
    return 0;
}

