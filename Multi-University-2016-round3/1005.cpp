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
const ll INF = 1e15;
const int maxk = 2e5 + 5;
const int MAXN = 5e4 + 5;
vector<int> G[MAXN];
int L[MAXN], R[MAXN], dfsNum;
int root[MAXN];
int dep[MAXN];
int N, Q;

void dfs(int u, int fa, int deep) {
    L[u] = ++dfsNum;
    dep[dfsNum] = deep;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u, deep + 1);
    }
    R[u] = dfsNum;
}

struct HJT_Tree {
    struct Node {
        int ls, rs, Max, Min;
        ll sum, lazy;
    }T[MAXN * 50];
    int tot;
    void init() {
        tot = 0;
    }
    
    void up(int u, int len) {
        T[u].sum = T[T[u].ls].sum + T[T[u].rs].sum + T[u].lazy * len;
        T[u].Min = min(T[T[u].ls].Min, T[T[u].rs].Min) + T[u].lazy;
        T[u].Max = max(T[T[u].ls].Max, T[T[u].rs].Max) + T[u].lazy;
    }
    
    void build(int &u, int l, int r) {
        u = ++tot;
        T[u].lazy = 0;
        int m = (l + r) >> 1;
        if(l == r) {
            T[u].Max = T[u].Min = T[u].sum = dep[l];
            return;
        }
        build(T[u].ls, l, m);
        build(T[u].rs, m + 1, r);
        up(u, r - l + 1);
    }
   
    void Modify(int &u, int l, int r, int x, int y, int z) {
        T[++tot] = T[u];
        u = tot;
        int m = (l + r) >> 1;
        if(x <= l && r <= y) {
            T[u].Max += z;
            T[u].Min += z;
            T[u].sum += (ll)z * (r - l + 1);
            T[u].lazy += z;
            return;
        }
        if(x <= m) Modify(T[u].ls, l, m, x, y, z);
        if(m  < y) Modify(T[u].rs, m + 1, r, x, y, z);
        up(u, r - l + 1);
    }
    
    ll query1(int u, int l, int r, int x, int y) {
        if(x == l && r == y) {
            return T[u].sum;
        }
        int m = (l + r) >> 1;
        ll ans = (ll)(y - x + 1) * T[u].lazy;
        if(y <= m) ans += query1(T[u].ls, l, m, x, y);
        else if(x > m) ans += query1(T[u].rs, m + 1, r, x, y);
        else {
            ans += query1(T[u].ls, l, m, x, m);
            ans += query1(T[u].rs, m + 1, r, m + 1, y);
        }
        // pr(l); prln(r);
        // pr(u);
        // prln(ans);
        return ans;
    }
    
    ll query2(int u, int l, int r, int x, int y) {
        ll ans = INF;
        if(x <= l && r <= y) {
            return T[u].Min;
        }
        int m = (l + r) >> 1;
        if(x <= m) ans = min(ans, query2(T[u].ls, l, m, x, y) + T[u].lazy);
        if(m < y) ans = min(ans, query2(T[u].rs, m + 1, r, x, y) + T[u].lazy);
        return ans;
    }

    ll query3(int u, int l, int r, int x, int y) {
        ll ans = 0;
        if(x <= l && r <= y) {
            return T[u].Max;
        }
        int m = (l + r) >> 1;
        if(x <= m) ans = max(ans, query3(T[u].ls, l, m, x, y) + T[u].lazy);
        if(m < y) ans = max(ans, query3(T[u].rs, m + 1, r, x, y) + T[u].lazy);
        return ans;
    }

}tree;

void dfs2(int u, int fa) {
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        root[v] = root[u];
        tree.Modify(root[v], 1, N, 1, N, 1);
        tree.Modify(root[v], 1, N, L[v], R[v], -2);
        dfs2(v, u);
    }
}

pii inter[maxk*2];
int cnt_inter;
int main(void) {
#ifdef MATHON
    freopen("1005.in", "r", stdin);
    freopen("1005.txt", "w", stdout);
#endif
    int Cas = 0;
    while(scanf("%d%d", &N, &Q) == 2) {
        for (int i = 0; i <= N; i++) {
            G[i].clear();
        }
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v); G[v].push_back(u);
        }
        memset(root, 0, sizeof(root));
        dfsNum = 0;
        dfs(1, -1, 0);
        tree.init();
        tree.build(root[1], 1, N);
        dfs2(1, -1);
        int last_ans = 0;
        while(Q--) {
            int K, P, T;
            ++Cas;
            bool debug = false;
            // if(Cas == 11) debug = true;
            scanf("%d%d%d", &K, &P, &T);
            if(debug) {
                printf("K = %d P = %d T = %d\n", K, P, T);
            }
            P = (P + last_ans) % N + 1;
            if(debug) {
                printf("K = %d P = %d T = %d\n", K, P, T);
            }
            cnt_inter = 0;
            for (int i = 1; i <= K; i++) {
                int x; scanf("%d", &x);
                // inter.push_back(pii(L[x], 1));
                // inter.push_back(pii(R[x] + 1, -1));
                inter[cnt_inter++] = pii(L[x], 1);
                inter[cnt_inter++] = pii(R[x] + 1, -1);
                // pr(L[x]); prln(R[x]);
            }
            // inter.push_back(pii(N + 1, 1));
            inter[cnt_inter++] = pii(N + 1, 1);
            sort(inter, inter + cnt_inter);
            int last = 1, flag = 0, ok = 1;
            ll ans;
            if(T == 1) {
                ans = 0;
            } else if(T == 3) {
                ans = -1;
            } else ans = INF;

            bool suc = false; 
            for (int i = 0; i < cnt_inter; i++) {
                flag += inter[i].yy;
                if(flag == 0) {
                    last = inter[i].xx;
                    ok = 1;
                }
                if(flag == 1 && ok) {
                    ok = 0;
                    int l = last, r = inter[i].xx - 1;
                    if(l > r) continue;
                    if(debug) {
                        pr(l); prln(r);
                    }
                    suc = true;
                    if(T == 1) {
                        // pr(l); prln(r);
                        ll tmp = tree.query1(root[P], 1, N, l, r);
                        // prln(tmp);
                        ans += tmp;
                    } else if(T == 2) {
                        ans = min(ans, tree.query2(root[P], 1, N, l, r));
                    } else if(T == 3) {
                        ll tmp = tree.query3(root[P], 1, N, l, r);
                        // prln(tmp);
                        ans = max(ans, tmp);
                    }
                }
            }
            if(T == 1 && suc == false) ans = -1;
            if(T == 2 && ans == INF) ans = -1;
            if(ans == -1) last_ans = 0;
            else last_ans = ans;
            printf("%lld\n", ans);
        }
    }
    return 0;
}

