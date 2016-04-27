/************************************************
 *Author        :mathon
 *Created Time  :三  4/27 19:50:42 2016
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

const int mod = 1<<30;
const int maxn = 1e5 + 5;

struct Query {
    int x, y, z, len, cnt;
    Query() {
        len = 1, cnt = 1;
    }
    bool operator < (const Query &b) const {
        if (x != b.x) return x < b.x;
        if (y != b.y) return y < b.y;
        return z < b.z;
    }
}q[maxn];

bool cmpy(const Query &a, const Query &b) {
    return a.y < b.y;
}

void get_max(Query &a, const Query &b) {
    if (a.len < b.len) {
        a.len = b.len;
        a.cnt = b.cnt;
    } else if(a.len == b.len) {
        a.cnt = (a.cnt + b.cnt) % mod;
    }
}

struct Bit {
    Query bit[maxn + 5];
    int n, tim, cnt[maxn + 5];

    void newOne() {
        tim++;
    }
    void init(int n) {
        this->n = n;
        tim = 0;
        memset(cnt, 0, sizeof(cnt));
    }

    void add(int i, Query x) {
        for (; i <= n; i += lowbit(i)) {
            if(cnt[i] != tim) {
                cnt[i] = tim;
                bit[i].len = 0;
                bit[i].cnt = 0;
            }
            get_max(bit[i], x);
        }
    }

    Query querry(int i) {
        Query res;
        res.len = 0, res.cnt = 0;
        for (; i > 0; i -= lowbit(i)) {
            if(cnt[i] == tim) get_max(res, bit[i]);
        }
        return res;
    }
}bit;


void cdq(int l, int r) {
    if (l == r) return;
    int m = (l + r) >> 1;
    cdq(l, m);
    sort(q + l, q + m + 1, cmpy);
    sort(q + m + 1, q + r + 1, cmpy);
    bit.newOne();
    for (int i = m + 1, j = l; i <= r; i++) {
        for (; j <= m && q[j].y <= q[i].y; j++) {
            bit.add(q[j].z, q[j]);
            /* pr(i); */
            /* prln(j); */
            /* pr(q[i].x); */
            /* pr(q[i].y); */
            /* prln(q[i].z); */
            /* pr(q[j].x); */
            /* pr(q[j].y); */
            /* prln(q[j].z); */
        }
        /* pr(i); */
        /* prln(q[i].z); */
        Query t = bit.querry(q[i].z);
        t.len++;
        /* pr(t.len); */
        /* prln(t.cnt); */
        get_max(q[i], t);
        /* pr(q[i].len); */
        /* prln(q[i].cnt); */
    }
    sort(q + m + 1, q + r + 1);
    cdq(m + 1, r);
}


int main(void)
{
ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        int n;
        sa(n);
        bit.init(n);
        vector<int>  xz(n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
            q[i].len = 1, q[i].cnt = 1;
            xz[i - 1] = q[i].z;
        }
        sort(xz.begin(), xz.end());
        xz.resize(unique(xz.begin(), xz.end()) - xz.begin());
        for (int i = 1; i <= n; i++) {
            q[i].z = lower_bound(xz.begin(), xz.end(), q[i].z) - xz.begin() + 1;
        }
        sort(q + 1, q + n + 1);
        cdq(1, n);
        Query ans;
        for (int i = 1; i <= n; i++) {
            get_max(ans, q[i]);
        }
        printf("%d %d\n", ans.len, ans.cnt);
    }
    return 0;
}
