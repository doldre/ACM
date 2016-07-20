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
typedef pair<ll, ll> pll;
const int maxn = 1e5 + 7;
ll A[maxn];
pll B[maxn];
int n;
ll L, R;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%lld%lld", &L, &R);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &A[i]);
        }
        sort(A, A + n);
        for (int i = 1; i < n; i++) {
            B[i-1] = pll(A[i] - A[i-1] + 1, A[i] + A[i-1] - 1);
        }
        sort(B, B + n - 1);
        ll t = 0;
        ll last = -1;
        for (int i = 0; i < n - 1; i++) {
            ll s = max(B[i].xx, L);
            ll e = min(B[i].yy, R);
            t += max(0ll, e - s + 1);
            ll r = min(last, e);
            t -= max(0ll, r - s + 1);
            last = max(e, last);
            // pr(s), prln(e);
        }
        cout << R - L + 1 - t << endl;
    }
    return 0;
}

