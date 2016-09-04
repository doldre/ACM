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
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 5;
vector<pii> G[MAXN];
vector<int> B;
int is_b[MAXN];
int n, m, k;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        G[u].push_back(pii(v, l));
        G[v].push_back(pii(u, l));
    }
    for (int i = 0; i < k; i++) {
        int u; scanf("%d", &u);
        is_b[u] = true;
        B.push_back(u);
    }
    int ans = INF;
    for (int i = 0; i < k; i++) {
        int u = B[i];
        for (auto &v: G[u]) {
            if (!is_b[v.xx]) {
                ans = min(ans, v.yy);
            }
        }
    }
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}

