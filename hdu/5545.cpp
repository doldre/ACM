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
typedef pair<int, ll > pli;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const ll INF = 1e15;
const int MAXN = 1e5 + 5;
int X[MAXN], Y[MAXN], C[MAXN], W[MAXN];
int n, m;
vector<pii> G[MAXN];
ll d[MAXN];

void solve() {
    priority_queue<pli, vector<pli>, greater<pli> > que;
    d[0] = 0;
    que.push(pli(0, 0));
    while(!que.empty()) {
        pli cur = que.top(); que.pop();
        if(cur.yy > d[cur.xx]) continue;
        for (auto e: G[cur.xx]) {
            int v = e.xx, w = e.yy;
            if(d[v] > d[cur.xx] + w) {
                d[v] = d[cur.xx] + w;
                que.push(pli(v, d[v]));
            }
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &X[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &Y[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &C[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &W[i]);
        }
        for (int i = 0; i <= m; i++) {
            G[i].clear();
            d[i] = INF;
        }
        for (int i = 1; i <= n; i++) {
            G[Y[i]].push_back(pli(X[i], C[i]));
        }
        for (int i = 1; i <= m; i++) {
            if(W[i] == 0) {
                G[0].push_back(pli(i, 0));
            }
        }
        solve();
        bool ok = true;
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            if(W[i] == 2) {
                if(d[i] < INF) {
                    ans += d[i];
                } else ok = false;
            }
        }
        if(!ok) ans = -1;
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

