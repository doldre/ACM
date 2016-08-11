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
const int maxn = 1e5 + 5;
int c[maxn];
bool is_cap[maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll ans = 0;
    ll tot = 0;
    ll tot2 = 0;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        tot += c[i];
    }
    for (int i = 0; i < k; i++) {
        int x; scanf("%d", &x);
        is_cap[x] = true;
        tot2 += c[x];
    }
    for (int i = 1; i <= n; i++) {
        if(is_cap[i]) {
            ans += (ll)c[i] * (tot - c[i]);
            ll tmp = tot - tot2;
            if(!is_cap[((i - 2) + n) % n + 1]) {
                tmp -= c[((i - 2) + n) % n + 1];
            }
            if(!is_cap[(i % n) + 1]) {
                tmp -= c[(i % n) + 1];
            }
            ans += (ll)c[i] * tmp;
        } else {
            ans += (c[i] * c[((i - 2) + n) % n + 1]);
            ans += (c[i] * c[(i % n) + 1]);
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}

