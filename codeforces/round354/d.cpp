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

const int maxn = 1000 + 5;
int dp[maxn][maxn][4];

struct Point {
    int x, y, dir;
    Point() {}
    Point(int x, int y, int dir):x(x), y(y), dir(dir) {}
};

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int mp[maxn][maxn];
char str[maxn][maxn];
int n, m;
Point s, e;

int solve() {
    memset(dp, -1, sizeof(dp));
    queue<Point> que;
    que.push(s);
    dp[s.x][s.y][s.dir] = 0;
    while(!que.empty()) {
        Point cur = que.front(); que.pop();
        if(cur.x == e.x && cur.y == e.y) {
            return dp[cur.x][cur.y][cur.dir];
        }
        if(dp[cur.x][cur.y][(cur.dir + 1) % 4] == -1) {
            dp[cur.x][cur.y][(cur.dir + 1) % 4] = dp[cur.x][cur.y][cur.dir] + 1;
            que.push(Point(cur.x, cur.y, (cur.dir + 1) % 4));
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            int d1 = (i + 4 - cur.dir) % 4;
            int d2 = (i + 2 + 4 - cur.dir) % 4;
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if((mp[cur.x][cur.y] & (1 << d1)) &&
                    (mp[nx][ny] & (1 << d2))) {
                if(dp[nx][ny][cur.dir] == -1) {
                    dp[nx][ny][cur.dir] = dp[cur.x][cur.y][cur.dir] + 1;
                    que.push(Point(nx, ny, cur.dir));
                }
            }
        }
    }
    return -1;
}

    int main(void)
    {
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    scanf("%d%d", &s.x, &s.y);
    s.dir = 0;
    scanf("%d%d", &e.x, &e.y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(str[i][j] == '+') {
                mp[i][j] = 15;
            }
            if(str[i][j] == '-') {
                mp[i][j] = 10;
            }
            if(str[i][j] == '|') {
                mp[i][j] = 5;
            }
            if(str[i][j] == '^') {
                mp[i][j] = 1;
            }
            if(str[i][j] == '>') {
                mp[i][j] = 2;
            }
            if(str[i][j] == '<') {
                mp[i][j] = 8;
            }
            if(str[i][j] == 'v') {
                mp[i][j] = 4;
            }
            if(str[i][j] == 'L') {
                mp[i][j] = 7;
            }
            if(str[i][j] == 'R') {
                mp[i][j] = 13;
            }
            if(str[i][j] == 'U') {
                mp[i][j] = 14;
            }
            if(str[i][j] == 'D') {
                mp[i][j] = 11;
            }
            if(str[i][j] == '*') {
                mp[i][j] = 0;
            }
        }
    }
    int ans = solve();
    cout << ans << endl;
    return 0;
    }
