/************************************************
 *Author        :mathon
 *Created Time  :六  4/16 10:45:22 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1000 + 5;
vector<int> G[maxn];
vector<int> R[maxn];
int used[maxn];
int n;
int dfs1(int v, int s, int deep) {
    if(used[v]) {
        return deep - used[s];
    }
    used[v] = deep;
    for (int i = 0; i < (int)G[v].size(); i++) {
        int u = G[v][i];
        return dfs1(u, s, deep + 1);
    }
}

int dfs2(int v, int deep) {
    if(used[v]) {
        return deep - 1;
    }
    used[v] = 1;
    if(R[v].size() == 0) {
        return deep;
    }
    int res = 0;
    for (int i = 0; i < (int)R[v].size(); i++) {
        int u = R[v][i];
        res = max(dfs2(u, deep + 1), res);
    }
    return res;
}
int BFF[maxn];
int main(void)
{
#ifdef LOCAL
    freopen("C-small.in", "r", stdin);
   freopen("C-small.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        for (int i = 0; i < maxn; i++) {
            G[i].clear(); R[i].clear();
        }
        int ans = 0;
        memset(used, 0, sizeof(used));
        memset(BFF, 0, sizeof(BFF));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            G[i].push_back(u);
            R[u].push_back(i);
            BFF[i] = u;
        }

        for (int i = 1; i <= n; i++) {
            if(!used[i]) {
                ans = max(ans, dfs1(i, i, 1));
            }
        }
        for (int i = 1; i <= n; i++) {
            int t = BFF[i];
            if(BFF[t] == i) {
//                printf("%d %d\n", i, t);
                memset(used, 0, sizeof(used));
                used[t] = 1;
                int t1 = dfs2(i, 0);
                memset(used, 0, sizeof(used));
                used[i] = 1;
                int t2 = dfs2(t, 0);
                //printf("t1 %d t2 %d\n", t1, t2);
                ans = max(t1 + t2 + 2, ans);
            }
        }
        printf("Case #%d: %d\n", Cas, ans);
    }
    return 0;
}
