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
ll pown[11][11];
ll fast_pow(ll x, int n) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) {
            res = res * x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}

ll A[10][MAXN], B[10][MAXN];
int cnt_A, cnt_B;
void solve(ll a[], ll base, ll maxn, int k, int cnt) {
    for (int i = 0; i < maxn; i++) {
        int x = i; 
        ll tmp = 0;
        for (int j = 0; j < cnt; j++) {
            int t = x % 10;
            x /= 10;
            tmp += pown[t][k] - t * pown[10][j] * base;
        }
        a[i] = tmp;
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    for (int i = 0; i <= 10; i++) {
        pown[i][0] = 1;
        for (int j = 1; j <= 10; j++) {
            pown[i][j] = pown[i][j-1] * i;
        }
    }
    for (int k = 1; k <= 9; k++) {
        solve(A[k], 1, 100000, k, 5);
        solve(B[k], 100000, 100000, k, 5);
        sort(A[k], A[k] + 100000);
        sort(B[k], B[k] + 100000);
    }

    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int x, k;
        scanf("%d%d", &x, &k);
        ll ans = 0;
        for (int i = 0; i < 100000; i++) {
            ll r = x - A[k][i];
            ans += upper_bound(B[k], B[k] + 100000, r) - lower_bound(B[k], B[k] + 100000, r);
        }
        if(x == 0) ans--;
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

