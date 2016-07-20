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
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1e5 + 5;

struct Trie {
    struct Node {
        int nxt[2], num;
        void clear() {
            memset(nxt, -1, sizeof(nxt));
            num = 0;
        }
    }nds[maxn*64];
    int cnt; 
    void init() {
        nds[0].clear();
        cnt = 0;
    }

    int newnode() {
        ++cnt;
        nds[cnt].clear();
        return cnt;
    }

    void insert(ll x) {
        int p = 0;
        for (int i = 63; i >= 0; i--) {
            int t = (x >> i) & 1;
            if(nds[p].nxt[t] == -1) {
                nds[p].nxt[t] = newnode();
            }
            p = nds[p].nxt[t];
            nds[p].num++;
        }
    }

    ll querry(ll x, int k) {
        int p = 0;
        ll res = 0;
        for (int i = 63; i >= 0; i--) {
            int t = (x >> i) & 1;
            int num = 0;
            if(nds[p].nxt[t^1] != -1) {
                num = nds[nds[p].nxt[t^1]].num;
            }
            if(num >= k) {
                res |= 1ll << i;
                p = nds[p].nxt[t^1];
            } else {
                k -= num;
                p = nds[p].nxt[t];
            }
        }
        return res;
    }

}trie;


vector<pil> G[maxn];
ll A[maxn];
int n, m;

void cal(int u, int fa, ll dist) {
    A[u] = dist;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].xx;
        if(v == fa) continue;
        cal(v, u, dist ^ G[u][i].yy);
    }
}
const int maxk = 2e5 + 5;
ll ans[maxk];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            ll w;
            scanf("%d%d%lld", &u, &v, &w);
            G[u].push_back(pil(v, w));
            G[v].push_back(pil(u, w));
        }
        memset(A, 0, sizeof(A));
        cal(1, -1, 0);
        trie.init();
        for (int i = 1; i <= n; i++) {
            trie.insert(A[i]);
        }
        priority_queue<pair<ll, pli> > que;
        for (int i = 1; i <= n; i++) {
            ll t = trie.querry(A[i], 1);
            que.push(make_pair(t, pli(A[i], 1)));
        }
        memset(ans, -1, sizeof(ans));
        int i = 1;
        ll tot = ll(n) * (n - 1);
        while(!que.empty() && i <= tot && i < maxk) {
            pair<ll, pli> cur = que.top(); que.pop();
            ans[i++] = cur.xx;
            if(cur.yy.yy == n - 1) continue;
            ll t = trie.querry(cur.yy.xx, cur.yy.yy + 1);
            que.push(make_pair(t, pli(cur.yy.xx, cur.yy.yy + 1)));
        }
        
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            int x; scanf("%d", &x);
            cout << ans[x] << endl;
        }
    }
    return 0;
}

