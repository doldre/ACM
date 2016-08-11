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

const int maxn = 5e4 + 5;
struct BIT {
    int bit[maxn + 5];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            bit[i] = 0;
        }
    }
    void update(int i, int add) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += add;
        }
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
}bit;
int n;
int A[maxn];
int pre_small[maxn], pre_greater[maxn], back_small[maxn], 
    back_greater[maxn];
int V[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            V[i-1] = A[i];
        }
        sort(V, V + n);
        bit.init(n + 4);
        for (int i = 1; i <= n; i++) {
            int id = lower_bound(V, V + n, A[i]) - V + 2;
            pre_small[i] = bit.sum(id - 1);
            pre_greater[i] = (i - 1) - bit.sum(id);
            // pr(pre_small[i]); prln(pre_greater[i]);
            bit.update(id, 1);
        }
        bit.init(n + 4);
        for (int i = n; i >= 1; i--) {
            int id = lower_bound(V, V + n, A[i]) - V + 2;
            back_small[i] = bit.sum(id - 1);
            back_greater[i] = (n - i) - bit.sum(id);
            // pr(back_small[i]); prln(back_greater[i]);
            bit.update(id, 1);
        }
        ll ans = 0;
        ll sum_1 = 0, sum_2 = 0;
        for (int i = 1; i <= n; i++) {
            sum_1 += pre_small[i];
            sum_2 += pre_greater[i];
        }
        // pr(sum_1); prln(sum_2);
        ans = sum_1 * sum_2;
        for (int i = 1; i <= n; i++) {
            // ans -= (ll)back_greater[i] * back_small[i];
            // ans -= (ll)back_greater[i] * pre_greater[i];
            // ans -= (ll)pre_small[i] * back_greater[i];
            // ans -= (ll)pre_small[i] * pre_greater[i];
            ans -= (ll)pre_small[i] * back_small[i];
            ans -= (ll)back_greater[i] * back_small[i];
            ans -= (ll)pre_small[i] * pre_greater[i];
            ans -= (ll)back_greater[i] * pre_greater[i];
        }
        cout << ans << endl;
    }
    return 0;
}

