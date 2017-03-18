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

const int MAXN = 5e5 + 5, MAXM = 5e5 + 5;
struct Edge {
    int to, nxt;
    ll w;
    Edge() {}
    Edge(int to, ll w, int nxt) {
        this->to = to; 
        this->w = w; 
        this->nxt = nxt;
    }
}es[MAXM*2];

int head[MAXN], tot;

void edge_init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add_edge(int u, int v, ll w) {
    es[tot] = Edge(v, w, head[u]);
    head[u] = tot++;
}

ll A[MAXN*2], sz;
ll dis[MAXN];

void dfs(int u, ll d) {
    if(dis[u] == -1) dis[u] = d;
    else {
        A[sz++] = dis[u] ^ d;
        return;
    }
    for (int i = head[u]; ~i; i = es[i].nxt) {
        int v = es[i].to;
        dfs(v, d ^ es[i].w);
    }
}

ll P[65];

void Gauss_Base() {
    memset(P, 0, sizeof(P));
    // for(int i = 0; i < sz; i++) {  
        // for(int j = 62; j >= 0; j--) {  
            // if(!(A[i] >> j & 1)) continue;  
            // if(!P[j]) {  
                // P[j] = A[i]; break;  
            // }  
            // A[i] ^= P[j];  
        // }  
        // }  
    for (int i = 62; i >= 0; i--) {
        for (int j = 0; j < sz; j++) {
            if((A[j] >> i) & 1) {
                P[i] = A[j];
                break;
            }
        }
        for (int j = 0; j < sz; j++) {
            if((A[j] >> i) & 1) A[j] ^= P[i];
        }
    }
}

int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    edge_init();
    sz = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    memset(dis, -1, sizeof(dis));
    dfs(1, 0);
    Gauss_Base();
    ll ans = dis[n];
    for (int i = 62; i >= 0; i--) {
        ans = max(ans, ans ^ P[i]);
    }
    printf("%lld\n", ans);
    return 0;
}

