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

struct Node {
    ll cnt, t, v;
    Node () {}
    Node (ll cnt, ll t, ll v): cnt(cnt), t(t), v(v) {}
    bool operator < (const Node &b) const {
        if(cnt != b.cnt) return cnt < b.cnt;
        else return t > b.t;
    }
};
const int MAXN = 5e3 + 5;
const int INF = 2e9 + 5;
int n, m;
ll T;
vector<pii> G[MAXN];
int d[MAXN][MAXN];
int pre[MAXN][MAXN];
void dfs(int u, int i) {
    if(u == 0) return;
    dfs(pre[u][i], i - 1);
    printf("%d ", u);
}

void solve() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            d[i][j] = INF;
        }
    }
    d[1][1] = 0;
    priority_queue<Node> que;
    que.push(Node(1, 0, 1));
    while(!que.empty()) {
        Node cur = que.top(); que.pop();
        ll cnt = cur.cnt, t = cur.t;
        int v = cur.v;
        for (int i = 0; i < (int)G[v].size(); i++) {
            int u = G[v][i].xx;
            ll w = G[v][i].yy;
            if(t + w > T) continue;
            if(d[u][cnt+1] > t + w) {
                d[u][cnt+1] = t + w;
                pre[u][cnt+1] = v;
                que.push(Node(cnt+1, d[u][cnt+1], u));
            }
        }
    }
    for (int i = MAXN; i >= 0; i--) {
        if(d[n][i] <= T) {
            printf("%d\n", i);
            dfs(n, i);
            return;
        }
    }
} 
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%lld", &n, &m, &T);
    for (int i = 0; i < m; i++) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        G[u].push_back(pii(v, t));
    }
    solve();
    return 0;
}
