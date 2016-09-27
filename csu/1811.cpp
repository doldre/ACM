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

const int MAXN = 1e5 + 5;
int tot_c[MAXN];
vector<pii> G[MAXN]; //xx: to, yy:id
int C[MAXN];
int ans[MAXN];
int n;
struct Node {
    Node *ch[2];
    int v, cnt_c, size;
    Node () {
        memset(ch, 0, sizeof(ch));
        v = cnt_c = size = 0;
    }
};
Node *root[MAXN];

void push_up(Node *rt) {
    int l = rt->ch[0] == NULL ? 0 : rt->ch[0]->v;
    int r = rt->ch[1] == NULL ? 0 : rt->ch[1]->v;
    rt->v = l + r;
    l = rt->ch[0] == NULL ? 0 : rt->ch[0]->size;
    r = rt->ch[1] == NULL ? 0 : rt->ch[1]->size;
    rt->size = l + r;
}

void insert(int p, int l, int r, Node *&rt) {
    if(rt == NULL) {
        rt = new Node();
    }
    if(l == r) {
        rt->cnt_c++;
        rt->v = rt->cnt_c != tot_c[l];
        rt->size = 1;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) insert(p, l, m, rt->ch[0]);
    else insert(p, m + 1, r, rt->ch[1]);
    push_up(rt);
}

void merge(Node *&dest, Node *src, int l, int r) {
    if(src == NULL) return;
    if(dest == NULL) {
        dest = new Node();
    }
    if(l == r) {
        dest->cnt_c += src->cnt_c;
        dest->v = dest->cnt_c != tot_c[l];
        dest->size = 1;
        return;
    }
    int m = (l + r) >> 1;
    merge(dest->ch[0], src->ch[0], l, m);
    merge(dest->ch[1], src->ch[1], m+1, r);
    push_up(dest);
}

void destroy(Node *rt) {
    if(rt == NULL) return;
    destroy(rt->ch[0]);
    destroy(rt->ch[1]);
    delete rt;
}

void tree_merge(Node *&rt1, Node *&rt2) {
    if(rt1->size > rt2->size) {
        merge(rt1, rt2, 1, n);
        destroy(rt2);
        rt2 = NULL;
    } else {
        merge(rt2, rt1, 1, n);
        destroy(rt1);
        rt1 = NULL;
        swap(rt1, rt2);
    }
}

void dfs(int u, int fa, int id) {
    insert(C[u], 1, n, root[u]);
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i].xx;
        if(v == fa) continue;
        dfs(v, u, G[u][i].yy);
        tree_merge(root[u], root[v]);
    }
    ans[id] = root[u]->v;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            tot_c[i] = 0;
            destroy(root[i]);
            root[i] = NULL;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &C[i]);
            tot_c[C[i]]++;
        }
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(pii(v, i));
            G[v].push_back(pii(u, i));
        }
        dfs(1, -1, 0);
        for (int i = 1; i <= n - 1; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

