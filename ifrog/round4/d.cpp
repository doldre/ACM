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
typedef long long LL;
const ll mod = 1e4 + 7;
int fac[mod + 7];
void init() {
    fac[0] = 1;
    for (int i = 1; i <= mod; ++i) fac[i] = (LL)fac[i - 1] * i % mod;
}
LL power(LL a, LL b) {
    LL x = a % mod, ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        x = x * x % mod;
        b >>= 1;
    }
    return ret;
}
LL C(int n, int m, int mod) {
    return m > n ? 0 : fac[n] * power((LL)fac[m] * fac[n - m], mod - 2) % mod;
}
LL Lucas(LL n, LL m, int mod) {
    return m ? (LL)C(n % mod, m % mod, mod) * Lucas(n / mod, m / mod, mod) % mod : 1;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    while(T--) {
        int x, y;
        scanf("%d%d", &x, &y);
        ll t = Lucas(x + y, y, mod) * (x - y + 1) % mod * power(x + 1, mod - 2) % mod;
        cout << t << endl;
    }
    return 0;
}

