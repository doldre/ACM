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
int n;

ll solve(ll a, ll b, ll c) {
    ll l = 0, r = 1e9 + 1;
    while(l < r - 1) {
        ll m = (l + r) / 2;
        if(a * m >= b * c) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        ll ans = 0, t = 1;
        for (int i = n; i >= 2; i--) {
            ans += t;
            t = solve(A[i] - A[i-1], A[i-1] - A[i-2], t);
        }
        ans += t;
        printf("Case #%d: %lld\n", Cas, ans); 
    }
    return 0;
}

