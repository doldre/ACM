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

const int MAXN = 1e5 + 5;
int A[MAXN];
int N;
ll k;
ll V[MAXN], cnt_v;
int deg[MAXN];
vector<int> G[MAXN];

struct BIT {
    int bit[MAXN], n;
    void init(int n) {
        this->n = n;
        memset(bit, 0, sizeof(bit));
    }
    void add(int i, int x) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += x;
        }
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;

ll ans = 0;
void dfs(int u) {
    ll tmp = k / A[u];
    int id = upper_bound(V, V + cnt_v, tmp) - V;
    ans += bit.sum(id);
    id = lower_bound(V, V + cnt_v, A[u]) - V + 1;
    bit.add(id, 1);
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        dfs(v);
    }
    bit.add(id, -1);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &N, &k);
        cnt_v = 0;
        for (int i = 1; i <= N; i++) {
            G[i].clear();
            scanf("%d", &A[i]);
            V[cnt_v++] = A[i];
        }
        sort(V, V + cnt_v);
        cnt_v = unique(V, V + cnt_v) - V;
        bit.init(N);
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i < N; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            deg[v]++;
        }
        int root = 1;
        while(deg[root]) root++;
        ans = 0;
        dfs(root);
        printf("%lld\n", ans);
    }
    return 0;
}

