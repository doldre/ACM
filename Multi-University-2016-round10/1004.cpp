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

const int MAXN = (1 << 22) + 5;
struct BIT {
    int bit[MAXN];
    void init() {
        memset(bit, 0, sizeof(bit));
    }
    void update(int i, int add) {
        for (; i < MAXN; i += lowbit(i)) {
            bit[i] += add;
        }
    }
    int kth(int k) {
        int cur = 0;
        for(int i = 1 << 22; i; i >>= 1) {
            if(cur + i < MAXN && k - bit[cur + i] > 0) {
                k -= bit[cur + i];
                cur += i;
            }
        }
        return cur + 1;
    }
}bit;
int ans[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        bit.init();
        for (int i = 1; i <= n; i++) {
            bit.update(i, 1);
        }
        int tot = n, pos = 1;
        for (int i = 1; i <= n; i++) {
            ans[i] = bit.kth(pos);
            bit.update(ans[i], -1);
            tot--;
            if(tot == 0) break;
            pos = pos + k - 1;
            if(pos > tot) pos = 1;
        }
        for (int i = 0; i < q; i++) {
            int x; scanf("%d", &x);
            printf("%d\n", ans[x]);
        }
    }
    return 0;
}

