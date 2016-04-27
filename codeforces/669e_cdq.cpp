/************************************************
 *Author        :mathon
 *Created Time  :2016年04月27日 星期三 12时53分44秒
 ***********************************************/
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
#define yy second
#define lowbit(x) (x&-x)
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;

struct Bit {
    int bit[maxn + 5], cnt[maxn];
    int tim;
    int n;
    void init(int n) {
        this->n = n;
        tim = 0;
        memset(cnt, 0, sizeof(cnt));
    }

    void newOne() {
        ++tim;
    }

    void add(int i, int x) {
        if(cnt[i] != tim) {
            cnt[i] = tim;
            bit[i] = 0;
        }
        bit[i] += x;
    }

    int sum(int i) {
        if(cnt[i] == tim) {
            return bit[i];
        }
        return 0;
    }
}bit;

int  ans[maxn];
struct Query {
    int a, t, x, id;
    bool operator < (const Query& b) const {
        return t < b.t;
    }
}q[maxn], buf[maxn];

void cdq(int l, int r) {
    if(l == r) return ;
    for (int i = l; i <= r; i++) buf[i] = q[i];
    int m = (l + r) >> 1;
    cdq(l, m);
    sort(buf + l, buf + m + 1);
    sort(buf + m + 1, buf + r + 1);
    bit.newOne();
    for (int i = m + 1, j = l; i <= r; i++) {
        for (; j <= m && buf[j].t <= buf[i].t; j++) {
            if(buf[j].a == 1) {
                bit.add(buf[j].x, 1);
            } else if(buf[j].a == 2) {
                bit.add(buf[j].x, -1);
            }
        }
        ans[buf[i].id] += bit.sum(buf[i].x);
        /* pr(bit.sum(buf[i].x)); */
        /* pr(buf[i].x); */
        /* pr(buf[i].id); */
        /* prln(ans[buf[i].id]); */
    }
    cdq(m + 1, r);
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    sa(n);
    bit.init(n);
    vector<int> xt, xx;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &q[i].a, &q[i].t, &q[i].x);
        q[i].id = i;
        xx.push_back(q[i].x);
        xt.push_back(q[i].t);
    }
    sort(xx.begin(), xx.end());
    sort(xt.begin(), xt.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    xt.resize(unique(xt.begin(), xt.end()) - xt.begin());
    for (int i = 1; i <= n; i++) {
        q[i].t = lower_bound(xt.begin(), xt.end(), q[i].t) - xt.begin() + 1;
        q[i].x = lower_bound(xx.begin(), xx.end(), q[i].x) - xx.begin() + 1;
    }
    cdq(1, n);
    for (int i = 1; i <= n; i++) {
        if(q[i].a == 3) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
