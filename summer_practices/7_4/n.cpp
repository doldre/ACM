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
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
int d[maxn];
struct Edge {
    int  to, w;
    Edge() {}
    Edge(int to, int w):to(to), w(w) {};
};

vector<Edge> G[maxn];

int T, N;
int dij() {
    memset(d, 0x3f, sizeof(d));
    priority_queue<pii, vector<pii>, greater<pii> > que;
    d[1] = 0;
    que.push(pii(d[1], 1));
    while(!que.empty()) {
        pii cur = que.top(); que.pop();
        int u = cur.yy, dist = cur.xx;
        if(u == N) {
            return dist;
        }
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].to;
            if(d[v] > d[u] + G[u][i].w) {
                d[v] = d[u] + G[u][i].w;
                que.push(pii(d[v], v));
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    scanf("%d%d", &T, &N);
    for (int i = 0; i < T; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back(Edge(v, c));
        G[v].push_back(Edge(u, c));
    }
    int ans = dij();
    printf("%d\n", ans);
	return 0;
}
