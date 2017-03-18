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

const int MAXN = 2e5 + 8;
int par[MAXN];
int n;

vector<int> G[MAXN];
int L[MAXN], R[MAXN];
int dfsNum;

void dfs(int u, int fa) {
    // prln(u);
    L[u] = ++dfsNum;
    for (auto v: G[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
    R[u] = dfsNum;
}

int A[30];
int used[30];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &par[i]);
        if(par[i] != 0) {
            G[par[i]].push_back(i);
            G[i].push_back(par[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if(par[i] == 0) {
            dfs(i, -1);
        }
    }

    int q; scanf("%d", &q);
    while(q--) {
        int m; scanf("%d", &m);
        int ans = 0;
        memset(used, 0, sizeof(used));
        vector<pii> V;
        for (int i = 0; i < m; i++) {
            scanf("%d", &A[i]);
            V.push_back(pii(L[A[i]], 1));
            V.push_back(pii(R[A[i]] + 1, -1));
        }
        sort(V.begin(), V.end());
        int cur = 0;
        int last = 0;
        for (auto x: V) {
            if(cur > 0) {
                ans += x.xx - last;
            }
            cur += x.yy;
            last = x.xx;
        }
        cout << ans << endl;
    }
    return 0;
}

