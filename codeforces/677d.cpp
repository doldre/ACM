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
#define pr(x) cout << #x << " = " << x << " " 
#define prln(x) cout << #x << " = " << x << endl
const int inf = 0x3f3f3f3f;
typedef pair<int, int> pii;
typedef long long ll;
const int maxn = 300 + 5;
int A[maxn][maxn];
int vis[maxn][maxn];
int dis[maxn][maxn], ans[maxn][maxn];
vector<pii> G[maxn*maxn]; 

int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	int ex, ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &A[i][j]);
			if(A[i][j] == p) {
				ex = i;
				ey = j;
			}
			G[A[i][j]].push_back(pii(i, j));
		}
	}
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= m; i++) {
		dis[1][i] = i - 1;
		vis[1][i] = 1;
	}

	for (int i = 1; i <= p; i++) {
		for (int j = 0; j < (int)G[i].size(); j++) {
			int x = G[i][j].xx, y = G[i][j].yy;
			for (int k = 1; k <= n; k++) {
				if(vis[k][y] == i) {
					ans[x][y] = min(ans[x][y], dis[k][y] + abs(x - k));
				}
			}
		}
		for (int j = 0; j < (int)G[i].size(); j++) {
			int x = G[i][j].xx, y = G[i][j].yy;
			for (int k = 1; k <= m; k++) {
				if(vis[x][k] != i + 1) {
					vis[x][k] = i + 1;
					dis[x][k] = ans[x][y] + abs(y - k);
				} else {
					dis[x][k] = min(dis[x][k], ans[x][y] + abs(y - k));
				}
			}
		}
	}
	cout << ans[ex][ey] << endl;
	return 0;
}
