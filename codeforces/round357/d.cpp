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
const int maxn = 1e5 + 7;
int ind[maxn], anc[maxn];
vector<int> G[maxn], ans;
bool suc;
int n, m;
void dfs(int u, int fa) {
    if(anc[u] != anc[fa] && anc[u] != u) {
        suc = false;
    }
    if(!suc) return;
    for (auto v: G[u]) {
        dfs(v, u);
    }
    if(anc[u] == u) {
        ans.push_back(u);
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        ind[v]++;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &anc[i]);
    }
    suc = true;
    for (int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            dfs(i, 0);
        }
    }
    if(!suc) puts("-1");
    else {
        printf("%d\n", (int)ans.size());
        for (auto u: ans) {
            printf("%d\n", u);
        }
    }
    return 0;
}
