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
const int maxn = 1000 + 5;

struct DSU {
    int par[4*maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    bool merge(int a, int b) {
        if(find(a << 1) == find(b << 1)) {
            return false;
        }
        par[find(a << 1)] = find(b << 1 | 1);
        par[find(b << 1)] = find(a << 1 | 1);
        return true;
    }
}dsu;

struct Edge {
    int u, v, w, num;
    Edge() {}
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
}es[maxn*maxn];

bool cmp(const Edge &a, const Edge &b) {
    return a.w > b.w;
}

int n, m, q;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
        es[i].u--; es[i].v--;
        es[i].num = i + 1;
    }
    sort(es, es + m, cmp);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int res = -1;
        dsu.init(2*n);
        for (int j = 0; j < m && res == -1; j++) {
            if(es[j].num >=l && es[j].num <= r) {
                if(!dsu.merge(es[j].u, es[j].v)) {
                    res = es[j].w;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

