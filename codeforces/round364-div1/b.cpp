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
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
bool is_uni[maxn];
vector<int> G[maxn];
int sub[maxn];
int n, k;
ll ans = 0;
void dfs(int u, int fa) {
    sub[u] = is_uni[u];
    for (int v: G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
    ll tmp = min(2 * k - sub[u], sub[u]);
    ans += tmp;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0;  i < 2 * k; i++) {
        int u; scanf("%d", &u);
        is_uni[u] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}

