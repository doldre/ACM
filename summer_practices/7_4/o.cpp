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
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
vector<pii> G[maxn];
int d[maxn];
int n, m;

int bfs() {
    memset(d, -1, sizeof(d));
    queue<int> que;
    d[1] = inf;
    que.push(1);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].xx;
            int t = min(d[u], G[u][i].yy);
            if(d[v] < t) {
                d[v] = t;
                que.push(v);
            }
        }
    }
    return d[n];
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            G[u].push_back(pii(v, c));
            G[v].push_back(pii(u, c));
        }
        printf("Scenario #%d:\n%d\n\n", Cas, bfs());
    }
    return 0;
}

