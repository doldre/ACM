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

const ll mod = 1e9 + 7;
ll fast_pow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = res * x % mod;
        }
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

const int MAXN = 2e5 + 5;
int A[MAXN];
int flag[MAXN];
vector<int> v;
int n;
int used[MAXN];
int is_circle[MAXN];
int tim;
void dfs2(int u, int k) {
    if(is_circle[u]) {
        v.push_back(k);
        return;
    }
    is_circle[u] = true;
    dfs2(A[u], k + 1);
}

void dfs(int u) {
    if(used[u]) {
        if(used[u] == tim) {
            dfs2(u, 0);
        }
        return;
    }
    used[u] = tim;
    dfs(A[u]);
}

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
        if(!used[i]) {
            tim++;
            dfs(i);
        }
    }
    ll ans = 1;
    for (auto x: v) {
        // prln(x);
        // prln(fast_pow(2, x));
        ans = ans * (fast_pow(2, x) - 2) % mod;
    }
    for (int i = 1; i <= n; i++) {
        if(!is_circle[i]) ans = 2 * ans % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

