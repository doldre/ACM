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
int n;
int A[MAXN], P[MAXN];
struct DSU {
    int par[MAXN];
    ll sz[MAXN];
    void init(int n) {
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            sz[i] = A[i];
        }
    }
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        par[a] = b;
        sz[b] += sz[a];
    }
}dsu;

int used[MAXN];
ll ans[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
    }
    dsu.init(n);
    ll cur = 0;
    for (int i = n; i >= 1; i--) {
        int t = P[i];
        used[t] = 1;
        if(used[t-1]) {
            dsu.merge(t, t - 1);
        }
        if(used[t+1]) {
            dsu.merge(t, t + 1);
        }
        int a = dsu.find(t);
        cur = max(cur, dsu.sz[a]);
        ans[i] = cur;
    }
    for (int i = 2; i <= n + 1; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}

