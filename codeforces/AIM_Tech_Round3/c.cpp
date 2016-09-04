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
const int MAXN = 4e5 + 5;
int max_sub[MAXN], idx[MAXN];
int sz[MAXN];
int n;
bool can[MAXN];
vector<int> G[MAXN];
void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto &v: G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] <= n / 2) {
            // max_sub[u] = max(max_sub[u], sz[v]);
            // idx[u] = v;
            if(sz[v] > max_sub[u]) {
                max_sub[u] = sz[v];
                idx[u] = v;
            }
        } else {
            if(max_sub[v] > max_sub[u]) {
                max_sub[u] = max_sub[v];
                idx[u] = v;
            }
        }
    }
    // pr(u); pr(sz[u]); pr(max_sub[u]); prln(idx[u]);
}

void dfs2(int u, int fa, int fa_max_sub) {
    // pr(u); pr(fa); prln(fa_max_sub);
    int max_com = n - sz[u], max_s = fa_max_sub;
    for (auto &v: G[u]) {
       if(v == fa) continue;
       if(sz[v] > max_com) {
           max_com = sz[v];
           max_s = max_sub[v];
       }
    }
    // pr(u); pr(max_com); prln(max_s);
    // puts("");
    if(max_com - max_s <= n / 2) can[u] = true;
    for (auto &v: G[u]) {
        if(v == fa) continue;
        if(v == idx[u]) {
            int tmp = 0;
            if(n - sz[u] <= n / 2) tmp = n - sz[u];
            else tmp = fa_max_sub;
            for (auto &vv: G[u]) {
                if(vv == v || vv == fa) continue;
                if(sz[vv] <= n / 2) {
                    tmp = max(sz[vv], tmp);
                } else {
                    tmp = max(tmp, max_sub[vv]);
                }
            }
            // prln(tmp);
            dfs2(v, u, tmp);
        } else {
            int tmp = 0;
            if(n - sz[u] <= n / 2) tmp = n - sz[u];
            else tmp = fa_max_sub;
            tmp = max(tmp, max_sub[u]);
            dfs2(v, u, tmp);
        }
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1);
    dfs2(1, -1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d ", can[i]);
    }
    puts("");
    return 0;
}

