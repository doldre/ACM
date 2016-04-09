#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1000 + 5;
typedef long long ll;
int A[maxn][maxn];
int used[maxn][maxn];
int n, m;
ll k;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
    int fa[maxn * maxn];
    int sz[maxn * maxn];

    void init() {
        for (int i = 0; i < n * m; i++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if(ra != rb) {
            sz[ra] = sz[ra] + sz[rb];
            sz[rb] = 0;
            fa[rb] = ra;
        }
    }
    int size(int x) {
        return sz[find(x)];
    }

pair<int, pair<int, int> > po[maxn * maxn];

inline void imerge(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(A[nx][ny] >= A[x][y]) {
             merge(nx * m + ny, x * m + y);
        }
    }
}

int remain;
void dfs(int x, int y, int v) {
    if(remain <= 0 || used[x][y]) return;
    remain--;
    used[x][y] = v;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if(A[nx][ny] >= v) dfs(nx, ny, v);
        }
    }
}
int main() {
    cin >> n >> m >> k;
    init();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< m; j++) {
            cin >> A[i][j];
            po[cnt++] = make_pair(A[i][j], make_pair(i, j));
        }
    }

    sort(po, po + cnt);
    reverse(po, po + cnt);
    bool ok = false;
    for (int i = 0; i < cnt; i++) {
        int v = po[i].first, x = po[i].second.first, y = po[i].second.second;
        imerge(x, y);
        //printf("size = %d\n", dsu.size(x * m + y));
        if(v && k % v == 0 &&size(x * m + y) >= k / v) {
            remain = k / v;
            ok = true;
            dfs(x, y, v);
            break;
        }
    }
    if(ok) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d%c", used[i][j], j == m - 1 ? '\n' : ' ');
            }
        }
    } else printf("NO\n");
    return 0;
}
