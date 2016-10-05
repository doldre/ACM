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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAXN = 50 + 5;
char mp[MAXN][MAXN];
bool used[MAXN][MAXN];
int n, m, k;
bool flag;
vector<pair<int, pii> > lakes;
int dfs(int x, int y) {
    used[x][y] = true;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            flag = true;
            continue;
        }
        if(mp[nx][ny] == '.' && !used[nx][ny]) {
            res += dfs(nx, ny);
        }
    }
    return res;
}

void fill(int x, int y) {
    mp[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }
        if(mp[nx][ny] == '.') {
            fill(nx, ny);
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", mp[i]);
    }
    memset(used, false, sizeof(used));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!used[i][j] && mp[i][j] == '.') {
                flag = false;
                int t = dfs(i, j);
                if(!flag) lakes.push_back(make_pair(t, pii(i, j)));
            }
        }
    }
    sort(lakes.begin(), lakes.end());
    int ans = 0;
    for (int i = 0; i < (int)lakes.size() - k; i++) {
        ans += lakes[i].xx;
        fill(lakes[i].yy.xx, lakes[i].yy.yy);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        puts(mp[i]);
    }
    return 0;
}

