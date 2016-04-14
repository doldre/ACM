/************************************************
 *Author        :mathon
 *Created Time  :三  4/13 19:33:58 2016
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
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1000 + 5;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m;
int A[maxn][maxn];
int fa[maxn*maxn];
int full[maxn*maxn], vised[maxn][maxn];
pair<int, pair<int, int> > nodes[maxn*maxn];
int union_find(int x) {
    return x == fa[x] ? x : fa[x] = union_find(fa[x]);
}

bool inmap(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void merge(int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(!inmap(nx, ny)) {
            full[x * m + y] = 1;
            continue;
        }
        if(!vised[nx][ny]) continue;
        int f = union_find(nx * m + ny);
        if(full[f]) {
            full[x * m + y] = 1;
            continue;
        }
        fa[f] = x * m + y;
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
            nodes[i*m + j] = make_pair(A[i][j], make_pair(i, j));
        }
    }
    int len = n * m;
    sort(nodes, nodes + len);
    for (int i = 0; i <= len; i++) fa[i] = i;
    for (int i = 0; i < len; i++) {
        vised[nodes[i].yy.xx][nodes[i].yy.yy] = true;
        merge(nodes[i].yy.xx, nodes[i].yy.yy);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int f = union_find(i * m + j);
            int fx = f / m, fy = f % m;
            printf("%d%c", A[fx][fy] - A[i][j], j == m - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
