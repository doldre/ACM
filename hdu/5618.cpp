/************************************************
 *Author        :mathon
 *Created Time  :三  4/27 08:25:36 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1e5 + 5;
struct Point {
    int x, y, z;
    int cnt, sum;
    int num;
    Point() {
        cnt = 0; sum = 0;
    }
    Point(int x, int y, int z): x(x), y(y), z(z) {
        cnt = 0; sum = 0;
    }

    bool operator < (const Point &b) const {
        if(x != b.x) return x < b.x;
        if(y != b.y) return y < b.y;
        return z < b.z;
    }

    bool operator == (const Point &b) const {
        return x == b.x && y == b.y && z == b.z;
    }
}p[maxn];

bool cmpy (const Point &a, const Point &b) {
    return a.y < b.y;
}

class Bit {
    public:
    int bit[maxn + 5];
    int n;
    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; i++) {
            bit[i] = 0;
        }
    }

    void add(int i, int x) {
        for (; i <= n; i += lowbit(i)) {
            bit[i] += x;
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

void cdq(int l, int r) {
    if(l == r) return;
    int m = (l + r) >> 1;
    cdq(l, m);
    cdq(m + 1, r);
    sort(p + l, p + m + 1, cmpy);
    sort(p + m + 1, p + r + 1, cmpy);
    int j = l;
    for (int i = m + 1; i <= r; i++) {
        for (; j <= m && p[j].y <= p[i].y; j++) {
            bit.add(p[j].z, 1);
        }
        p[i].sum += bit.sum(p[i].z);
        /* pr(p[i].num); */
        /* prln(p[i].sum); */
    }
    for (int i = l; i < j; i++) {
        bit.add(p[i].z, -1);
    }
}

int ans[maxn];

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        int n;
        sa(n);
        bit.init(maxn);
        rep(i, 0, n) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
            p[i].num = i;
            p[i].sum = 0;
        }
        sort(p, p + n);
        cdq(0, n - 1);
        sort(p, p + n);
        rep(i, 0, n) {
            int maxv = 0;
            int j;
            for (j = i; j < n && p[i] == p[j]; j++) maxv = max(maxv, p[j].sum);
            for (j = i; j < n && p[i] == p[j]; j++) ans[p[j].num] = maxv;
            i = j - 1;
        }
        rep(i, 0, n) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
