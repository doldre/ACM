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
const int maxn = 3e5 + 7;
int parent[maxn], size[maxn], centroid[maxn];
vector<int> children[maxn];
int n, q;

void dfs(int u) {
    size[u] = 1;
    pii best {0, 0};
    for (auto v: children[u]) {
        dfs(v);
        size[u] += size[v];
        best = max(best, pii(size[v], v));
    }
    auto &ref = centroid[u] = best.xx ? centroid[best.yy] : u;
    while (ref != u && size[u] - size[ref] >= size[ref]) {
        ref = parent[ref];
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", parent + i);
        children[parent[i]].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", centroid[x]);
    }
    return 0;
}
