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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 1e9 + 7;
const int maxn = 500000 + 5;
int A[maxn];
int n, k;
ll tot, lb, ub;

bool check1(int x) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if(A[i] - x > 0) res += A[i] - x;
    }
    return res <= k;
}
bool check2(int x) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if(A[i] - x < 0) res += x - A[i];
    }
    return res <= k;
}

int get_max() {
    int l = ub - 1, r = inf;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        if(check1(m)) {
            r = m;
        } else l = m;
    }
    return r;
}
int get_min() {
    int l = 0, r = lb + 1;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        if(check2(m)) {
            l = m;
        } else r = m;
    }
    return l;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sa(n);sa(k);
    for (int i = 1; i <= n; i++) {
        sa(A[i]);
        tot += A[i];
    }
    lb = tot / n; ub = (tot + n - 1) / n;
    int mi = get_min(), ma = get_max();
    printf("%d\n", ma - mi);
    return 0;
}
