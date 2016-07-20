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
vector<int> G[maxn];
int cnt[maxn];
int root;
int low[maxn], dfn[maxn], dfsNum;
int used[maxn];
int n, m;
const int maxm = 1e4 + 5;
int U[maxm], V[maxm]; 
void dfs(int u, int pass) {
    low[u] = dfn[u] = ++dfsNum;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == pass) continue;
        if(dfn[v] == -1) {
            dfs(v, pass);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                cnt[u]++;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void init() {
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 0; i < m; i++) {
        int u = U[i], v = V[i];
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int count_cut(int u) {
    memset(cnt, 0, sizeof(cnt));
    memset(dfn, -1, sizeof(dfn));
    dfsNum = 0;
    int pass;
    if(u != 1) {
        root = 1;
        pass = u;
    } else {
        root = 2;
        pass = u;
    }
    dfs(root, pass);
    cnt[root]--;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if(cnt[i] > 0) {
           res++;
        }
    }
    return res;
}

int dfs2(int u, int pass) {
    used[u] = 1;
    int res = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(used[v] || v == pass) continue;
        res += dfs2(v, pass);
    }
    return res;
}
vector<int> count_part(int pass) {
    memset(used, 0, sizeof(used));
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if(i == pass) {
            continue;
        }
        if(!used[i]) {
            int t = dfs2(i, pass);
            res.push_back(t);
        }
    }
    return res;
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        if(n == 0 && m == 0) return 0;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &U[i], &V[i]);
        }
        // prln("ok");
        int res = 0;
        init();
        for (int i = 1; i <= n; i++) {
            int add = 0;
            vector<int> t = count_part(i);
            sort(t.begin(), t.end());
            if(t.size() > 2) {
                add = n - 1;
            }else if(t.size() == 2) {
                if(t[1] > 1 && t[0] == 1) {
                    add = t[1];
                } else if(t[1] > 1 && t[0] > 1) {
                    add = n - 1;
                }
            } else if(t.size() == 1) {
                add = count_cut(i);
            }
            res += add;
        }
        // pr(i); prln(add);
        printf("Case %d: %d\n", ++Case, res / 2);
    }
    return 0;
}

