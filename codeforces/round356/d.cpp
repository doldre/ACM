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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int maxn = 500 + 5;
char board[maxn][maxn];
int conid[maxn][maxn];
int cnt[maxn];
int n, k, con, concnt;

void dfs(int x, int y) {
    if(conid[x][y]) return;
    concnt++;
    conid[x][y] = con;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx > n || nx <= 0 || ny > n || ny <= 0) {
            continue;
        }
        if(board[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int eg[maxn], inter[maxn];
void solve() {
    con = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            concnt = 0;
            if(board[i][j] == '.' && conid[i][j] == 0) {
                ++con;
                dfs(i, j);
            }
        }
    }


    for (int i = 1; i <= n - k + 1; i++) {
        memset(inter, 0, sizeof(inter));
        memset(eg, 0, sizeof(eg));
        for (int x = i; x <= i + k - 1; x++) {
            for (int y = 1; y <= k; y++) {
                if(conid[x][y] > 0) {
                    inter[conid[x][y]]++;
                }
            }
        }
        for (int y = 1; y <= n - k + 1; y++) {
            memset(eg, 0, sizeof(eg));
            int left = y, right = y + k - 1, up = i, down = i + k - 1;
            if(left > 1) {
                for (int x = up; x <= down; x++) {
                    eg[conid[x][left - 1]]++;
                }
            }
            if(right < n) {
                for (int x = up; x <= down; x++) {
                    eg[conid[x][right+1]]++;
                }
            }
            if(up > 1) {
                for (int k = left; k <= right; k++) {
                    eg[:x
            ]
                }
            }
        }
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", board[i] + 1);
    }
    return 0;
}
