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

const int MAXN = 10 + 5;
int A[MAXN], B[MAXN];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
        ll a = A[n], b = B[n];
        for (int i = n - 1; i >= 1; i--) {
            ll ta = a, tb = b;
            a = ta * A[i] + tb;
            b = ta * B[i];
        }
        ll g = gcd(a, b);
        printf("Case #%d: %lld %lld\n", Cas, b / g, a / g);
    }
    return 0;
}

