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
vector<pii> G[maxn];
int A[maxn];
int num[maxn];
int n;

void dfs(int u, int fa) {
    num[u] += 1;
    for (pii x: G[u]) {
        int v = x.xx;
        if(v == fa) continue;
        dfs(v, u);
        num[u] += num[v];
    }
}

int ans = 0;

void dfs2(int u, int fa, int maxd) {
    for (pii x: G[u]) {
        int v = x.xx;
        if(v == fa) continue;
        int nmaxd = max(maxd + x.yy, x.yy);
        if(nmaxd > A[v]) {
            ans += num[v];
            continue;
        } else {
            dfs2(v, u, nmaxd);
        }
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 1; i <= n - 1; i++) {
        int p, c;
        scanf("%d%d", &p, &c);
        G[i+1].push_back(pii(p, c));
        G[p].push_back(pii(i + 1, c));
    }
    dfs(1, -1);
    dfs2(1, -1, 0);
    cout << ans << endl;
    return 0;
}
