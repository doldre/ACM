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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fac {
    ll x, y;
    Fac() {
        x = 0; y = 1;
    }
    Fac(ll x, ll y): x(x), y(y) {}
    bool operator == (const Fac &b) const {
        return x == b.x && y == b.y;
    }
    bool operator != (const Fac &b) const {
        return !(*this == b);
    }
    Fac operator - (const Fac &b) const {
        ll p = x * b.y - y * b.x, q = y * b.y;
        ll g = gcd(p, q);
        return Fac(p / g, q / g);
    }
    Fac operator + (const Fac &b) const {
        ll p = x * b.y + y * b.x, q = y * b.y;
        ll g = gcd(p, q);
        return Fac(p / g, q / g);
    }
    Fac operator * (const Fac &b) const {
        ll p = x * b.x, q = y * b.y;
        ll g = gcd(p, q);
        return Fac(p / g, q / g);
    }
};

const int MAXN = 20 + 5;
vector<vector<Fac> > dp;
int B[MAXN];
int P;
int N, M;

Fac dfs(int mask, int dam, int card, int rest) {
   if(dam >= P) return Fac(1, 1);
    if(dp[mask][rest] != Fac(-1, 1)) {
        return dp[mask][rest];
    }
    if(card == 0) {
        return dp[mask][rest] = Fac(0, 1);
    }
    dp[mask][rest] = Fac(0, 1);
    int n = __builtin_popcount(mask);
    for (int i = 0; i < M; i++) {
        if((mask >> i) & 1) {
            dp[mask][rest] = dp[mask][rest] + 
                (dfs(mask ^ (1<<i), 
                     dam + B[i], card - 1, rest) * Fac(1, n + rest));
        }
    }
    if(rest > 0) dp[mask][rest] = dp[mask][rest] + 
        (dfs(mask, dam, card + 1, rest - 1) * Fac(rest, n + rest));
    return dp[mask][rest];
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d%d", &P, &N, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d", &B[i]);
        }
        dp = vector<vector<Fac> >(1<<M, vector<Fac>(N + 1, Fac(-1, 1)));
        // for (int i = 0; i < (1<<M); i++) {
            // for (int j = 0; j <= N; j++) {
                // dp[i][j] = Fac(-1, 1);
            // }
        // }
        Fac ans = dfs((1<<M) - 1, 0, 1, N);
        printf("%lld/%lld\n", ans.x, ans.y);
    }
    return 0;
}

