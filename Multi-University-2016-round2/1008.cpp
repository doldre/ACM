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
//const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
const int maxm = 5e5 + 5;
struct Bit {
    int bit[maxn * maxn * 2 + 100];
    int n;
    void init(int n) {
        this->n = n;
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

struct Seg {
    int l1, r1, l2, r2;
    Seg() {}
    Seg(int l1, int r1, int l2, int r2):l1(l1), r1(r1), l2(l2), r2(r2){}
}segs[maxn*maxn*2], buf[maxn*maxn*2];

int cnt_buf;
int V[maxn * maxn * 2 + 100], cnt_v;
int A[maxn];
int ans[maxm];
int n, m;
int cnt_segs;
pair<pii, int> query[maxm];

int id(int x) {
    return lower_bound(V, V + cnt_v, x) - V + 1;
}

bool seg_cmp(const Seg &a, const Seg &b) {
    return a.l1 < b.l1;
}

void add_seg(int l1, int r1, int l2, int r2) {
    segs[cnt_segs++] = Seg(l1, r1, l2, r2);
}


void pre_work() {
    cnt_v = 0;
    cnt_buf = 0;
    cnt_segs = 0;
    for (int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            add_seg(1, A[i], 0, 0);
        } else {
            add_seg(0, 0, 1, A[i]);
        }
        int cnt[2] = {0, 0};
        int l[2], r[2];
        for (int j = i + 1; j < n; j++) {
            l[0] = r[0] = cnt[0];
            l[1] = r[1] = cnt[1];
            l[j % 2] += 1;
            r[j % 2] += A[j];
            l[i % 2] += 1;
            r[i % 2] += A[i];
            add_seg(l[0], r[0], l[1], r[1]);
            cnt[j % 2] += A[j];
        }
    }

    for (int i = 0; i < cnt_segs; i++) {
        int &l1 = segs[i].l1, &l2 = segs[i].l2;
        int &r1 = segs[i].r1, &r2 = segs[i].r2;
        // printf("%d %d %d %d\n", l1, r1, l2, r2);
        buf[cnt_buf++] = Seg(l1, 1, l2, r2);
        buf[cnt_buf++] = Seg(r1 + 1, -1, l2, r2);
        // V[cnt_v++] = segs[i].l2;
        V[cnt_v++] = segs[i].l2;
        // V[cnt_v++] = segs[i].r2;
        V[cnt_v++] = segs[i].r2 + 1;
    }
    for (int i = 0; i < m; i++) {
        V[cnt_v++] = query[i].xx.yy;
    }
    sort(V, V + cnt_v);
    cnt_v = unique(V, V + cnt_v) - V; 
    // prln("ok");
}

void solve() {
    sort(query, query + m);
    sort(buf, buf + cnt_buf, seg_cmp);
    bit.init(cnt_v + 2);
    for (int i = 0, j = 0; i < m; i++) {
        int a = query[i].xx.xx, b = query[i].xx.yy;
        // prln(a);
        while(j < cnt_buf && buf[j].l1 <= a) {
            bit.add(id(buf[j].l2), buf[j].r1);
            bit.add(id(buf[j].r2) + 1, -buf[j].r1);
            // printf("%d %d %d %d\n", buf[j].l1, buf[j].r1, buf[j].l2,
            //buf[j].r2);
            j++;
        }
        if(bit.sum(id(b)) > 0) {
            ans[query[i].yy] = 1;
        } else {
            ans[query[i].yy] = 0;
        }
        // prln(ans[query[i].yy]);
    }
}

int main() {
#ifdef MATHON
    freopen("1008.in", "r", stdin);
    freopen("1008.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        // pr(n); prln(m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &query[i].xx.xx, &query[i].xx.yy);
            query[i].yy = i;
        }
        pre_work();
        solve();
        for (int i = 0; i < m; i++) {
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}

