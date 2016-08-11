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
const int maxn = 22;
int edge[maxn];
int n, m;
int cnt[1<<maxn];
int U[maxn*maxn], V[maxn*maxn];
int ind[1<<maxn];

inline int lowbit(int x) {
    return x & (-x);
}

bool check(int mask) {
    int done = 0;
    int did = lowbit(mask);
    while(ind[lowbit(did^done)] != -1) {
        int u = ind[lowbit(did^done)];
        // prln(u);
        done |= 1<<u;
        int v = mask & edge[u];
        did |= v;
    }
    // pr(mask); prln(done);
    return done == mask;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    memset(ind, -1, sizeof(ind));
    for (int i = 0; i < maxn; i++) ind[1<<i] = i;
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d", &n, &m);
        memset(edge, 0, sizeof(edge));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u] |= 1 << v;
            edge[v] |= 1 << u;
            U[i] = u; V[i] = v;
        }
        int base = (1<<n) - 1;
        int tot = 0;
        for (int mask = 1; mask < base; mask++) {
            if(mask & 1) {
                if(check(mask) && check(mask ^ base)) {
                    // prln(mask);
                    cnt[mask] = 1; cnt[mask ^ base] = 1;
                    tot++;
                }
            }
        }
        for (int i = 1<<n; i > 0; i >>= 1) {
            for (int j = 0; j <= base; j++) {
                if(i & j) {
                    cnt[j ^ i] += cnt[j];
                }
            }
        }
        printf("Case #%d:", Cas);
        for (int i = 0; i < m; i++) {
            int u = U[i], v = V[i];
            printf(" %d", tot - cnt[(1<<u) | (1<<v)]);
        }
        puts("");
    }
    return 0;
}

